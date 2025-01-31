//
// Created by tallyboy on 1/31/25.
//

#include <cmath>

#include "Cube.hpp"

#include "Utils/Utils.hpp"
#include "Utils/Object2D/Rectangle.hpp"

Cube::Cube(const Vector3d &position, const Vector2d& direction, const double size) : Object3D(position, direction), size_(size) {}

double Cube::getSize() const {
    return size_;
}

std::unique_ptr<Object2D> Cube::getCut(const double ang, const Vector2d& centre) const {
    double x;
    double width;
    if (!collisionRectLine(Vector2d(_pos.x, _pos.z), Vector2d(size_, size_), centre, ang, x, width)) {
        return nullptr;
    }
    Vector2d pos(x, _pos.y);
    double dir = _dir.x * cos(ang) + _dir.y * sin(ang);
    double height = size_;
    return std::make_unique<Rectangle>(pos, dir, width, height);
}