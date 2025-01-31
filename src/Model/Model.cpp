//
// Created by tallyboy on 1/31/25.
//

#include "Model.hpp"

Model::Model() = default;

Vector3d Model::getPlayerPosition() const {
    return _player.getPosition();
}

double Model::getPlayerDirection() const {
    return _player.getDirection();
}

void Model::rotatePlayer(const double delta) {
    _player.rotate(delta);
}
