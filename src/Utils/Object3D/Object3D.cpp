//
// Created by tallyboy on 1/31/25.
//

#include "Object3D.hpp"

Object3D::Object3D(const Vector3d &position, const Vector2d& direction) : _pos(position), _dir(direction) {}

Vector3d Object3D::getPosition() const {
    return _pos;
}

Vector2d Object3D::getDirection() const {
    return _dir;
}