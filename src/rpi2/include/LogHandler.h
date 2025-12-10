#pragma once
#include <expected.hpp>
#include <fstream>
#include <http_headers.hpp>
#include <deque>
//=========================*/
// Example data structure
//=========================*/

class LogHandler {

    private:
    std::ofstream log_file;
    std::deque<std::string> route_queue;
    std::string file_path;

    public:

    LogHandler(const std::string& file_path = "logger.txt") : file_path(file_path) {
        log_file.open(file_path, std::ios::app);
        if (!log_file.is_open()) {
            throw std::runtime_error("failed to opn file");
        }

        if (log_file.is_open()) {
            std::ifstream log_file_stream(file_path);
            std::string line;
            while (std::getline(log_file_stream, line)) {
                route_queue.push_back(line);
            }
        }
    };
    ~LogHandler() {
        if (log_file.is_open()) {
            log_file.close();
        }
    }

    void post_route(const std::string& log_rooms) {
        route_queue.push_back(log_rooms);
        if (log_file.is_open()) {
            log_file << route_queue.back() << "\n";
            log_file.flush();
        }
    };

    std::string get_route() {

        if (route_queue.empty()) {
            throw std::runtime_error("no route queue given");
        }

        std::string first_route = route_queue.front();
        route_queue.pop_front();
        update_route();
        return first_route;
    }

    void update_route() {
        std::ofstream out(file_path);
        for (auto route_item : route_queue) {
            out << route_item << "\n";
        }
    }

    bool queue_empty() const {
        return route_queue.empty();
    }
};


