#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

#define eps 1e-9

template <class T>
struct Point2D
{
    T x;
    T y;

    friend std::istream& operator >> (std::istream& in, Point2D<T> &p) {
        in >> p.x >> p.y;
        return in;
    }
    friend std::ostream& operator << (std::ostream& out, Point2D<T> const &p) {
        out << "(" << p.x << ", " << p.y << ")";
        return out;
    }

    double distance_to (Point2D const &other) const {
        return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
    }

    double vect (Point2D const &other) const {
        return x * other.y - y * other.x;
    }

    bool operator == (Point2D const &other) const noexcept {
        if (fabs(x - other.x) < eps and fabs(y - other.y) < eps) {
            return true;
        }
        return false;
    }
    bool operator != (Point2D const &other) const noexcept {
        return !(*this == other);
    }
};

#endif