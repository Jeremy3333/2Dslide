//
// Created by tallyboy on 2/10/25.
//

#ifndef GENERIC2DOBJECT_HPP
#define GENERIC2DOBJECT_HPP

#include <vector>
#include <array>

#include "Utils/Object2D/Vector2d.hpp"

class Generic2Dobject {
public:
    Generic2Dobject();
    Generic2Dobject(const std::vector<Vector2d>& p_vertices, const std::vector<std::pair<double, double>>& p_edges);
    void setVertices(const std::vector<Vector2d>& p_vertices);
    void setEdges(const std::vector<std::pair<double, double>>& p_edges);
    void getTriangles(std::vector<Vector2d>& vertices, std::vector<std::array<int, 3>>& triangles);
    const std::vector<std::pair<double, double>>& getEdges();
    const std::vector<Vector2d>& getVertices();
private:
    std::vector<Vector2d> _vertices;
    std::vector<std::pair<double, double>> _edges;
};



#endif //GENERIC2DOBJECT_HPP
