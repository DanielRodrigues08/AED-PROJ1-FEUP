//
// Created by pedro on 02/12/2021.
//

#ifndef AED_PROJ1_INPUT_H
#define AED_PROJ1_INPUT_H


#include <string>
#include <iostream>
#include <sstream>

#define MAX_NAME_LENGHT 20

namespace input {
    /**
     * Get a string from cin
     * @return string
     */
    std::string getRaw();


    /**
     * Convert a string to a var of type T
     * @tparam T - Type with defined >> operator
     * @param str - String to be read
     * @param var - Output after reading
     * @return true if operation was successful
     */
    template<typename T>
    bool strToVar(const std::string &str, T &var) {
        std::istringstream ss{str};
        ss >> var;
        if (ss.fail() || !ss.eof()) {
            return false;
        }
        return true;
    }

    /**
     * Get a var of type T from cin
     * @tparam T - Type with defined >> operator
     * @param var - Output
     * @return true if operation was successful
     */
    template<typename T>
    bool get(T &var) {
        std::string str = getRaw();
        if (str.empty()) {
            return false;
        }
        return strToVar(str, var);
    }

    /**
     * Wait for user to press enter
     */
    void waitEnter();

    void trimString(std::string &str);
    /**
     * Check if name is valid
     * @param name
     * @return true if valid
     */
    bool validateID(const std::string &userid);

    /**
     * Check if name is valid
     * @param name
     * @return true if valid
     */
    bool validateName(const std::string &name);

    /**
     * Check if birthday is valid
     * @param date
     * @return true if valid
     */
    bool validateBirthDate(const std::string &date);

    /**
     * Check if flight is valid
     * @param title
     * @return true if valid
     */

    bool validateFlight(const std::string &flight);

    /**
     * Check if class is valid
     * @param title
     * @return true if valid
     */

    bool validateClass(const std::string &classe);
}

#endif //AED_PROJ1_INPUT_H
