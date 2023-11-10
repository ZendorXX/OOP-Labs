#ifndef FIGURE_HPP
#define FIGURE_HPP

#include <algorithm>
#include <memory>

#include "point.hpp"

template <class T>
bool cmp (Point2D<T> const &a, Point2D<T> const &b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}

template <class T>
bool cmp_for_traversal (Point2D<T> const &a, Point2D<T> const &b) {
    return a.vect(b) > 0;
}

template <class T>
class Figure {
protected:
    int cnt_vertices = -1;
    std::shared_ptr< Point2D<T>[] > vertices;
    //Point2D<T>* vertices;

public:
    Figure() = default;

    Figure(Figure const &other) {
        cnt_vertices = other.cnt_vertices;
        vertices = std::shared_ptr< Point2D<T>[] >(new Point2D<T>[cnt_vertices]);
        for (size_t i = 0; i < cnt_vertices; ++i) {
            vertices[i] = other.vertices[i];
        }
    }
    Figure(Figure &&other) noexcept {
        cnt_vertices = other.cnt_vertices;
        vertices = other.vertices;

        other.cnt_vertices = -1;
        other.vertices = nullptr;
    }

    Figure(int cnt) {
        cnt_vertices = cnt;
        //vertices = new Point2D<T>[cnt_vertices];
        vertices = std::shared_ptr< Point2D<T>[] >(new Point2D<T>[cnt_vertices]);
    }
    virtual ~Figure() noexcept = default;

protected:
    virtual void print(std::ostream& out) const = 0;
    virtual void input(std::istream& in) = 0;

public:
    friend std::ostream& operator << (std::ostream& out, Figure const &f) {
        f.print(out);
        return out;
    }
    friend std::istream& operator >> (std::istream& in, Figure &f) {
        f.input(in);
        return in;
    }

    Figure& operator = (Figure const &other) {
        std::cout << "copy assignment\n";
        if (this == &other) {
            return *this;
        }
        cnt_vertices = other.cnt_vertices;
        vertices = new Point2D<T>[cnt_vertices];
        for (int i = 0; i < cnt_vertices; ++i) {
            vertices[i] = other.vertices[i];
        }
        return *this;
    }
    Figure& operator = (Figure &&other) noexcept {
        std::cout << "move assignment\n";
        if (this == &other) {
            return *this;
        }

        cnt_vertices = other.cnt_vertices;
        vertices = other.vertices;

        other.cnt_vertices = -1;
        other.vertices = nullptr;

        return *this;
    }

    bool operator == (Figure const &other) const noexcept {
        for (int i = 0; i < cnt_vertices - 1; ++i) {
            if (vertices[i].distance_to(vertices[i + 1]) != other.vertices[i].distance_to(other.vertices[i + 1])) {
                return false;
            }
        }
        return true;
    }
    bool operator != (Figure const &other) const noexcept {
        return !(*this == other);
    }

    /*void sort_vertices() const noexcept {
        //std::sort(std::begin(vertices), std::end(vertices), cmp);
        double move_x = vertices[0].x, move_y = vertices[0].y;
        for (int i = 0; i < cnt_vertices; ++i) {
            vertices[i].x -= move_x;
            vertices[i].y -= move_y;
        }
        //std::sort(std::begin(vertices), std::end(vertices), cmp_for_traversal);
        for (int i = 0; i < cnt_vertices; ++i) {
            vertices[i].x += move_x;
            vertices[i].y += move_y;
        }
    }*/
    Point2D<T> geometrical_center() const noexcept {
        Point2D<T> center;
        for (int i = 0; i < cnt_vertices; ++i) {
            center.x += vertices[i].x;
            center.y += vertices[i].y;
        }
        center.x /= cnt_vertices;
        center.y /= cnt_vertices;
        return center;
    }
    explicit operator double() const noexcept {
        double left_sum = 0, right_sum = 0;
        for (int i = 0; i < cnt_vertices; ++i) {
            left_sum += vertices[i % cnt_vertices].x * vertices[(i + 1) % cnt_vertices].y;
            right_sum += vertices[(i + 1) % cnt_vertices].x * vertices[i % cnt_vertices].y;
        }
        return fabs(left_sum - right_sum) / 2;
    }

    virtual void validation() = 0;
};

#endif