#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <cmath>

#define eps 1e-9

class Figure {
public:
    struct Point2D
    {
        double x;
        double y;

        friend std::istream& operator >> (std::istream& in, Point2D &T);
        friend std::ostream& operator << (std::ostream& out, Point2D const &T);

        double distance_to (Point2D const &other) const;

        double vect (Point2D const &other) const;
    };

protected:
    int cnt_vertices = -1;
    Point2D* vertices;

public:
    Figure() = default;
    Figure(int cnt);    
    virtual ~Figure() noexcept;

protected:
    virtual void print(std::ostream& out) const = 0;
    virtual void input(std::istream& in) = 0;

public:
    friend std::ostream& operator << (std::ostream& out, Figure const &T);
    friend std::istream& operator >> (std::istream& in, Figure &T);

    explicit virtual operator double() const noexcept = 0;
    virtual Point2D geometrical_center() const noexcept = 0;
    virtual void validation() = 0;

    Figure& operator = (Figure const &other);

    void sort_vertices() const noexcept;
};

#endif