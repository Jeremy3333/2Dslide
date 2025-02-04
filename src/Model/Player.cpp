//
// Created by tallyboy on 1/31/25.
//

#include <cmath>

#include "Player.hpp"

Player::Player() :_dir(0), _rotationSpeed(1.5) {}

Vector3d Player::getPosition() const {
    return _pos;
}

double Player::getDirection() const {
    return _dir;
}

void Player::rotate(const double delta) {
    const double deltaSpeed = delta * _rotationSpeed;
    _dir = fmod(_dir + deltaSpeed, 2 * M_PI);
    if (_dir < 0) _dir += 2 * M_PI;
}
