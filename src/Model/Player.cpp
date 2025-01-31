//
// Created by tallyboy on 1/31/25.
//

#include <cmath>

#include "Player.hpp"

Player::Player() : _dir(0) {}

Vector3d Player::getPosition() const {
    return _pos;
}

double Player::getDirection() const {
    return _dir;
}

void Player::rotate(const double delta) {
    _dir = fmod(_dir + delta, 2 * M_PI);
    if (_dir < 0) _dir += 2 * M_PI;
}
