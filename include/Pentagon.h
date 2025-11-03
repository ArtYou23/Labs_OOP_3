#ifndef PENTAGON_H
#define PENTAGON_H

#include "Figure.h"
#include <vector>
#include <utility>

class Pentagon : public Figure {
private:
    std::vector<std::pair<double, double>> vertices; 

public:
    Pentagon() = default;
    Pentagon(const std::vector<std::pair<double, double>>& points);

    std::pair<double, double> calculateGeometricCenter() const override;

    explicit operator double() const override; 

    bool operator==(const Figure& other) const override;

    void print(std::ostream& os) const override;
    void read(std::istream& is) override;
};

#endif