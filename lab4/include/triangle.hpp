#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"

template <class T>
class Triangle final: public Figure<T> {
public:
    explicit Triangle();
    explicit Triangle(std::shared_ptr<Point2D<T>> points);
public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

template <class T>
Triangle<T>::Triangle() : Figure<T>(3) {
    this->vertices[0] = {0, 0};
    this->vertices[1] = {3, 0};
    this->vertices[2] = {0, 4};
    //sort_vertices();
    validation();
}

template <class T>
Triangle<T>::Triangle(std::shared_ptr<Point2D<T>> points) : Figure<T>(3) {
    for (int i = 0; i < this->cnt_vertices; ++i) {
        this->vertices[i] = points[i];
    }
    //sort_vertices();
    validation();
}

template <class T>
void Triangle<T>::input(std::istream &in) {
    for (int i = 0; i < this->cnt_vertices; ++i) {
        in >> this->vertices[i];
    }
    //sort_vertices();
    validation();
}

template <class T>
void Triangle<T>::print(std::ostream &out) const {
    out << "Triangle:" << std::endl;
    for (int i = 0; i < this->cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << this->vertices[i] << std::endl;
    }
}

template <class T>
void Triangle<T>::validation() {
    double AB = this->vertices[0].distance_to(this->vertices[1]);
    double BC = this->vertices[1].distance_to(this->vertices[2]);
    double CA = this->vertices[2].distance_to(this->vertices[0]);

    if ((AB >= BC + CA) or (BC >= AB + CA) or (CA >= AB + BC)) {
        throw std::logic_error("Triangle with these vertices doesn't exsist!");
    }
}

#endif