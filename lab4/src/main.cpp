#include <iostream>

#include "array.hpp"

void menu() {
    std::cout << std::endl;
    std::cout << "Press 0 to exit" << std::endl
              << "      1 to input triangle" << std::endl
              << "      2 to input square" << std::endl
              << "      3 to input octagon" << std::endl
              << "      4 to print total area" << std::endl
              << "      5 to print size of figures array" << std::endl
              << "      6 to print figures array" << std::endl 
              << "      7 to delete element in figures array by index (indexes must be positive!)" << std::endl
              << "      8 to check if two figures are equal (indexes must be positive!)" << std::endl
              << std::endl;
}

int main() {
    int cmd;
    Array figures;

    do {
        menu();

        std::cin >> cmd;

        if (cmd == 0) {
            break;
        }
        else if (cmd == 1 or cmd == 2 or cmd == 3) {
           figures.input_figure(cmd);
        }
        else if (cmd == 4) {
            figures.get_total_area();
        } 
        else if (cmd == 5) {
           figures.get_size();
        }
        else if (cmd == 6) {
            figures.print_figures();
        }
        else if (cmd == 7) {
            figures.delete_elem();
        }
        else if (cmd == 8) {
           figures.compare_elements();
        }
        else { 
            std::cout << "Invalid cmd. Please, try again." << std::endl;
        }
    } while (cmd != 0);

    return 0;
}