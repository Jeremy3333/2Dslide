//
// Created by tallyboy on 1/31/25.
//

#ifndef VECTOR2D_HPP
#define VECTOR2D_HPP
#include <vector>


class Vector2d {
public:
    Vector2d();
    Vector2d(double p_x, double p_y);
    Vector2d(const Vector2d& other);

    static Vector2d mean(const std::vector<Vector2d>& vectors);

    bool operator==(const Vector2d &other) const;
    Vector2d operator+(const Vector2d& a) const;
    Vector2d operator/(double p_x) const;
    void operator+=(const Vector2d &other);

    double x, y;
};



#endif //VECTOR2D_HPP
