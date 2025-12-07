#include "Encoder.h"
#include <iostream>
#include <unistd.h>
#include <poll.h>
#include <linux/gpio.h>
#include <cstring>
#include <stdexcept>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <atomic>
#include <thread>

// Default constructor does not initialize GPIO lines
Encoder::Encoder()
    : chipname_(CHIP_PATH),
      poll_timeout_ms_(POLL_TIMEOUT_MS),
      encoder_position_(0),
      running_(false)
{
}

void Encoder::init_encoder(int gpio_enc_a, int gpio_enc_b)
{
    gpio_enc_a_ = gpio_enc_a;
    gpio_enc_b_ = gpio_enc_b;

    chip_fd_ = open(chipname_.c_str(), O_RDONLY);
    if (chip_fd_ < 0)
        throw std::runtime_error("Failed to open GPIO chip");

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
            close(chip_fd_);
	    std::cout << gpio_enc_a <<" "<< gpio_enc_b << std::endl;
            throw std::runtime_error("Failed to request GPIO line event");
        }

        poll_fds_[i].fd = event_req_[i].fd;
        poll_fds_[i].events = POLLIN;
        poll_fds_[i].revents = 0;
    }

    if (pipe(wake_pipe_) < 0)
        throw std::runtime_error("Failed to create wake pipe");

    poll_fds_[2].fd = wake_pipe_[0];
    poll_fds_[2].events = POLLIN;
    poll_fds_[2].revents = 0;

    last_state_ = 0;

    std::cout << "Encoder initialized successfully." << std::endl;
}

Encoder::Encoder(int gpio_enc_a, int gpio_enc_b)
    : chipname_(CHIP_PATH),
      poll_timeout_ms_(POLL_TIMEOUT_MS),
      gpio_enc_a_(gpio_enc_a),
      gpio_enc_b_(gpio_enc_b),
      encoder_position_(0),
      running_(false)
{
    init_encoder(gpio_enc_a, gpio_enc_b);
}

void Encoder::start_thread()
{
    if (running_)
        return;
    running_ = true;
    monitor_thread_ = std::thread(&Encoder::monitor_events, this);
}

void Encoder::stop_thread()
{
    if (!running_)
        return;

    running_ = false;
    char c = 'x';
    write(wake_pipe_[1], &c, 1);

    if (monitor_thread_.joinable())
        monitor_thread_.join();

    cleanup();
}

void Encoder::monitor_events()
{
    struct gpioevent_data event_data;

    // Quadrature decoding lookup table
    const int8_t quad_table[16] = {0, -1, 1, 0,
                                   1, 0, 0, -1,
                                   -1, 0, 0, 1,
                                   0, 1, -1, 0};

    while (running_)
    {
        int ret = poll(poll_fds_, 3, -1);
        if (ret < 0)
            break;

        if (poll_fds_[2].revents & POLLIN) // wake pipe
        {
            char buf[8];
            read(wake_pipe_[0], buf, sizeof(buf));
            break;
        }

        for (int i = 0; i < 2; ++i)
        {
            if (poll_fds_[i].revents & POLLIN)
            {
                ssize_t bytes = read(poll_fds_[i].fd, &event_data, sizeof(event_data));
                if (bytes != sizeof(event_data))
                    continue;

                /*
                               // --- DEBOUNCE START ---
                                static uint64_t last_ts[2] = {0, 0};
                                const uint64_t debounce_ns = 100000; // 1 ms

                                int ch = i; // 0 for A, 1 for B

                                if (event_data.timestamp - last_ts[ch] < debounce_ns)
                                {
                                    // Ignorer bounce
                                    continue;
                                }

                                last_ts[ch] = event_data.timestamp;
                                // --- DEBOUNCE SLUT ---
                */
                int a = (i == 0) ? (event_data.id == GPIOEVENT_EVENT_RISING_EDGE) : (last_state_ >> 1) & 1;
                int b = (i == 1) ? (event_data.id == GPIOEVENT_EVENT_RISING_EDGE) : last_state_ & 1;

                int current_state = (a << 1) | b;
                int index = (last_state_ << 2) | current_state;
                encoder_position_ += quad_table[index];
                last_state_ = current_state;
            }
        }
    }
}

int Encoder::get_position() const
{
    return encoder_position_.load();
}

void Encoder::cleanup()
{
    for (int i = 0; i < 2; ++i)
        if (event_req_[i].fd >= 0)
            close(event_req_[i].fd);

    if (chip_fd_ >= 0)
        close(chip_fd_);
    close(wake_pipe_[0]);
    close(wake_pipe_[1]);
}

Encoder::~Encoder()
{
    stop_thread();
    std::cout << "Encoder destroyed.\n";
}
