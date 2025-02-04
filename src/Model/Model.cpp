//
// Created by tallyboy on 1/31/25.
//

#include "Model.hpp"
#include "Utils/Object3D/Cube.hpp"

Model::Model() {
    _objects.push_back(std::make_unique<Cube>(Vector3d(0, -1, 0), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(0, -1, 1), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(0, -1, -1), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(1, -1, 0), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(1, -1, 1), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(1, -1, -1), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(-1, -1, 0), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(-1, -1, 1), Vector2d(), 1));
    _objects.push_back(std::make_unique<Cube>(Vector3d(-1, -1, -1), Vector2d(), 1));
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
