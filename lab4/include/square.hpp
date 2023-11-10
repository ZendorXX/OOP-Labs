#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "figure.hpp"

template <class T>
class Square final : public Figure<T> {
public:
    explicit Square();
    explicit Square(std::shared_ptr< Point2D<T>> points);
public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

template <class T>
Square<T>::Square() : Figure<T>(4) {
    this->vertices[0] = {0, 0};
    this->vertices[1] = {1, 0};
    this->vertices[2] = {1, 1};
    this->vertices[3] = {0, 1};
    //sort_vertices();
    validation();
}

template <class T>
Square<T>::Square(std::shared_ptr<Point2D<T>> points) : Figure<T>(4) {
    for (int i = 0; i < this->cnt_vertices; ++i) {
        this->vertices[i] = points[i];
    }
    //sort_vertices();
    validation();
}

template <class T>
void Square<T>::input(std::istream &in) {
    for (int i = 0; i < this->cnt_vertices; ++i) {
        in >> this->vertices[i];
    }
    //sort_vertices();
    validation();
}

template <class T>
void Square<T>::print(std::ostream &out) const {
    out << "Square:" << std::endl;
    for (int i = 0; i < this->cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << this->vertices[i] << std::endl;
    }
}

template <class T>
void Square<T>::validation() {
    double AB = this->vertices[0].distance_to(this->vertices[1]);
    double AC = this->vertices[0].distance_to(this->vertices[2]);
    double AD = this->vertices[0].distance_to(this->vertices[3]);

    if (!(AB - AD < eps and AC - sqrt(2) * AB < eps)) {
        throw std::logic_error("Square with these vertices doesn't exsist!");
    }
}

#endif