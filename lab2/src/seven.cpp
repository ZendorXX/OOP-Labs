#include "seven.hpp"

//Default constructor
Seven::Seven() : _size(0), _array{nullptr} {}

//Fill constructor
Seven::Seven(const size_t &n, unsigned char t) {
    _size = n;
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i) {
        _array[_size - i - 1] = t;
    }
}

//Initializer list constructor
Seven::Seven(const std::initializer_list<unsigned char> &t) {
    _size = t.size();
    _array = new unsigned char[_size];
    size_t i = _size - 1;
    for (auto &c : t) {
        _array[i--] = c;
    }
}

//Copy string constuctor
Seven::Seven(const std::string &t) {
    _size = t.size();
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i) {
        _array[_size - i - 1] = t[i];
    }
}

//Copy constructor
Seven::Seven(const Seven &other) {
    _size = other._size;
    _array = new unsigned char[_size];
    for (size_t i = 0; i < _size; ++i) {
        _array[i] = other._array[i];
    }
}

//Move constructor
Seven::Seven(Seven &&other) noexcept {
    _size = other._size;
    _array = other._array;

    other._size = 0;
    other._array = nullptr;
}

Seven& Seven::operator = (Seven const &other) {
    if (this == &other) {
        return *this;
    }

    if (this->_size != other._size) {
        unsigned char *temp = new unsigned char[other._size];
        if (this->_array != nullptr) {
            delete[] this->_array;
        }
        this->_array = temp;
        this->_size = other._size;
    }
    std::copy(other._array, other._array + other._size, this->_array);

    return *this;
}

Seven& Seven::operator = (Seven &&other) {
    if (this == &other) {
        return *this;
    }

    this->_size = other._size;
    other._size = 0;

    if (this->_array != nullptr)  {
        delete[] this->_array;
    }
    this->_array = other._array;
    other._array = nullptr;

    return *this;
}

std::ostream& operator <<(std::ostream &out, Seven const &t) {
    for (size_t i = t._size; i > 0; i--) {
        out << t._array[i - 1];
    }
    return out;
}

bool Seven::operator ==(Seven &other) {
    if (this->_size != other._size) {
        return false;
    }

    for (size_t i = this->_size; i > 0; --i) {
        if (this->_array[i - 1] == other._array[i - 1]) {
            continue;
        }
        return false;
    }

    return true;
}

bool Seven::operator >(Seven &other) {
    if (this->_size < other._size) {
        return false;
    } 

    if (this->_size > other._size) {
        return true;
    } 

    for (size_t i = this->_size; i > 0; --i) {
        if (this->_array[i - 1] == other._array[i - 1]) {
            continue;
        }
        if (this->_array[i - 1] > other._array[i - 1]) {
            return true;
        }
        if (this->_array[i - 1] < other._array[i - 1]) {
            return false;
        }
    }

    return false;
}

bool Seven::operator <(Seven &other) {
    if (*this > other || *this == other) {
        return false;
    }

    return true;
}

void Seven::resize(size_t new_size) {
    if (this->_size > new_size) {
        throw std::logic_error("New size have to be bigger that current");
    } 

    if (this->_size == new_size) {
        return;
    }

    unsigned char *new_array = new unsigned char[new_size];
    for (size_t i = 0; i < this->_size; ++i) {
        new_array[i] = this->_array[i];
    }
    delete[] this->_array;
    this->_size = new_size;
    this->_array = new_array;
}

Seven Seven::operator +(Seven &other) {
    size_t max_size = this->_size > other._size ? this->_size : other._size;
    Seven tmp(max_size, '0');
    unsigned int rem = 0, digit_of_this = 0, digit_of_other = 0;

    for (size_t i = 0; i < max_size; ++i) {
        digit_of_this = i < this->_size ? int(this->_array[i]) - 48 : 0;
        digit_of_other = i < other._size ? int(other._array[i]) - 48 : 0;

        int sum = digit_of_this + digit_of_other + rem;
        tmp._array[i] = static_cast<char>(int(tmp._array[i]) + sum % 7);
        rem = sum / 7;
    }

    if (rem != 0) {
        tmp.resize(max_size + 1);
        tmp._array[tmp._size - 1] = static_cast<char>(rem + 48);
    }

    return tmp;
}

void Seven::remove_leading_zeros() {
    int cnt_of_zeros = 0;
    for (size_t i = this->_size; i > 0; i--) {
        if (this->_array[i - 1] == '0') {
            cnt_of_zeros += 1;
        } 
        else {
            break;
        }
    }
    if (cnt_of_zeros == this->_size) {
        --cnt_of_zeros;
    }
    size_t new_size = this->_size - cnt_of_zeros;
    unsigned char *new_array = new unsigned char[new_size];
    for (size_t i = 0; i < new_size; ++i) {
        new_array[i] = this->_array[i];
    }
    delete[] this->_array;
    this->_size = new_size;
    this->_array = new_array;
}

Seven Seven::operator -(Seven &other) {
    if (other > *this) {
        throw std::logic_error("Second number can't be greater than first number!");
    }

    size_t max_size = this->_size > other._size ? this->_size : other._size;
    Seven tmp(max_size, '0');
    int rem = 0, digit_of_this = 0, digit_of_other = 0;

    for (size_t i = 0; i < max_size; ++i) {
        digit_of_this = i < this->_size ? int(this->_array[i]) - 48 : 0;
        digit_of_other = i < other._size ? int(other._array[i]) - 48 : 0;

        if (rem > 0) {
            digit_of_this -= rem;
        }

        int diff = digit_of_this - digit_of_other;

        if (diff < 0) {
            rem = 1;
            diff += 7;
        } 
        else {
            rem = 0;
        }
        tmp._array[i] = static_cast<char>(int(tmp._array[i]) + diff);
    }

    tmp.remove_leading_zeros();
    
    return tmp;
}

Seven Seven::add(Seven &other) {
    *this = *this + other;
    return *this;
}

Seven Seven::diff(Seven &other) {
    *this = *this - other;
    return *this;
}

Seven::~Seven() noexcept {
    this->_size = 0;
    if (this->_array != nullptr) {
        delete[] this->_array;
    }
}