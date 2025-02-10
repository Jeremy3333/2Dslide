//
// Created by tallyboy on 1/31/25.
//

#ifndef MODEL_HPP
#define MODEL_HPP

#include <vector>

#include "Player.hpp"
#include "Utils/GenericObject/Generic3DObject.hpp"

class Model {
public:
    Model();

    [[nodiscard]] Vector3d getPlayerPosition() const;
    [[nodiscard]] double getPlayerDirection() const;

    [[nodiscard]] const std::vector<Generic3DObject>& getObjects() const;

    void rotatePlayer(double delta);

private:
    Player _player;
    std::vector<Generic3DObject> _objects;
};



#endif //MODEL_HPP
