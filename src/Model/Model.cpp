//
// Created by tallyboy on 1/31/25.
//

#include "Model.hpp"

#include <iostream>

Model::Model() {
    _objects.push_back(Generic3DObject({-30, -10, -10}, {-10, 10, 10}));
    _objects.push_back(Generic3DObject({-10, -10, -10}, {10, 10, 10}));
    _objects.push_back(Generic3DObject({10, -10, -10}, {30, 10, 10}));
    _objects.push_back(Generic3DObject({-30, -10, -30}, {-10, 10, -10}));
    _objects.push_back(Generic3DObject({-10, -10, -30}, {10, 10, -10}));
    _objects.push_back(Generic3DObject({10, -10, -30}, {30, 10, -10}));
    _objects.push_back(Generic3DObject({-30, -10, 10}, {-10, 10, 30}));
    _objects.push_back(Generic3DObject({-10, -10, 10}, {10, 10, 30}));
    _objects.push_back(Generic3DObject({10, -10, 10}, {30, 10, 30}));
    for (auto object : _objects) {
        if (!object.isClosed()) {
            std::cerr << "An Object isn't closed" << std::endl;
            exit(1);
        }
    }
}

Vector3d Model::getPlayerPosition() const {
    return _player.getPosition();
}

double Model::getPlayerDirection() const {
    return _player.getDirection();
}

const std::vector<Generic3DObject> &Model::getObjects() const {
    return _objects;
}


void Model::rotatePlayer(const double delta) {
    _player.rotate(delta);
}
