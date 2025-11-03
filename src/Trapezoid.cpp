#include "../include/Trapezoid.h"
#include <cmath>

std::pair<double, double> Trapezoid::calculateGeometricCenter() const {
    double x_center = 0, y_center = 0;
    for (const auto &pair : vertices) {
        x_center += pair.first;
        y_center += pair.second;
    }
    x_center /= 4;
    y_center /= 4;
    return {x_center, y_center};
}

Trapezoid::operator double() const {
    double area = 0;
    int n = vertices.size();
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return std::fabs(area) / 2;
}

Trapezoid::Trapezoid(const std::vector<std::pair<double, double>> &points) : vertices(points) {}

bool Trapezoid::operator==(const Figure& other) const { 
    if (typeid(other) != typeid(*this)) {
        return false;
    }
    const Trapezoid &otherTrapezoid = static_cast<const Trapezoid&>(other);
    
    return vertices == otherTrapezoid.vertices;
}

void Trapezoid::print(std::ostream &os) const {
    os << "Trapezoid: ";
    for (const auto &vertex : vertices) {
        os << "(" << vertex.first << "," << vertex.second << ") ";
    }
}

void Trapezoid::read(std::istream &is) {
    vertices.clear();
    for (int i = 0; i < 4; ++i) {
        double x, y;
        is >> x >> y;
        vertices.push_back({x, y});
    }
}