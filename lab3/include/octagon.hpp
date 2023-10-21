#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "figure.hpp"

class Octagon final : public Figure {
public:
    explicit Octagon();

public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

#endif