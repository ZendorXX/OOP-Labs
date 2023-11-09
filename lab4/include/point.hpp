#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <cmath>

#define eps 1e-9

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

std::istream& operator >> (std::istream& in, Point2D &T) {
    in >> T.x >> T.y;
    return in;
}

std::ostream& operator << (std::ostream& out, Point2D const &T)  {
    out << "(" << T.x << ", " << T.y << ")";
    return out;
}

double Point2D::distance_to (Point2D const &other) const {
    return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

double Point2D::vect (Point2D const &other) const {
    return x * other.y - y * other.x;
}

bool Point2D::operator == (Point2D const &other) const noexcept {
    if (fabs(x - other.x) < eps and fabs(y - other.y) < eps) {
        return true;
    }
    return false;
}

bool Point2D::operator != (Point2D const &other) const noexcept {
    return !(*this == other);
}

#endif