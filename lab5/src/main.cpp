#include <iostream>
#include <map>
#include "allocator.hpp"
#include "container.hpp"

int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    std::map<int, int, std::less<int>, allocator< std::pair<const int, int> > > test_map;

    for (int i = 1; i < 10; ++i) {
        test_map.insert(std::pair<int, int>(i, fact(i)));
    }

    for (auto elem : test_map) {
        std::cout << elem.first << ' ' << elem.second << std::endl;
    }

    ForwardList<int, allocator> list;

    list.push_front(1);
    list.push_front(2);
    list.push_front(3);
    list.push_front(4);
    list.push_front(5);
    
    for (int i = 0; i < 5; ++i){
        std::cout << list[i] << std::endl;
    }


    return 0;
}