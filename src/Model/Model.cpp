//
// Created by tallyboy on 1/31/25.
//

#include "Model.hpp"
#include "Utils/Object3D/Cube.hpp"

Model::Model() {
    _objects.push_back(std::make_unique<Cube>(Vector3d(0, -20, 0), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(0, -20, 20), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(0, -20, -20), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(20, -20, 0), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(20, -20, 20), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(20, -20, -20), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(-20, -20, 0), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(-20, -20, 20), Vector2d(), 20));
    _objects.push_back(std::make_unique<Cube>(Vector3d(-20, -20, -20), Vector2d(), 20));
}

Vector3d Model::getPlayerPosition() const {
    return _player.getPosition();
}

double Model::getPlayerDirection() const {
    return _player.getDirection();
}

const std::vector<std::unique_ptr<Object3D>>& Model::getObjects() const{
    return _objects;
}

void Model::rotatePlayer(const double delta) {
    _player.rotate(delta);
}
