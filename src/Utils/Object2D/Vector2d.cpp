//
// Created by tallyboy on 1/31/25.
//

#include "Vector2d.hpp"

Vector2d::Vector2d() : x(0.0), y(0.0) {}

Vector2d::Vector2d(const double p_x, const double p_y) : x(p_x), y(p_y) {}

Vector2d::Vector2d(const Vector2d &other) = default;
