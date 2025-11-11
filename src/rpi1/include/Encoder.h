#ifndef ENCODER_H
#define ENCODER_H

#include <string>
#include <atomic>
#include <thread>
#include <poll.h>
#include <linux/gpio.h>

class Encoder {
public:
    Encoder(std::string chipname, int poll_timeout_ms, int gpio_enc_a, int gpio_enc_b);
    ~Encoder();

    void start_thread();
    void stop_thread();
    int get_position() const { return encoder_position_.load(); }

private:
    void monitor_events();
    void cleanup();

    std::string chipname_;
    int poll_timeout_ms_;
    int gpio_enc_a_;
    int gpio_enc_b_;

    int chip_fd_ = -1;
    struct gpioevent_request event_req_[2];
    struct pollfd poll_fds_[3];
    int wake_pipe_[2] = {-1, -1};

    std::atomic<int> encoder_position_{0};
    std::atomic<bool> running_{false};
    std::thread monitor_thread_;
};

#endif // ENCODER_H
