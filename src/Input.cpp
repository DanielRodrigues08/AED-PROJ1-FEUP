//
// Created by pedro on 02/12/2021.



#include "Input.h"

using namespace std;

namespace input {
    string getRaw() {
        std::string str;
        std::cout << "> ";
        std::getline(std::cin, str);
        trimString(str);
        std::cout << std::endl;
        return str;
    }

    void waitEnter() {
        std::cout << std::endl << "Press enter to continue..." << std::endl;
        std::string str;
        std::getline(std::cin, str);
    }

    void trimString(std::string &str) {
        // Remove whitespace from start and end of the string
        auto front = std::find_if_not(str.begin(), str.end(), [](int c) {
            return std::isspace(c);
        });
        auto back = std::find_if_not(str.rbegin(), str.rend(), [](int c) {
            return std::isspace(c);
        }).base();
        str = back <= front ? std::string() : std::string(front, back);

        // Convert multiple whitespaces into a single one
        // For example "Viewer   Complete      Name" would become "Viewer Complete Name"
        auto new_end = std::unique(str.begin(), str.end(), [](char a, char b) {
            return (a == b) && (a == ' ');
        });
        str.erase(new_end, str.end());
    }

    bool validateID(const std::string &id) {
        if (id.empty()) {
            std::cout << "ID number can't be empty" << std::endl;
            return false;
        }
        if (id.length() > MAX_NAME_LENGHT) {
            std::cout << "ID number can't exceed " << MAX_NAME_LENGHT << " characters " << std::endl;
            return false;
        }

        for (auto c: id) {
            if (!isdigit(c)) {
                std::cout << "ID number can only contain numeric characters" << std::endl;
                return false;
            }
        }
        return true;
    }
}