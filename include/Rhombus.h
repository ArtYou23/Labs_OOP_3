#ifndef RHOMBUS_H
#define RHOMBUS_H

#include "Figure.h"
#include <vector>
#include <utility>

class Rhombus : public Figure {
private:
    std::vector<std::pair<double, double>> vertices;

public:
    Rhombus() = default;
    Rhombus(const std::vector<std::pair<double, double>>& points);

    std::pair<double, double> calculateGeometricCenter() const override;

    explicit operator double() const override;

    bool operator==(const Figure& other) const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif