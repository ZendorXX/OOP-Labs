#ifndef ARRAY_HPP
#define ARRAY_HPP

#include "figure.hpp"
#include "octagon.hpp"
#include "triangle.hpp"
#include "square.hpp"

template <class T>
class Array {
private:
    size_t size;
    int capacity;
    //T* arr;
    std::shared_ptr< T[] > arr;
    double total_area;

public:
    Array() {
        size = 0;
        capacity = 1;
        //arr = new T[capacity];
        arr = std::shared_ptr< T[] >(new T[capacity]);
        total_area = 0;
    }

    Array(int SIZE) {
        size = 0;
        capacity = SIZE;
        //arr = new T[capacity];
        arr = std::shared_ptr< T[] >(new T[capacity]);
        total_area = 0;
    }

    ~Array() = default;

    void input_figure(int cmd, T tmp) {
        /*if (size + 1 >= capacity) {
            capacity *= 2;

            std::shared_ptr< T[][] > tmp_arr = std::shared_ptr< T[] >(new T[capacity]);
            
            for (size_t i = 0; i < size; ++i) {
                *tmp_arr[i] = std::move(*arr[i]);
            }
            //std::move(arr, arr + size, tmp_arr);

            arr = tmp_arr;
        }*/

        if (size + 1 > capacity) {
            std::cout << "MEMORT LIMIT" << std::endl;
            return;
        }

        if (cmd == 1) { arr[size] = std::make_shared< Triangle<double> > (); }
        else if (cmd == 2) { arr[size] = std::make_shared< Square<double> > (); }
        else if (cmd == 3) { arr[size] = std::make_shared< Octagon<double> >(); }

        *arr[size] = std::move(*tmp);
        double curr_area = double(*arr[size]);
        total_area += curr_area;
        
        std::cout << *arr[size] 
                    << "Center: " << arr[size]->geometrical_center() << std::endl 
                    << "Area: " << curr_area << std::endl;

        
        ++size;
    }

    void get_total_area() {
        std::cout << "Total area: " << total_area << std::endl;
    }

    void get_size() {
        std::cout << "Size of figures array: " << size << std::endl;
        std::cout << "[DEBUG_INFO] capacity: " << capacity << std::endl;
    }

    void print_figures() {
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

    void delete_elem() {
        if (size == 0) {
            std::cout << "Array is empty!" << std::endl;
        }
        std::cout << "Print index of element which should be deleted: ";
        size_t del_index;
        std::cin >> del_index;
        if (del_index > size - 1) {
            std::cout << std::endl << "There is no element with given index. Try again." << std::endl;
        }
        for (int i = del_index; i < size - 1; ++i) {
            *arr[i] = std::move(*arr[i + 1]);
        }
        delete arr[size - 1];
        --size;
    }

    void compare_elements() {
        if (size == 0) {
            std::cout << "Array is empty!" << std::endl;
        }
        size_t first_index, second_index;
        std::cout << "Print index of first element: ";
        std::cin >> first_index;
        std::cout << "Print index of second element: ";
        std::cin >> second_index;

        if (first_index > size - 1 or second_index > size - 1) {
            std::cout << "Invalid indexex. Try again." << std::endl;
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
};

#endif 