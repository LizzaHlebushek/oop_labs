#include <iostream>
#include "../include/reconf_str.h"


std::string reconfString(const std::string& str) {
    std::string resultString = "";
    for (char c : str) {
        switch (c) {
        case 'a':
            resultString += "b";
            break;
        case 'b':
            resultString += "a";
            break;
        case 'c':
            resultString += "c";
            break;
        default:
            throw std::runtime_error("the string contains an invalid character '" + std::string(1, c) + "'");
            break;
        }
    }
    return std::string(resultString);
}