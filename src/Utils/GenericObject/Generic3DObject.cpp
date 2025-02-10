//
// Created by tallyboy on 2/10/25.
//

#include "Generic3DObject.hpp"

#include <algorithm>

#include "Utils/Utils.hpp"

Generic3DObject::Generic3DObject(const Vector3d& min, const Vector3d& max) {
    // add the 8 vertices
    _vertices.push_back(min);
    _vertices.emplace_back(min.x, min.y, max.z);
    _vertices.emplace_back(min.x, max.y, min.z);
    _vertices.emplace_back(min.x, max.y, max.z);
    _vertices.emplace_back(max.x, min.y, min.z);
    _vertices.emplace_back(max.x, min.y, max.z);
    _vertices.emplace_back(max.x, max.y, min.z);
    _vertices.push_back(max);
    // add the faces
    // bot
    _faces.emplace_back(0, 4, 1);
    _faces.emplace_back(5, 4, 1);
    // top
    _faces.emplace_back(7, 6, 3);
    _faces.emplace_back(2, 6, 3);
    // back
    _faces.emplace_back(0, 4, 6);
    _faces.emplace_back(0, 2, 6);
    // front
    _faces.emplace_back(7, 3, 4);
    _faces.emplace_back(1, 3, 4);
    // left
    _faces.emplace_back(0, 1, 2);
    _faces.emplace_back(3, 1, 2);
    // right
    _faces.emplace_back(7, 6, 5);
    _faces.emplace_back(4, 6, 5);
}

bool Generic3DObject::isClosed() {
    return _vertices.size() - countEdge() + _faces.size() == 2;
}

std::unique_ptr<Generic2Dobject> Generic3DObject::getCut(const double ang, const Vector2d &origin) const{
    std::vector<Vector2d> vertices;
    std::vector<std::pair<double, double>> edges;
    bool hit = false;

    for (const auto face : _faces) {
        const Vector3d coord[3] = {_vertices[face.p1], _vertices[face.p2], _vertices[face.p3]};

        if (
            std::pair<Vector2d, Vector2d> seg;
            collisionFacePlane(coord, origin, ang, seg)
            ) {
            hit = true;
            auto foundA = std::ranges::find(vertices, seg.first);
            int indexA = static_cast<int>(std::distance(vertices.begin(), foundA));
            if (foundA == vertices.end()) {
                vertices.push_back(seg.first);
                indexA = static_cast<int>(vertices.size()) - 1;
            }
            auto foundB = std::ranges::find(vertices, seg.second);
            int indexB = static_cast<int>(std::distance(vertices.begin(), foundB));
            if (foundB == vertices.end()) {
                vertices.push_back(seg.second);
                indexB = static_cast<int>(vertices.size()) - 1;
            }
            edges.emplace_back(indexA, indexB);
        }
    }
    if (hit)
        return std::make_unique<Generic2Dobject>(vertices, edges);
    return nullptr;
}


int Generic3DObject::countEdge() {
    std::vector<std::pair<int, int>> edges;
    int count = 0;
    for (auto face : _faces) {
        if(std::ranges::find(edges, std::pair(face.p1, face.p2)) == edges.end() ||
        std::ranges::find(edges, std::pair(face.p2, face.p1)) == edges.end()
            ) {
            count++;
            edges.emplace_back(face.p1, face.p2);
        }
        if(std::ranges::find(edges, std::pair(face.p1, face.p3)) == edges.end() ||
        std::ranges::find(edges, std::pair(face.p3, face.p1)) == edges.end()) {
            count++;
            edges.emplace_back(face.p1, face.p3);
        }
        if(std::ranges::find(edges, std::pair(face.p3, face.p2)) == edges.end() ||
        std::ranges::find(edges, std::pair(face.p2, face.p3)) == edges.end()) {
            count++;
            edges.emplace_back(face.p3, face.p2);
        }
    }
    return count;
}
