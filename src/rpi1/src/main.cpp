#include "MotorController.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <unistd.h>
#include <termios.h>
#include <fcntl.h>
#include <fstream>
#include "astar.h"
#include <httplib.h>
#include "HttpHandler.h"
#include "CalcPath.h"
#include <gpiod.h>
#include <sys/ioctl.h>

#define FORWARD 1
#define BACKWARD 0
#define GREEN_LED_PIN 21
#define ACTIVITY_BUTTON_PIN 16

/*
// Test of Pid class
// Simulated encoder: reacts to PWM like a real motor
double simulate_encoder(double pos, double pwm)
{
    // convert PWM into acceleration
    double accel = pwm * 0.05; // tune this for realism

    // friction reduces velocity
    static double velocity = 0.0;
    velocity += accel;
    velocity *= 0.90; // friction / damping

    pos += velocity;
    return pos;
}

int main()
{
    // Configure PID exactly like MotorController does
    Pid pid;
    pid.set_dt(0.1);
    pid.set_kp(0.6);
    pid.set_ki(0.15);
    pid.set_kd(0.6);
    pid.set_ramp_limit(5.0);
    pid.set_max_output(100);
    pid.set_min_output(-100);

    // Setpoint simulating a motor target position
    double target = 200; // pretend encoder counts
    double pos = 0;      // starting encoder value
    constexpr double INTEGRATION_THRESHOLD = 5.0;

    // Open file in truncate mode to clear it first
    std::ofstream data_file("/home/au772678/PRJ3/src/rpi1/scripts/pid_test.csv", std::ios::out | std::ios::trunc);

    if (!data_file.is_open())
    {
        std::cerr << "Failed to open pid_test.csv for writing!\n";
        return 1;
    }
    data_file << "time,pos,ctrl,pwm\n"; // CSV header

    std::cout << "=== PID TEST START ===\n";

    for (int i = 0; i < 200; i++)
    {
        double ctrl;
        int pwm = pid.update(target, pos, &ctrl, INTEGRATION_THRESHOLD);

        // Update simulated encoder
        pos = simulate_encoder(pos, pwm);

        double t = i * pid.get_dt();

        // Write to CSV
        data_file << t << "," << pos << "," << ctrl << "," << pwm << "\n";
        data_file.flush();

        // Print to console
        std::cout << "t=" << t
                  << "s  pos=" << pos
                  << "  ctrl=" << ctrl
                  << "  pwm=" << pwm
                  << std::endl;

        // Stop early if close enough
        if (std::abs(target - pos) < 1.0)
        {
            std::cout << "Target reached.\n";
            break;
        }
    }

    data_file.close(); // close CSV

    std::cout << "Final position: " << pos << std::endl;
    std::cout << "=== PID TEST END ===\n";

    return 0;
}
*/

/*
// Test of Encoder class and drive
// Utility: set stdin to non-blocking mode
void set_nonblocking(bool enable)
{
    struct termios ttystate;
    tcgetattr(STDIN_FILENO, &ttystate);
    if (enable)
    {
        ttystate.c_lflag &= ~ICANON; // disable canonical mode
        ttystate.c_lflag &= ~ECHO;   // disable echo
        fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);
    }
    else
    {
        ttystate.c_lflag |= ICANON; // restore canonical mode
        ttystate.c_lflag |= ECHO;   // restore echo
        fcntl(STDIN_FILENO, F_SETFL, 0);
    }
}

int main()
{
    // Initialize MotorController
    MotorController motors;

    usleep(100000); // wait for initialization

    // Example: set left motor forward and right motor forward
    // motors.set_direction(FORWARD, FORWARD);
    // motors.drive(20, -40); // 30% speed

    motors.drive_distance(TARGET_DISTANCE);
    // motors.drive(30, 0);
    // motors.turn(900);

    // Set stdin non-blocking for key press detection
    set_nonblocking(true);

    std::cout << "Monitoring encoder positions. Press any key to exit..." << std::endl;

    while (true)
    {
        // Print encoder positions
        motors.print_encoder_pos();

        std::this_thread::sleep_for(std::chrono::milliseconds(500));

        // Check for key press
        char c;
        if (read(STDIN_FILENO, &c, 1) > 0)
        {
            break; // exit on key press
        }
    }

    set_nonblocking(false);
    std::cout << "\nExiting program." << std::endl;

    return 0;
}
 */

int wake_pipe = {};
pollfd poll_fds[2];
std::atomic<bool> act_btn_pressed = false;

void init_button(const int pin)
{
    int chip_fd = open(CHIP_PATH, O_RDONLY);
    if(chip_fd < 0)
        throw std::runtime_error("Failed to open GPIO chip");

    gpioevent_request req = {};
    req.lineoffset = pin;
    req.handleflags = GPIOHANDLE_REQUEST_INPUT;
    req.eventflags = GPIOEVENT_REQUEST_RISING_EDGE;
    strcpy(req.consumer_label, "action_button_event");

    if(ioctl(chip_fd, GPIO_GET_LINEEVENT_IOCTL, &req) < 0) {
        close(chip_fd);
        throw std::runtime_error("Failed to request GPIO line event for act btn");
    }

    poll_fds[0] = {
        .fd = req.fd,
        .events = POLLIN,
        .revents = 0,
    };

    if(pipe(&wake_pipe) < 0)
        throw std::runtime_error("Failed to create wake pipe");

    poll_fds[1] = {
        .fd = wake_pipe,
        .events = POLLIN,
        .revents = 0,
    };

    std::cout << "Encoder initialized successfully." << std::endl;
}

void monitor_act_btn()
{
    gpioevent_data event_data;

    while(true) {
        int ret = poll(&poll_fds[0], 2, -1);
        if(ret < 0)
            break;

        if(poll_fds[1].revents & POLLIN) // wake pipe
        {
            char buf[8];
            read(wake_pipe, buf, sizeof(buf));
            break;
        }

        if(poll_fds[0].revents & POLLIN) {
            ssize_t bytes = read(poll_fds[0].fd, &event_data, sizeof(event_data));
            if(bytes != sizeof(event_data))
                continue;

            // --- DEBOUNCE START ---
            static uint64_t last_ts = 0;
            constexpr uint64_t debounce_ns = 100000; // 1 ms

            if(event_data.timestamp - last_ts < debounce_ns) {
                // Ignorer bounce
                continue;
            }

            last_ts = event_data.timestamp;

            act_btn_pressed.store(event_data.id == GPIOEVENT_EVENT_RISING_EDGE);
        }
    }
}

int main()
{
    // Initialize MotorController
    MotorController motors;
    usleep(100000); // wait for initialization
    DR driving_calculator;
    init_button(ACTIVITY_BUTTON_PIN);
    auto activity_button_thr = std::thread(monitor_act_btn);


    while(true) {
        std::cout << "Waiting for button before req route\n";
        while(!act_btn_pressed.load()) { }
        std::cout << "Route req'd\n";

        httplib::Result res;
#pragma region Get route from server

        auto t = std::thread(HttpHandler::get_route, &res);
        t.join();

        //TODO move to gpiod
        if(res->status != httplib::StatusCode::OK_200) {
            gpiod_chip* chip_ = gpiod_chip_open(CHIP_PATH);
            if(!chip_)
                throw std::runtime_error("Error: Failed to setup LED");

            gpiod_line* led = gpiod_chip_get_line(chip_, GREEN_LED_PIN);
            if(!led) {
                gpiod_chip_close(chip_);
                throw std::runtime_error("Error: Failed to get led GPIO line");
            }

            if(gpiod_line_request_output(led, "LedCtrl", 0) < 0) {
                gpiod_chip_close(chip_);
                throw std::runtime_error("Error: Failed to set led GPIO line as output");
            }
            int seconds = 0;
            while(seconds != 5) {
                gpiod_line_set_value(led, 1);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));

                gpiod_line_set_value(led, 0);
                std::this_thread::sleep_for(std::chrono::milliseconds(500));
                seconds++;
            }

            std::cerr << "No route received\n";
            break;
        }

#pragma endregion

        const auto r = json_dto::from_json<Route>(res->body);

        std::vector<std::vector<Point>> paths = Astar::calculate_path(r);
        std::cout << "Ready to start route\n";
        for(const auto& path : paths) {
            while(!act_btn_pressed.load()) { }
            for(const auto& point : path) {
                //Drive to point
                //auto instr = driving_calculator.calc_route({point.x, point.y});
                //motors.turn(instr.first);
                //motors.drive_distance(instr.second);
                std::cout << '(' << point.x << ',' << point.y << ')';
            }
            std::cout << '\n';
            //Wait for button press

            act_btn_pressed.store(false);
        }

        std::cout << "Route finished!\n";
    }

    std::cout << "Shutting down\n";
    char c = 'x';
    write(wake_pipe, &c, 1);
    activity_button_thr.join();
    return 0;
}
