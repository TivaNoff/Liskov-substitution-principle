﻿#include <iostream>
#include <vector>
#include <memory>
#include <cmath>
#include <numbers>

constexpr double MY_PI = 3.14159265358979323846;


// Базовий інтерфейс для фігур
class IShape {
public:
    virtual ~IShape() = default;
    virtual double area() const = 0;
};

// Прямокутник
class Rectangle : public IShape {
public:
    Rectangle(double width, double height) : width_(width), height_(height) {}
    double area() const override {
        return width_ * height_;
    }
private:
    double width_;
    double height_;
};

// Коло
class Circle : public IShape {
public:
    explicit Circle(double radius) : radius_(radius) {}
    double area() const override {
        return MY_PI * radius_ * radius_;
    }
private:
    double radius_;
};

// Трикутник
class Triangle : public IShape {
public:
    Triangle(double base, double height) : base_(base), height_(height) {}
    double area() const override {
        return 0.5 * base_ * height_;
    }
private:
    double base_;
    double height_;
};

// Функція, яка обчислює сумарну площу довільної множини фігур
double totalArea(const std::vector<std::unique_ptr<IShape>>& shapes) {
    double total = 0.0;
    for (const auto& shape : shapes) {
        total += shape->area();
    }
    return total;
}

int main() {
    std::vector<std::unique_ptr<IShape>> shapes;
    shapes.push_back(std::make_unique<Rectangle>(4.0, 6.0));
    shapes.push_back(std::make_unique<Circle>(5.0));
    shapes.push_back(std::make_unique<Triangle>(3.0, 4.0));

    std::cout << "Total area of shapes: " << totalArea(shapes) << std::endl;

    return 0;
}