#include "octagon.hpp"
#include <algorithm>

/*bool cmp_for_bypass (Figure::Point2D const &a, Figure::Point2D const &b) {
    return a.vect(b) > 0;
}*/

/*bool cmp (Figure::Point2D const &a, Figure::Point2D const &b) {
    if (a.y != b.y) {
        return a.y < b.y;
    }
    return a.x < b.x;
}*/

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

Octagon::operator double() const noexcept {
    double left_sum = 0, right_sum = 0;
    for (int i = 0; i < cnt_vertices; ++i) {
        left_sum += vertices[i % cnt_vertices].x * vertices[(i + 1) % cnt_vertices].y;
        right_sum += vertices[(i + 1) % cnt_vertices].x * vertices[i % cnt_vertices].y;
    }
    return fabs(left_sum - right_sum) / 2;
}

Figure::Point2D Octagon::geometrical_center() const noexcept {
    Point2D center;
    for (int i = 0; i < cnt_vertices; ++i) {
        center.x += vertices[i].x;
        center.y += vertices[i].y;
    }
    center.x /= cnt_vertices;
    center.y /= cnt_vertices;
    return center;
}

void Octagon::validation() {
    for (int i = 0; i < cnt_vertices - 2; ++i) {
        double signed_area = (vertices[i + 1].x - vertices[i].x) * (vertices[i + 2].y - vertices[i].y) - (vertices[i + 1].y - vertices[i].y) * (vertices[i + 2].x - vertices[i].x);
        if (signed_area <= 0) {
            throw std::logic_error("Convex octagon with these vertices doesn't exsist!");
        }
    }
    
}

bool Octagon::operator == (Octagon &other) {
    for (int i = 0; i < cnt_vertices - 1; ++i) {
        if (vertices[i].distance_to(vertices[i + 1]) != other.vertices[i].distance_to(other.vertices[i + 1])) {
            return false;
        }
    }
    return true;
}

bool Octagon::operator != (Octagon &other) {
    return !(*this == other);
}