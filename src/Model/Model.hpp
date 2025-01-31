//
// Created by tallyboy on 1/31/25.
//

#ifndef MODEL_HPP
#define MODEL_HPP

#include <memory>
#include <vector>

#include "Player.hpp"
#include "Utils/Object3D/Object3D.hpp"

class Model {
public:
    Model();

    [[nodiscard]] Vector3d getPlayerPosition() const;
    [[nodiscard]] double getPlayerDirection() const;

    [[nodiscard]] const std::vector<std::unique_ptr<Object3D>>& getObjects() const;

    void rotatePlayer(double delta);

private:
    Player _player;
    std::vector<std::unique_ptr<Object3D>> _objects;
};



#endif //MODEL_HPP
