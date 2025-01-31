//
// Created by tallyboy on 1/31/25.
//

#ifndef MODEL_HPP
#define MODEL_HPP

#include "Player.hpp"
#include "Utils/Vector3d.hpp"

class Model {
public:
    Model();

    [[nodiscard]] Vector3d getPlayerPosition() const;
    [[nodiscard]] double getPlayerDirection() const;

    void rotatePlayer(double delta);

private:
    Player _player;
};



#endif //MODEL_HPP
