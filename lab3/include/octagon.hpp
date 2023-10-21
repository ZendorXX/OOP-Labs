#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "figure.hpp"

class Octagon final : public Figure {
public:
    explicit Octagon();

public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    explicit operator double() const noexcept override;
    Point2D geometrical_center() const noexcept override;

    //void sort_vertices();
    void validation() override;

    bool operator == (Octagon &other);
    bool operator != (Octagon &other);
};

#endif