//
// Created by tallyboy on 1/31/25.
//

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "Object2D.hpp"


class Rectangle final : public Object2D {
public:
    Rectangle(const Vector2d &position, double direction, double width, double height);
    ~Rectangle() override = default;

    [[nodiscard]] double getWidth() const;
    [[nodiscard]] double getHeight() const;
private:
    double width_;
    double height_;
};



#endif //RECTANGLE_HPP
