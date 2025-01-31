//
// Created by tallyboy on 1/31/25.
//

#ifndef OBJECT2D_HPP
#define OBJECT2D_HPP

#include "Vector2d.hpp"


class Object2D {
public:
    Object2D(const Vector2d &position, double direction);
    virtual ~Object2D() = default;

    [[nodiscard]] Vector2d getPosition() const;
    [[nodiscard]] double getDirection() const;
private:
    Vector2d _pos;
    double _dir;
};



#endif //OBJECT2D_HPP
