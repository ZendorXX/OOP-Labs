#include <iostream>

#include "figure.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "octagon.hpp"

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
    size_t size = 0;
    int cmd;
    int capacity = 1;
    Figure** arr = new Figure*[capacity];
    double total_area = 0;

    do {
        menu();

        std::cin >> cmd;

        if (cmd == 0) {
            break;
        }
        else if (cmd == 1 or cmd == 2 or cmd == 3) {
            Figure* tmp;
            if (cmd == 1) { tmp = new Triangle(); }
            else if (cmd == 2) { tmp = new Square(); }
            else if (cmd == 3) { tmp = new Octagon(); }

            try {
                std::cin >> *tmp;
            }
            catch (std::logic_error &l_ex) {
                std::cout << "exepction: " << l_ex.what() << std::endl;
                delete tmp;
                continue;
            }

            if (size + 1 >= capacity) {
                capacity *= 2;
  
                Figure** tmp_arr = new Figure*[capacity];
                
                std::move(arr, arr + size, tmp_arr);

                arr = tmp_arr;
            }

            if (cmd == 1) { arr[size] = new Triangle(); }
            else if (cmd == 2) { arr[size] = new Square(); }
            else if (cmd == 3) { arr[size] = new Octagon(); }

            *arr[size] = std::move(*tmp);
            double curr_area = double(*arr[size]);
            total_area += curr_area;
            
            std::cout << *arr[size] 
                      << "Center: " << arr[size]->geometrical_center() << std::endl 
                      << "Area: " << curr_area << std::endl;

            
            ++size;

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
            if (size == 0) {
                std::cout << "Array is empty!" << std::endl;
                continue;
            }
            std::cout << "Print index of element which should be deleted: ";
            size_t del_index;
            std::cin >> del_index;
            if (del_index > size - 1) {
                std::cout << std::endl << "There is no element with given index. Try again." << std::endl;
                continue;
            }
            for (int i = del_index; i < size - 1; ++i) {
                *arr[i] = std::move(*arr[i + 1]);
            }
            delete arr[size - 1];
            --size;
        }
        else if (cmd == 8) {
            if (size == 0) {
                std::cout << "Array is empty!" << std::endl;
                continue;
            }
            size_t first_index, second_index;
            std::cout << "Print index of first element: ";
            std::cin >> first_index;
            std::cout << "Print index of second element: ";
            std::cin >> second_index;

            if (first_index > size - 1 or second_index > size - 1) {
                std::cout << "Invalid indexex. Try again." << std::endl;
                continue;
            }

            std::cout << std::endl;
            if (*arr[first_index] == *arr[second_index]) {
                std::cout << "Figures at indexes " << first_index << " and " << second_index 
                          << " are equal" << std::endl;
            }
            else {
                std::cout << "Figures at indexes " << first_index << " and " << second_index 
                          << " are not equal" << std::endl;
            }
        }
        else { 
            std::cout << "Invalid cmd. Please, try again." << std::endl;
        }
    } while (cmd != 0);

    for (int i = 0; i < size; ++i) {
        delete(arr[i]);
    }
    delete(arr);

    return 0;
}