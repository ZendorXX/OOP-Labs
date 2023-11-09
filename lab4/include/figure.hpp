#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <iostream>
#include <cmath>
#include <algorithm>

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

    Figure(Figure const &other);
    Figure(Figure &&other) noexcept;

    Figure(int cnt);    
    virtual ~Figure() noexcept;

protected:
    virtual void print(std::ostream& out) const = 0;
    virtual void input(std::istream& in) = 0;

public:
    friend std::ostream& operator << (std::ostream& out, Figure const &T);
    friend std::istream& operator >> (std::istream& in, Figure &T);

    Figure& operator = (Figure const &other);
    Figure& operator = (Figure &&other) noexcept;

    bool operator == (Figure const &other) const noexcept;
    bool operator != (Figure const &other) const noexcept;

    virtual void validation() = 0;

    void sort_vertices() const noexcept;
    Point2D geometrical_center() const noexcept;
    explicit operator double() const noexcept;
};

Figure::Figure(int cnt) {
    cnt_vertices = cnt;
    vertices = new Point2D[cnt_vertices];
}

Figure::Figure(Figure const &other) {
    cnt_vertices = other.cnt_vertices;
    vertices = new Point2D[cnt_vertices];
    for (size_t i = 0; i < cnt_vertices; ++i) {
        vertices[i] = other.vertices[i];
    }
}

Figure::Figure(Figure &&other) noexcept {
    cnt_vertices = other.cnt_vertices;
    vertices = other.vertices;

    other.cnt_vertices = -1;
    other.vertices = nullptr;
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

bool Figure::Point2D::operator == (Figure::Point2D const &other) const noexcept {
    if (fabs(x - other.x) < eps and fabs(y - other.y) < eps) {
        return true;
    }
    return false;
}

bool Figure::Point2D::operator != (Figure::Point2D const &other) const noexcept {
    return !(*this == other);
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
    std::cout << "copy assignment\n";
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

Figure& Figure::operator = (Figure &&other) noexcept {
    std::cout << "move assignment\n";
    if (this == &other) {
        return *this;
    }
    
    if (vertices != nullptr) {
        delete[] vertices;
    }

    cnt_vertices = other.cnt_vertices;
    vertices = other.vertices;

    other.cnt_vertices = -1;
    other.vertices = nullptr;

    return *this;
}

bool cmp (Figure::Point2D const &a, Figure::Point2D const &b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

bool cmp_for_traversal (Figure::Point2D const &a, Figure::Point2D const &b) {
    return a.vect(b) > 0;
}

void Figure::sort_vertices() const noexcept {
    std::sort(vertices, vertices + cnt_vertices, cmp);
    double move_x = vertices[0].x, move_y = vertices[0].y;
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i].x -= move_x;
        vertices[i].y -= move_y;
    }
    std::sort(vertices, vertices + cnt_vertices, cmp_for_traversal);
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i].x += move_x;
        vertices[i].y += move_y;
    }
}

Figure::Point2D Figure::geometrical_center() const noexcept {
    Point2D center;
    for (int i = 0; i < cnt_vertices; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= cnt_vertices;
    center.y /= cnt_vertices;
    return center;
}

Figure::operator double() const noexcept {
    double left_sum = 0, right_sum = 0;
    for (int i = 0; i < cnt_vertices; ++i) {
        left_sum += vertices[i % cnt_vertices].x * vertices[(i + 1) % cnt_vertices].y;
        right_sum += vertices[(i + 1) % cnt_vertices].x * vertices[i % cnt_vertices].y;
    }
    return fabs(left_sum - right_sum) / 2;
}

bool Figure::operator == (Figure const &other) const noexcept {
    for (int i = 0; i < cnt_vertices - 1; ++i) {
        if (vertices[i].distance_to(vertices[i + 1]) != other.vertices[i].distance_to(other.vertices[i + 1])) {
            return false;
        }
    }
    return true;
}

bool Figure::operator != (Figure const &other) const noexcept {
    return !(*this == other);
}

#endif