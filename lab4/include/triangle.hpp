#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "figure.hpp"

class Triangle final: public Figure {
public:
    explicit Triangle();
    explicit Triangle(Point2D<double> *poitns);
public:
    void input(std::istream &in) override;
    void print(std::ostream &out) const override;

    void validation() override;
};

Triangle::Triangle() : Figure(3) {
    vertices[0] = {0, 0};
    vertices[1] = {3, 0};
    vertices[2] = {0, 4};
    sort_vertices();
    validation();
}

Triangle::Triangle(Point2D<double> *points) : Figure(3) {
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i] = points[i];
    }
    sort_vertices();
    validation();
}

void Triangle::input(std::istream &in) {
    for (int i = 0; i < cnt_vertices; ++i) {
        in >> vertices[i];
    }
    sort_vertices();
    validation();
}

void Triangle::print(std::ostream &out) const {
    out << "Triangle:" << std::endl;
    for (int i = 0; i < cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << vertices[i] << std::endl;
    }
}

void Triangle::validation() {
    double AB = vertices[0].distance_to(vertices[1]);
    double BC = vertices[1].distance_to(vertices[2]);
    double CA = vertices[2].distance_to(vertices[0]);

    if ((AB >= BC + CA) or (BC >= AB + CA) or (CA >= AB + BC)) {
        throw std::logic_error("Triangle with these vertices doesn't exsist!");
    }
}

#endif