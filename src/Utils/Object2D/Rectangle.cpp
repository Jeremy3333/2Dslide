//
// Created by tallyboy on 1/31/25.
//

#include "Rectangle.hpp"

Rectangle::Rectangle(const Vector2d &position, const double direction, const double width, const double height)
    : Object2D(position, direction), width_(width), height_(height) {}

double Rectangle::getWidth() const {
    return width_;
}

double Rectangle::getHeight() const {
    return height_;
}