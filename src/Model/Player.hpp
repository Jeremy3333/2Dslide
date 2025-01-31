//
// Created by tallyboy on 1/31/25.
//

#ifndef PLAYER_HPP
#define PLAYER_HPP
#include "Utils/Vector3d.hpp"


class Player {
public:
    Player();
    [[nodiscard]] Vector3d getPosition() const;
    [[nodiscard]] double getDirection() const;

    void rotate(double delta);
private:
    Vector3d _pos;
    double _dir;
};



#endif //PLAYER_HPP
