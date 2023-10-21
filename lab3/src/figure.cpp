#include "figure.hpp"

Figure::Figure(int cnt) {
    cnt_vertices = cnt;
    vertices = new Point2D[cnt_vertices];
}

Figure::~Figure() noexcept {
    delete[] vertices;
}

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

Figure& Figure::operator = (Figure const &other) {
    if (this == &other) {
        return *this;
    }
    delete[] vertices;
    cnt_vertices = other.cnt_vertices;
    vertices = new Point2D[cnt_vertices];
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i] = other.vertices[i];
    }
    return *this;
}