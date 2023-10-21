#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "figure.hpp"

class Octagon final : public Figure {
public:
    explicit Octagon();
    explicit Octagon(Point2D *poitns);
public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

#endif