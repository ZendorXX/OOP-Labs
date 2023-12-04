#ifndef ALLOCATOR_HPP
#define ALLOCATOR_HPP

// Хранилище внутри аллокатора: std::deque

#include <deque>

template<class T>
class Allocator {
    public:
        using value_type = T;
        using pointer = T*;
        using const_pointer = const T*;
        using size_type = std::size_t;
        
        Allocator() noexcept {};

        ~Allocator() {
            for (pointer elem : used_blocks) {
                delete[] elem;
            }
        }

        pointer allocate(size_type size) {
            std::cout << "allocate" << std::endl;
            pointer reserve_block = new value_type[size];
            if (reserve_block == nullptr) {
                throw std::bad_alloc(); 
            }
            used_blocks.push_back(reserve_block);
            return reserve_block;
        }

        void deallocate(pointer block, size_type size) {
            std::cout << "deallocate" << std::endl;
            for (size_type i = 0; i < used_blocks.size(); ++i) {
                if (used_blocks[i] == block) {
                    used_blocks.erase(used_blocks.begin() + i);
                }
            }
            delete[] block;
        }

    private:
        std::deque<pointer> used_blocks;
};

#endif