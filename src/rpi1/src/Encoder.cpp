#include "Encoder.h"
#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <linux/gpio.h>
#include <cstring>
#include <stdexcept>
#include <fcntl.h>
#include <sys/ioctl.h>


Encoder::Encoder(std::string chipname, int poll_timeout_ms, int gpio_enc_a, int gpio_enc_b)
    : chipname_(std::move(chipname)),
      poll_timeout_ms_(poll_timeout_ms),
      gpio_enc_a_(gpio_enc_a),
      gpio_enc_b_(gpio_enc_b)
{
    chip_fd_ = open(chipname_.c_str(), O_RDONLY);
    if (chip_fd_ < 0)
    {
        perror("open");
        throw std::runtime_error("Failed to open GPIO chip: " + chipname_);
    }

    memset(event_req_, 0, sizeof(event_req_));

    event_req_[0].lineoffset = gpio_enc_a_;
    event_req_[1].lineoffset = gpio_enc_b_;

    for (int i = 0; i < 2; ++i)
    {
        event_req_[i].handleflags = GPIOHANDLE_REQUEST_INPUT;
        event_req_[i].eventflags = GPIOEVENT_REQUEST_BOTH_EDGES;
        strcpy(event_req_[i].consumer_label, "encoder_event");

        if (ioctl(chip_fd_, GPIO_GET_LINEEVENT_IOCTL, &event_req_[i]) < 0)
        {
            perror("ioctl");
            close(chip_fd_);
            throw std::runtime_error("Failed to request GPIO line event");
        }

        poll_fds_[i].fd = event_req_[i].fd;
        poll_fds_[i].events = POLLIN;
        poll_fds_[i].revents = 0;
    }

    // Create a pipe to wake poll() during stop
    if (pipe(wake_pipe_) < 0)
    {
        perror("pipe");
        throw std::runtime_error("Failed to create wake pipe");
    }

    poll_fds_[2].fd = wake_pipe_[0];  // read end
    poll_fds_[2].events = POLLIN;
    poll_fds_[2].revents = 0;

    std::cout << "Encoder initialized successfully." << std::endl;
}

void Encoder::start_thread()
{
    if (running_)
    {
        std::cerr << "Encoder thread already running.\n";
        return;
    }

    running_ = true;
    monitor_thread_ = std::thread(&Encoder::monitor_events, this);
    std::cout << "Encoder monitoring thread started.\n";
}

void Encoder::stop_thread()
{
    if (!running_)
        return;

    running_ = false;

    // Write one byte to wake the poll() call
    if (wake_pipe_[1] >= 0)
    {
        const char stop_byte = 'x';
        write(wake_pipe_[1], &stop_byte, 1);
    }

    if (monitor_thread_.joinable())
    {
        monitor_thread_.join();
    }

    cleanup();

    std::cout << "Encoder monitoring thread stopped.\n";
}

void Encoder::monitor_events()
{
    std::cout << "Starting encoder event monitoring loop..." << std::endl;

    struct gpioevent_data event_data;
    int last_state_a = -1;
    int last_state_b = -1;

    while (running_)
    {
        int ret = poll(poll_fds_, 3, -1);  // wait indefinitely until event or wake signal
        if (ret < 0)
        {
            perror("poll");
            break;
        }

        // Check if wake pipe triggered (exit signal)
        if (poll_fds_[2].revents & POLLIN)
        {
            char buf[8];
            read(wake_pipe_[0], buf, sizeof(buf));  // drain pipe
            break;
        }

        for (int i = 0; i < 2; ++i)
        {
            if (poll_fds_[i].revents & POLLIN)
            {
                ssize_t bytes_read = read(poll_fds_[i].fd, &event_data, sizeof(event_data));
                if (bytes_read != sizeof(event_data))
                {
                    perror("read");
                    continue;
                }

                bool rising = (event_data.id == GPIOEVENT_EVENT_RISING_EDGE);

                if (i == 0)
                {
                    last_state_a = rising ? 1 : 0;
                    if (last_state_a == last_state_b)
                        encoder_position_.fetch_add(1);
                    else
                        encoder_position_.fetch_sub(1);
                }
                else
                {
                    last_state_b = rising ? 1 : 0;
                    if (last_state_a != last_state_b)
                        encoder_position_.fetch_add(1);
                    else
                        encoder_position_.fetch_sub(1);
                }
            }
        }
    }

    std::cout << "Exiting encoder monitor loop." << std::endl;
}

void Encoder::cleanup()
{
    for (int i = 0; i < 2; ++i)
    {
        if (event_req_[i].fd >= 0)
            close(event_req_[i].fd);
    }

    if (chip_fd_ >= 0)
        close(chip_fd_);

    if (wake_pipe_[0] >= 0)
        close(wake_pipe_[0]);
    if (wake_pipe_[1] >= 0)
        close(wake_pipe_[1]);
}

Encoder::~Encoder()
{
    stop_thread();
    std::cout << "Encoder destroyed.\n";
}
