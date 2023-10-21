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

        bool operator == (Point2D const &other) const noexcept;
        bool operator != (Point2D const &other) const noexcept;
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

    Figure& operator = (Figure const &other);

    bool operator == (Figure const &other) const noexcept;
    bool operator != (Figure const &other) const noexcept;

    virtual void validation() = 0;

    void sort_vertices() const noexcept;
    Point2D geometrical_center() const noexcept;
    explicit operator double() const noexcept;
};

#endif