//
// Created by tallyboy on 1/31/25.
//

#include "Object2D.hpp"

Object2D::Object2D(const Vector2d &position, const double direction) : _pos(position), _dir(direction) {}

Vector2d Object2D::getPosition() const {
    return _pos;
}

double Object2D::getDirection() const {
    return _dir;
}
