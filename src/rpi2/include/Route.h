#pragma once
#include <expected.hpp>
#include <fstream>
#include <http_headers.hpp>
#include <deque>
//=========================*/
// Example data structure
//=========================*/

class Route {

    private:
    std::ofstream route_file;
    std::deque<std::string> route_queue;
    std::string file_path;

    public:

    Route(const std::string& file_path = "../../output/logger.txt") : file_path(file_path) {
        route_file.open(file_path, std::ios::app);
        if (!route_file.is_open()) {
            throw std::runtime_error("failed to opn file");
        }

        if (route_file.is_open()) {
            std::ifstream route_file_stream(file_path);
            std::string line;
            while (std::getline(route_file_stream, line)) {
                route_queue.push_back(line);
            }
        }
    };
    ~Route() {
        if (route_file.is_open()) {
            route_file.close();
        }
    }

    void post_route(const std::string& log_rooms) {
        route_queue.push_back(log_rooms);
        if (route_file.is_open()) {
            route_file << route_queue.back() << "\n";
            route_file.flush();
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


