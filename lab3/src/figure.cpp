#include "figure.hpp"

std::istream& operator >> (std::istream& in, Figure::Point2D &T) {
    in >> T.x >> T.y;
    return in;
}

std::ostream& operator << (std::ostream& out, Figure::Point2D const &T)  {
    out << "(" << T.x << ", " << T.y << ")";
    return out;
}

double Figure::Point2D::distance_to (Figure::Point2D const &other) const {
    return sqrt((other.x - x) * (other.x - x) + (other.y - y) * (other.y - y));
}

double Figure::Point2D::vect (Figure::Point2D const &other) const {
    return x * other.y - y * other.x;
}

std::ostream& operator << (std::ostream& out, Figure const &T) {
    T.print(out);
    return out;
}
std::istream& operator >> (std::istream& in, Figure &T) {
    T.input(in);
    return in;
}