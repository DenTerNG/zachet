// main.cpp
#include <iostream>
#include "a_b.hpp"

int main() {
    A a;
    int number;

    std::cout << "Введите число для проверки делимости на 5: ";
    std::cin >> number;

    int res = a.f1(number);
    std::cout << "Результат: " << res << std::endl;

    return 0;
}
