#include "triangle.hpp"

Triangle::Triangle() {
    vertices[0] = {0, 0};
    vertices[1] = {3, 0};
    vertices[2] = {0, 4};
    validation();
}

void Triangle::input(std::istream &in) {
    for (int i = 0; i < cnt_vertices; ++i) {
        in >> vertices[i];
    }
    validation();
}

void Triangle::print(std::ostream &out) const {
    out << "Triangle:" << std::endl;
    for (int i = 0; i < cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << vertices[i] << std::endl;
    }
}

Triangle::operator double() const noexcept {
    //return fabs((vertices[1].x - vertices[0].x) * (vertices[2].y - vertices[0].y) - (vertices[2].x - vertices[0].x) * (vertices[1].y - vertices[0].y)) / 2;
    double left_sum = 0, right_sum = 0;
    for (int i = 0; i < cnt_vertices - 1; ++i) {
        left_sum += vertices[i].x * vertices[i + 1].y;
        right_sum += vertices[i + 1].x * vertices[i].y;
    }
    return fabs(left_sum - right_sum) / 2;
}

Figure::Point2D Triangle::geometrical_center() const noexcept {
    Point2D center;
    for (int i = 0; i < cnt_vertices; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= cnt_vertices;
    center.y /= cnt_vertices;
    return center;
}

void Triangle::validation() {
    double AB = vertices[0].distance_to(vertices[1]);
    double BC = vertices[1].distance_to(vertices[2]);
    double CA = vertices[2].distance_to(vertices[0]);

    if ((AB >= BC + CA) or (BC >= AB + CA) or (CA >= AB + BC)) {
        throw std::logic_error("Triangle with these vertices doesn't exsist!");
    }
}

bool Triangle::operator == (Triangle &other) {
     for (int i = 0; i < cnt_vertices - 1; ++i) {
        if (vertices[i].distance_to(vertices[i + 1]) != other.vertices[i].distance_to(other.vertices[i + 1])) {
            return false;
        }
    }
    return true;
}

bool Triangle::operator != (Triangle &other) {
    return !(*this == other);
}