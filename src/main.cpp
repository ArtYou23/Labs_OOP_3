#include <iostream>
#include <string>
#include <vector>
#include <memory>
#include "../include/Figure.h"
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/Pentagon.h"

class FigureManager {
    private:
        std::vector<Figure*> figures; 

    public:
        void addFigure(Figure* figure) {
            figures.push_back(figure);
        }

        void printAllFigures() const {
            for (size_t i = 0; i < figures.size(); ++i) {
                std::cout << "Figure " << i << ": " << *figures[i] << std::endl;
                auto center = figures[i]->calculateGeometricCenter();
                double area = static_cast<double>(*figures[i]);
                std::cout << "  Center: (" << center.first << ", " << center.second << ")" << std::endl;
                std::cout << "  Area: " << area << std::endl << std::endl;
            }
        }

        double calculateTotalArea() const {
            double total = 0;
            for (const auto &figure : figures) {
                total += static_cast<double>(*figure);
            }
            return total;
        }

        bool removeFigure(int index) {
            if (index >= 0 && index < static_cast<int>(figures.size())) {
                delete figures[index]; 
                figures.erase(figures.begin() + index);
                return true;
            }
            return false;
        }

        ~FigureManager() {
            for (auto figure : figures) {
                delete figure;
            }
        }
};

int main() {
    FigureManager manager;
    
    std::cout << "=== Figure Manager Test ===" << std::endl;

    // Создаём несколько фигур
    Trapezoid* trap = new Trapezoid({{0,0}, {4,0}, {3,2}, {1,2}});
    Rhombus* rhombus = new Rhombus({{0,0}, {2,2}, {4,0}, {2,-2}});
    Pentagon* pentagon = new Pentagon({{0,0}, {2,1}, {3,3}, {1,4}, {-1,2}});

    // Добавляем в массив
    manager.addFigure(trap);
    manager.addFigure(rhombus);
    manager.addFigure(pentagon);

    // Тестируем функции
    std::cout << "All figures:" << std::endl;
    manager.printAllFigures();

    std::cout << "Total area: " << manager.calculateTotalArea() << std::endl;

    // Удаляем одну фигуру
    std::cout << "\nRemoving figure at index 1..." << std::endl;
    manager.removeFigure(1);

    std::cout << "After removal:" << std::endl;
    manager.printAllFigures();
    std::cout << "Total area after removal: " << manager.calculateTotalArea() << std::endl;

    return 0;
}