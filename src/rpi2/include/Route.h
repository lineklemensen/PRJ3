#pragma once
#include <json_dto\pub.hpp>
#include <fstream>
#include <sstream>
//=========================*/
// Example data structure
//=========================*/

class Route {

    private:
    std::ofstream route_file;

    public:

    Route(const std::string& file_path = "../../output/logger.txt") {
        route_file.open(file_path, std::ios::app);
        if (!route_file.is_open()) {
            throw std::runtime_error("failed to opn file");
        }
    };
    ~Route() {
        if (route_file.is_open()) {
            route_file.close();
        }
    }

    void write_route(const std::string_view log_rooms) {
        if (route_file.is_open()) {
            route_file << log_rooms << "\n";
            route_file.flush();
        }
    };

    std::string get_lates_route(const std::string& file_path = "../../output/logger.txt") {
        std::ifstream log_file(file_path);
        std::string first_line;

        if (std::getline(log_file, first_line)) {
            std::string rest;
            std::string line;
            while (std::getline(log_file, line)) {
                rest += line + "\n";
            }

            std::ofstream out(file_path);
            out << rest;
            return first_line;
        }
    }
};


