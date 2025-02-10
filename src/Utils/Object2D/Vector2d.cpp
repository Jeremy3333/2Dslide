//
// Created by tallyboy on 1/31/25.
//

#include "Vector2d.hpp"

Vector2d::Vector2d() : x(0.0), y(0.0) {}

Vector2d::Vector2d(const double p_x, const double p_y) : x(p_x), y(p_y) {}

Vector2d::Vector2d(const Vector2d &other) = default;


Vector2d Vector2d::operator/(const double p_x) const {
    return {x / p_x, y / p_x};
}

Vector2d Vector2d::mean(const std::vector<Vector2d>& vectors) {
    Vector2d a;
    for (const auto& vector : vectors) {
        a += vector;
    }
    return (a / static_cast<double>(vectors.size()));
}


bool Vector2d::operator==(const Vector2d &other) const {
    return other.x == x && other.y == y;
}

Vector2d Vector2d::operator+(const Vector2d &a) const {
    return {this->x + a.x, this->y + a.y};
}

void Vector2d::operator+=(const Vector2d &other) {
    x += other.x;
    y += other.y;
}

