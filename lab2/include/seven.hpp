#ifndef __SEVEN_H__
#define __SEVEN_H__

#include <iostream>

class Seven {
    public: 
        Seven();
        Seven(const size_t &n, unsigned char t = 0);
        Seven(const std::initializer_list<unsigned char> &t);
        Seven(const std::string &t);

        Seven(const Seven &other);
        Seven(Seven &&other) noexcept;

        friend std::ostream& operator <<(std::ostream &out, Seven const &t);

        Seven& operator = (Seven const &other);
        Seven& operator = (Seven &&other);

        bool operator ==(Seven &other);
        bool operator > (Seven &other);
        bool operator < (Seven &other);

        Seven operator +(Seven &other);
        Seven operator -(Seven &other);

        Seven add(Seven &other);
        Seven diff(Seven &other);

        virtual ~Seven() noexcept;
    private:
        size_t _size;
        unsigned char *_array;
        void resize(size_t new_size);
        void remove_leading_zeros();
};

#endif