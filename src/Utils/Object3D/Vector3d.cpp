//
// Created by tallyboy on 1/31/25.
//

#include "Vector3d.hpp"

Vector3d::Vector3d() : x(0.0), y(0.0), z(0.0) {}

Vector3d::Vector3d(const double p_x, const double p_y, const double p_z) : x(p_x), y(p_y), z(p_z) {}

Vector3d::Vector3d(const Vector3d& other) = default;