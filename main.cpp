#include <iostream>
#include "include/reconf_str.h"

int main() {
    std::string input;
    std::cout << "Введите строку. Все 'a' будут заменены на 'b' и наоборот. Допустимые символы: a, b, c : ";
    std::getline(std::cin, input);

    std::string reconf {reconfString(input)};
    std::cout << "Реконфигурированная строка: " << reconf << std::endl;

    return 0;
}