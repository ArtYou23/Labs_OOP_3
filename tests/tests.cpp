#include <gtest/gtest.h>
#include <vector>
#include <cmath>
#include "../include/Trapezoid.h"
#include "../include/Rhombus.h"
#include "../include/Pentagon.h"

// Вспомогательная функция для сравнения double с допуском
bool doubleEquals(double a, double b, double epsilon = 1e-6) {
    return std::fabs(a - b) < epsilon;
}

// Тест 1: Создание и базовые операции трапеции
TEST(TrapezoidTest, BasicOperations) {
    std::vector<std::pair<double, double>> points = {{0,0}, {4,0}, {3,2}, {1,2}};
    Trapezoid trapezoid(points);
    
    auto center = trapezoid.calculateGeometricCenter();
    EXPECT_TRUE(doubleEquals(center.first, 2.0));
    EXPECT_TRUE(doubleEquals(center.second, 1.0));
    EXPECT_TRUE(doubleEquals(static_cast<double>(trapezoid), 6.0));
}

// Тест 2: Сравнение трапеций
TEST(TrapezoidTest, Equality) {
    std::vector<std::pair<double, double>> points1 = {{0,0}, {4,0}, {3,2}, {1,2}};
    std::vector<std::pair<double, double>> points2 = {{0,0}, {4,0}, {3,2}, {1,2}};
    std::vector<std::pair<double, double>> points3 = {{0,0}, {5,0}, {4,2}, {1,2}};
    
    Trapezoid trap1(points1);
    Trapezoid trap2(points2);
    Trapezoid trap3(points3);
    
    EXPECT_TRUE(trap1 == trap2);
    EXPECT_FALSE(trap1 == trap3);
}

// Тест 3: Площадь ромба
TEST(RhombusTest, AreaCalculation) {
    std::vector<std::pair<double, double>> points = {{0,0}, {2,2}, {4,0}, {2,-2}};
    Rhombus rhombus(points);
    
    // Площадь ромба с диагоналями 4 и 4 = (4*4)/2 = 8
    EXPECT_TRUE(doubleEquals(static_cast<double>(rhombus), 8.0));
}

// Тест 4: Центр ромба
TEST(RhombusTest, GeometricCenter) {
    std::vector<std::pair<double, double>> points = {{1,1}, {2,2}, {3,1}, {2,0}};
    Rhombus rhombus(points);
    
    auto center = rhombus.calculateGeometricCenter();
    EXPECT_TRUE(doubleEquals(center.first, 2.0));
    EXPECT_TRUE(doubleEquals(center.second, 1.0));
}

// Тест 5: Площадь пятиугольника
TEST(PentagonTest, AreaCalculation) {
    std::vector<std::pair<double, double>> points = {{0,0}, {2,1}, {3,3}, {1,4}, {-1,2}};
    Pentagon pentagon(points);
    
    EXPECT_TRUE(doubleEquals(static_cast<double>(pentagon), 9.0));
}

// Тест 6: Сравнение разных типов фигур
TEST(FigureTest, DifferentTypeComparison) {
    std::vector<std::pair<double, double>> trapPoints = {{0,0}, {4,0}, {3,2}, {1,2}};
    std::vector<std::pair<double, double>> rhombusPoints = {{0,0}, {2,2}, {4,0}, {2,-2}};
    
    Trapezoid trapezoid(trapPoints);
    Rhombus rhombus(rhombusPoints);
    
    EXPECT_FALSE(trapezoid == rhombus);
    EXPECT_FALSE(rhombus == trapezoid);
}

// Тест 7: Общая площадь через массив
TEST(FigureManagerTest, TotalArea) {
    std::vector<Figure*> figures;
    
    Trapezoid* trap = new Trapezoid({{0,0}, {4,0}, {3,2}, {1,2}});      // площадь 6
    Rhombus* rhombus = new Rhombus({{0,0}, {2,2}, {4,0}, {2,-2}});      // площадь 8
    Pentagon* pentagon = new Pentagon({{0,0}, {2,1}, {3,3}, {1,4}, {-1,2}}); // площадь 9
    
    figures.push_back(trap);
    figures.push_back(rhombus);
    figures.push_back(pentagon);
    
    double totalArea = 0.0;
    for (const auto& figure : figures) {
        totalArea += static_cast<double>(*figure);
    }
    
    EXPECT_TRUE(doubleEquals(totalArea, 23.0));
    
    // Очистка памяти
    for (auto figure : figures) {
        delete figure;
    }
}

// Тест 8: Удаление из массива
TEST(FigureManagerTest, RemoveFromArray) {
    std::vector<Figure*> figures;
    
    Trapezoid* trap = new Trapezoid({{0,0}, {4,0}, {3,2}, {1,2}});      // площадь 6
    Rhombus* rhombus = new Rhombus({{0,0}, {2,2}, {4,0}, {2,-2}});      // площадь 8
    
    figures.push_back(trap);
    figures.push_back(rhombus);
    
    // Удаляем первый элемент
    delete figures[0];
    figures.erase(figures.begin());
    
    EXPECT_EQ(figures.size(), 1);
    
    // Очистка памяти
    for (auto figure : figures) {
        delete figure;
    }
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}