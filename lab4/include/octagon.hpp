#ifndef OCTAGON_HPP
#define OCTAGON_HPP

#include "figure.hpp"

template <class T>
class Octagon final : public Figure<T> {
public:
    explicit Octagon();
    explicit Octagon(std::shared_ptr<Point2D<T>> points);
public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

template <class T>
Octagon<T>::Octagon() : Figure<T>(8) {
    this->vertices[0] = {0, 0};
    this->vertices[1] = {1, 0};
    this->vertices[2] = {2, 1};
    this->vertices[3] = {2, 2};
    this->vertices[4] = {1, 3};
    this->vertices[5] = {0, 3};
    this->vertices[6] = {-1, 2};
    this->vertices[7] = {-1, 1};
    validation();
}

template <class T>
Octagon<T>::Octagon(std::shared_ptr<Point2D<T>> points) : Figure<T>(8) {
    for (int i = 0; i < this->cnt_vertices; ++i) {
        this->vertices[i] = points[i];
    }
    //sort_vertices();
    validation();
}

template <class T>
void Octagon<T>::input(std::istream &in) {
    for (int i = 0; i < this->cnt_vertices; ++i) {
        in >> this->vertices[i];
    }
    //sort_vertices();
    validation();
}

template <class T>
void Octagon<T>::print(std::ostream &out) const {
    out << "Octagon:" << std::endl;
    for (int i = 0; i < this->cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << this->vertices[i] << std::endl;
    }
}

template <class T>
void Octagon<T>::validation() {
    for (int i = 0; i < this->cnt_vertices - 2; ++i) {
        double signed_area = (this->vertices[i + 1].x - this->vertices[i].x) * (this->vertices[i + 2].y - this->vertices[i].y) - (this->vertices[i + 1].y - this->vertices[i].y) * (this->vertices[i + 2].x - this->vertices[i].x);
        if (signed_area <= 0) {
            throw std::logic_error("Convex octagon with these vertices doesn't exsist!");
        }
    }
}

#endif