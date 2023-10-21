#include "square.hpp"
#include <algorithm>

Square::Square() : Figure(4) {
    vertices[0] = {0, 0};
    vertices[1] = {1, 0};
    vertices[2] = {1, 1};
    vertices[3] = {0, 1};
    sort_vertices();
    validation();
}

void Square::input(std::istream &in) {
    for (int i = 0; i < cnt_vertices; ++i) {
        in >> vertices[i];
    }
    sort_vertices();
    validation();
}

void Square::print(std::ostream &out) const {
    out << "Square:" << std::endl;
    for (int i = 0; i < cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << vertices[i] << std::endl;
    }
}

void Square::validation() {
    double AB = vertices[0].distance_to(vertices[1]);
    double AC = vertices[0].distance_to(vertices[2]);
    double AD = vertices[0].distance_to(vertices[3]);

    if (!(AB - AD < eps and AC - sqrt(2) * AB < eps)) {
        throw std::logic_error("Square with these vertices doesn't exsist!");
    }
}

bool Square::operator == (Square &other) {
    if (vertices[0].distance_to(vertices[1]) == other.vertices[0].distance_to(other.vertices[1])) {
        return true;
    }
    return false;
}

bool Square::operator != (Square &other) {
    return !(*this == other);
}