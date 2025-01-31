//
// Created by tallyboy on 1/31/25.
//

#ifndef CUBE_HPP
#define CUBE_HPP

#include "Object3D.hpp"


class Cube final : public Object3D {
public:
    Cube(const Vector3d &position, const Vector2d& direction, double size);
    ~Cube() override = default;

    [[nodiscard]] double getSize() const;
    [[nodiscard]] std::unique_ptr<Object2D> getCut(double ang, const Vector2d& centre) const override;
private:
    double size_;
};



#endif //CUBE_HPP
