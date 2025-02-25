//
// Created by tallyboy on 1/31/25.
//

#ifndef VECTOR3D_HPP
#define VECTOR3D_HPP
#include <vector>


class Vector3d {
public:
    Vector3d();
    Vector3d(double p_x, double p_y, double p_z);
    Vector3d(const Vector3d& other);

    double x, y, z;
};



#endif //VECTOR3D_HPP
