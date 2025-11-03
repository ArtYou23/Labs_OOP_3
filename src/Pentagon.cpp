#include "../include/Pentagon.h"
#include <cmath>

std::pair<double, double> Pentagon::calculateGeometricCenter() const {
    double x_center = 0, y_center = 0;
    for (const auto &pair : vertices) {
        x_center += pair.first;
        y_center += pair.second;
    }
    x_center /= 5;
    y_center /= 5;
    return {x_center, y_center};
}

Pentagon::operator double() const {
    double area = 0;
    int n = vertices.size(); // n = 5
    for (int i = 0; i < n; ++i) {
        int j = (i + 1) % n;
        area += vertices[i].first * vertices[j].second;
        area -= vertices[j].first * vertices[i].second;
    }
    return std::fabs(area) / 2;
}

Pentagon::Pentagon(const std::vector<std::pair<double, double>> &points) : vertices(points) {}

bool Pentagon::operator==(const Figure& other) const { 
    if (typeid(other) != typeid(*this)) {
        return false;
    }
    const Pentagon &otherPentagon = static_cast<const Pentagon&>(other);
    
    return vertices == otherPentagon.vertices;
}

void Pentagon::print(std::ostream &os) const {
    os << "Pentagon: ";
    for (const auto &vertex : vertices) {
        os << "(" << vertex.first << "," << vertex.second << ") ";
    }
}

void Pentagon::read(std::istream &is) {
    vertices.clear();
    for (int i = 0; i < 5; ++i) {
        double x, y;
        is >> x >> y;
        vertices.push_back({x, y});
    }
}