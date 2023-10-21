#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "figure.hpp"

class Square final : public Figure {
public:
    explicit Square();

public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    explicit operator double() const noexcept override;
    Point2D geometrical_center() const noexcept override;

    void validation() override;

    bool operator == (Square &other);
    bool operator != (Square &other);
};

#endif