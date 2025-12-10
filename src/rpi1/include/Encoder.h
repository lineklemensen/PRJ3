#ifndef ENCODER_H
#define ENCODER_H

#include <string>
#include <thread>
#include <atomic>
#include <unistd.h>
#include <poll.h>
#include <linux/gpio.h>

#define CHIP_PATH "/dev/gpiochip0"
#define POLL_TIMEOUT_MS 1

class Encoder
{
public:
    // Constructor / Destructor
    Encoder(int gpio_enc_a, int gpio_enc_b);
    Encoder();
    ~Encoder();

    // Initialize encoder GPIO lines
    void init_encoder(int gpio_enc_a, int gpio_enc_b);
    // Start / stop background thread
    void start_thread();
    void stop_thread();

    // Get current encoder position
    int get_position() const;

private:
    int chip_fd_;
    struct gpioevent_request event_req_[2];
    struct pollfd poll_fds_[3];
    int wake_pipe_[2];

    int gpio_enc_a_;
    int gpio_enc_b_;
    int poll_timeout_ms_;
    int last_state_;

    std::atomic<int> encoder_position_;
    std::thread monitor_thread_;
    std::atomic<bool> running_;
    std::string chipname_;

    // Quadrature encoder event monitoring
    void monitor_events();

    void cleanup();
};

#endif // ENCODER_H
