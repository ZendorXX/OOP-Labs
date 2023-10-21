#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"

class Triangle final: public Figure {
public:
    explicit Triangle();

public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;

    bool operator == (Triangle &other);
    bool operator != (Triangle &other);
};

#endif