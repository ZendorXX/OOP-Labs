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
    int cnt;
    std::cin >> cnt;
    Array<std::shared_ptr<Figure<double>>> figures(cnt);

    for (int i = 0; i < cnt; ++i) {
        std::cin >> cmd;
        std::shared_ptr< Figure<double> > tmp;
        if (cmd == 1) { tmp = std::make_shared< Triangle<double> > (); }
        else if (cmd == 2) { tmp = std::make_shared< Square<double> > (); }
        else if (cmd == 3) { tmp = std::make_shared< Octagon<double> >(); }

        try {
            std::cin >> *tmp;
        }
        catch (std::logic_error &l_ex) {
            std::cout << "exepction: " << l_ex.what() << std::endl;
        }

        figures.input_figure(cmd, tmp);
    }

    figures.print_figures();

    /*do {
        menu();

        std::cin >> cmd;

        if (cmd == 0) {
            break;
        }
        else if (cmd == 1 or cmd == 2 or cmd == 3) {
            Figure<double>* tmp;
            if (cmd == 1) { tmp = new Triangle(); }
            else if (cmd == 2) { tmp = new Square(); }
            else if (cmd == 3) { tmp = new Octagon(); }

            try {
                std::cin >> *tmp;
            }
            catch (std::logic_error &l_ex) {
                std::cout << "exepction: " << l_ex.what() << std::endl;
                delete tmp;
            }

            figures.input_figure(cmd, tmp);

            delete tmp;
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
    } while (cmd != 0);*/

    return 0;
}