//
// Created by tallyboy on 1/31/25.
//

#ifndef OBJECT3D_HPP
#define OBJECT3D_HPP
#include <memory>

#include "Vector3d.hpp"
#include "Utils/Object2D/Object2D.hpp"
#include "Utils/Object2D/Vector2d.hpp"


class Object3D {
public:
    Object3D(const Vector3d &position, const Vector2d& direction);
    virtual ~Object3D() = default;

    [[nodiscard]] Vector3d getPosition() const;
    [[nodiscard]] Vector2d getDirection() const;
    [[nodiscard]] virtual std::unique_ptr<Object2D> getCut(double ang, const Vector2d& origin) const = 0;
protected:
    Vector3d _pos;
    Vector2d _dir;
};



#endif //OBJECT3D_HPP
