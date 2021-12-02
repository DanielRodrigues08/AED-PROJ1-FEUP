//
// Created by pedro on 02/12/2021.
//
#include "Input.h"
#include <iostream>
#include <sstream>
#include <algorithm>
#include <chrono>
#include "Date.h"

namespace input {
    std::string getRaw() {
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
        if (id.length() > MAX_NICKNAME_LENGHT) {
            std::cout << "ID number can't exceed " << MAX_NICKNAME_LENGHT << " characters " << std::endl;
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

    bool validateName(const std::string &name) {
        if (name.empty()) {
            std::cout << "Name can't be empty" << std::endl;
            return false;
        }
        if (name.length() > MAX_NAME_LENGHT) {
            std::cout << "Name can't exceed " << MAX_NAME_LENGHT << " characters " << std::endl;
            return false;
        }
        for (auto c: name) {
            if (!isalpha(c) && c != ' ') {
                std::cout << "Name can only contain alphabetic characters and spaces" << std::endl;
                return false;
            }
        }
        return true;
    }

    bool validateBirthDate(const std::string &date) {


        if (day < 1 || day > 31) {
            return false;
        } else if (month < 1 || month > 12) {
            return false;
        } else if (year < 1900 || year > 2021) {
            return false;
        }

        if ((month == 4 || month == 6 || month == 9 || month == 11) && day == 31) {
            return false;
        } else if ((month == 2) && (year % 4 == 0) && day > 29) {
            return false;

        } else if ((month == 2) && (year % 4 != 0) && day > 28) {
            return false;
        }
        return true;
    }

}