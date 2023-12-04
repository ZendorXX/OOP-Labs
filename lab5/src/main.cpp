#include <iostream>
#include <map>
#include "allocator.hpp"
#include "forward_list.hpp"

int fact(int n) {
    int result = 1;
    for (int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    
    std::cout << "=========================" << std::endl;
    std::cout << "Example with map" << std::endl;
    std::map<int, int, std::less<int>, Allocator< std::pair<const int, int> > > test_map;

    for (int i = 1; i < 10; ++i) {
        test_map.insert(std::pair<int, int>(i, fact(i)));
    }

    for (auto elem : test_map) {
        std::cout << elem.first << ' ' << elem.second << std::endl;
    }

    std::cout << "=========================" << std::endl;
    std::cout << "Example with forward list" << std::endl;
    ForwardList<int, Allocator> list;

    list.push_front(1);
    list.push_front(5);
    list.push_front(6);
    list.push_front(2);

    for (int i = 0; i < list.size(); ++i){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    ForwardList<int, Allocator>::ListIterator it = list.begin();
    ++it; ++it; ++it; ++it;
    list.insert(it, 10);
    for (int i = 0; i < list.size(); ++i){
        std::cout << list[i] << " ";
    }
    std::cout << std::endl;
    std::cout << "=========================" << std::endl;
    
    return 0;
}