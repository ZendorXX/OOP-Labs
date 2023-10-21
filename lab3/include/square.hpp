#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "figure.hpp"

class Square final : public Figure {
public:
    explicit Square();
    explicit Square(Point2D *poitns);
public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

#endif