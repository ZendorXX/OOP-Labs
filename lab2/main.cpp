// вариант 8
/*
Создать класс Seven для работы с беззнаковыми целыми семеричными числами, 
используя для представления числа массив из элементов типа unsigned char, 
каждый элемент которого является семиричной цифрой.
Младшая цифра имеет 
меньший индекс (единицы — в нулевом элементе массива).
*/

#include <iostream>
#include "seven.hpp"

int main() {
    Seven a ("10000");
    Seven b ("1");
    a.diff(b);
    std::cout << a << '\n';

    /*Seven a1 ("534021");
    Seven b1 ("102346");
    Seven c1 = a1 - b1;
    std::cout << c1 << '\n';*/

    Seven a2("120000");
    Seven b2("4000");
    std::cout << a2 - b2 << '\n';
    return 0;
}