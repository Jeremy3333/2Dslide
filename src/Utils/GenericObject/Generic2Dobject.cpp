//
// Created by tallyboy on 2/10/25.
//

#include "Generic2Dobject.hpp"


Generic2Dobject::Generic2Dobject() = default;

Generic2Dobject::Generic2Dobject(
    const std::vector<Vector2d> &p_vertices,
    const std::vector<std::pair<double, double> > &p_edges
    ) : _vertices(p_vertices), _edges(p_edges) {}


void Generic2Dobject::setVertices(const std::vector<Vector2d> &p_vertices) {
    _vertices = p_vertices;
}

void Generic2Dobject::setEdges(const std::vector<std::pair<double, double> > &p_edges) {
    _edges = p_edges;
}

void Generic2Dobject::getTriangles(std::vector<Vector2d> &vertices, std::vector<std::array<int, 3>>& triangles) {
    vertices.clear();
    triangles.clear();
    if (_vertices.size() <= 2)
        return;
    vertices = _vertices;
    if (_vertices.size() == 3) {
        constexpr std::array tri = {0, 1, 2};
        triangles.push_back(tri);
        return;
    }
    vertices.push_back(Vector2d::mean(_vertices));
    const int centerIndex = static_cast<int>(vertices.size()) - 1;
    for (const auto&[fst, snd] : _edges) {
        std::array tri = {centerIndex, static_cast<int>(fst), static_cast<int>(snd)};
        triangles.push_back(tri);
    }
}

const std::vector<std::pair<double, double> > &Generic2Dobject::getEdges() {
    return _edges;
}

const std::vector<Vector2d> &Generic2Dobject::getVertices() {
    return _vertices;
}
