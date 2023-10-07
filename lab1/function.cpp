/*
Вариант 8
Вам дана строка, представляющая собой число в двоичном виде. Ваша задача - удалить все
нулевые биты в этой строке и вернуть соответствующее число (сохранив только "1").
На практике вы должны реализовать эту функцию:
long eliminate_unset_bits(string number);
Примеры
eliminate_unset_bits("1101010101010101") -> 255 (= 11111111)
                                                   111111111
eliminate_unset_bits("111") -> 7
eliminate_unset_bits("1000000") -> 1
eliminate_unset_bits("000") -> 0
*/

#include <string>
#include <cmath>

long eliminate_unset_bits(const std::string &number) {
    if (number == "" || number.size() == 0) { return -1; }
    for (char bit : number) {
        if (bit == '0' || bit == '1') {
            continue;
        }
        return -1;
    }

    std::string number_without_0 = "";
    for (char bit : number) {
        if (bit != '0') {
            number_without_0 += bit;
        }
    }
    long result = 0;
    int cnt_of_digit = number_without_0.size();
    for (int i = 0; i < cnt_of_digit; ++i) {
        result += (long)pow(2, cnt_of_digit - i - 1); // плохая реализация
    }

    return result;
}