// 8-угольник

#include <iostream>
#include <cmath>

#include "figure.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "octagon.hpp"

void menu() {
    std::cout << "Press 0 to exit" << std::endl
              << "      1 to input triangle" << std::endl
              << "      2 to input square" << std::endl
              << "      3 to input octagon" << std::endl
              << "      4 to print total area" << std::endl
              << "      5 to print size of figures array" << std::endl
              << "      6 to print figures array" << std::endl 
              << "      7 to delete element in figures array by index" << std::endl;
}

int main() {
    size_t size = 0;
    int capacity = 1;
    Figure** arr = (Figure**)malloc(sizeof(Figure*));
    
    menu();

    int cmd;
    double total_area = 0;
    while (std::cin >> cmd) {
        if (cmd == 0) {
            for (int i = 0; i < size; ++i) {
                free(arr[i]);
            }
            free(arr);
            return 0;
        }
        else if (cmd == 1 or cmd == 2 or cmd == 3) {
            ++size;

            if (size >= capacity) {
                capacity *= 2;
                arr = (Figure**)realloc(arr, capacity * sizeof(Figure*));
            }

            bool is_valid = true;
            Figure* tmp;
            if (cmd == 1) {
                arr[size - 1] = new Triangle();
                tmp = new Triangle();
            }
            else if (cmd == 2) {
                arr[size - 1] = new Square();
                tmp = new Square();
            }
            else if (cmd == 3) {
                arr[size - 1] = new Octagon();
                tmp = new Octagon();
            }

            try {
                std::cin >> *tmp;
            }
            catch (std::logic_error &l_ex) {
                std::cout << "exepction: " << l_ex.what() << std::endl;
                is_valid = false;
                --size;
            }

            if (is_valid) {
                *arr[size - 1] = *tmp;
                double curr_area = double(*arr[size - 1]);
                total_area += curr_area;
                
                std::cout << *arr[size - 1] 
                        << "Center: " << arr[size - 1]->geometrical_center() << std::endl 
                        << "Area: " << curr_area << std::endl 
                        << std::endl;
            }

            delete tmp;
        }
        else if (cmd == 4) {
            std::cout << "Total area: " << total_area << std::endl;
        } 
        else if (cmd == 5) {
            std::cout << "Size of figures array: " << size << std::endl;
            std::cout << "[DEBUG_INFO] capacity: " << capacity << std::endl;
        }
        else if (cmd == 6) {
            std::cout << "====================" << std::endl
                      << "Figures array:" << std::endl;
            for (int i = 0; i < size; ++i) {
                std::cout << "Figure " << i + 1 << ":" << std::endl 
                          << *arr[i] 
                          << "Center: " << arr[i]->geometrical_center() << std::endl 
                          << "Area: " << double(*arr[i]) << std::endl 
                          << std::endl;
            }
            std::cout << "====================" << std::endl;
        }
        else if (cmd == 7) {
            std::cout << "Print index of element which should be deleted: ";
            int del_index;
            std::cin >> del_index;
            if (del_index >= size and del_index < 0) {
                std::cout << std::endl << "There is no element with given index. Try again." << std::endl;
                std::cout << std::endl;
                menu();
                continue;
            }
            for (int i = del_index; i < size - 1; ++i) {
                *arr[i] = *arr[i + 1];
            }
            delete arr[size - 1];
            --size;
        }
        else { 
            std::cout << "Invalid cmd. Please, try again." << std::endl;
        }
        std::cout << std::endl;
        menu();
    }


    for (int i = 0; i < size; ++i) {
        free(arr[i]);
    }
    free(arr);

    return 0;
}