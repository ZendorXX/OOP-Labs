#include "octagon.hpp"

Octagon::Octagon() : Figure(8) {
    vertices[0] = {0, 0};
    vertices[1] = {1, 0};
    vertices[2] = {2, 1};
    vertices[3] = {2, 2};
    vertices[4] = {1, 3};
    vertices[5] = {0, 3};
    vertices[6] = {-1, 2};
    vertices[7] = {-1, 1};
    validation();
}

Octagon::Octagon(Point2D *points) : Figure(8) {
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i] = points[i];
    }
    sort_vertices();
    validation();
}

void Octagon::input(std::istream &in) {
    for (int i = 0; i < cnt_vertices; ++i) {
        in >> vertices[i];
    }
    sort_vertices();
    validation();
}

void Octagon::print(std::ostream &out) const {
    out << "Octagon:" << std::endl;
    for (int i = 0; i < cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << vertices[i] << std::endl;
    }
}

void Octagon::validation() {
    for (int i = 0; i < cnt_vertices - 2; ++i) {
        double signed_area = (vertices[i + 1].x - vertices[i].x) * (vertices[i + 2].y - vertices[i].y) - (vertices[i + 1].y - vertices[i].y) * (vertices[i + 2].x - vertices[i].x);
        if (signed_area <= 0) {
            throw std::logic_error("Convex octagon with these vertices doesn't exsist!");
        }
    }
    
}