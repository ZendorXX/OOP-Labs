#include <iostream>
#include "function.cpp"

int main() {
    std::string input;
    std::cin >> input;

    long result = eliminate_unset_bits(input);
    if (result == -1) {
        std::cout << "Произошла ошибка. Перепроверьте введённые данные.\n";
    } else {
        std::cout << result << '\n';
    }

    return 0;
}