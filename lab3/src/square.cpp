#include "square.hpp"
#include <algorithm>

/*bool cmp (Figure::Point2D const &a, Figure::Point2D const &b) {
    return (a.x * b.y - a.y * b.x) > 0;
}*/

Square::Square() : Figure(4) {
    vertices[0] = {0, 0};
    vertices[1] = {1, 0};
    vertices[2] = {1, 1};
    vertices[3] = {0, 1};
    //std::sort(vertices, vertices + cnt_vertices, cmp);
    validation();
}

void Square::input(std::istream &in) {
    for (int i = 0; i < cnt_vertices; ++i) {
        in >> vertices[i];
    }

    double move_x = vertices[0].x, move_y = vertices[0].y;
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i].x -= move_x;
        vertices[i].y -= move_y;
    }
    //std::sort(vertices, vertices + cnt_vertices, cmp);
    for (int i = 0; i < cnt_vertices; ++i) {
        vertices[i].x += move_x;
        vertices[i].y += move_y;
    }
    
    validation();
}

void Square::print(std::ostream &out) const {
    out << "Square:" << std::endl;
    for (int i = 0; i < cnt_vertices; ++i) {
        out << " " << i + 1 << " point: " << vertices[i] << std::endl;
    }
}

Square::operator double() const noexcept {
    return vertices[0].distance_to(vertices[1]) * vertices[0].distance_to(vertices[1]);
}

Figure::Point2D Square::geometrical_center() const noexcept {
    Point2D center;
    for (int i = 0; i < cnt_vertices; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= cnt_vertices;
    center.y /= cnt_vertices;
    return center;
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