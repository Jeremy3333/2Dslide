//
// Created by tallyboy on 1/31/25.
//

#include "Utils.hpp"

#include <cmath>

double pointLineProjection(const Vector2d& P, const Vector2d& linePos, double lineAng) {
    double dx = std::cos(lineAng);
    double dy = std::sin(lineAng);
    return (P.x - linePos.x) * dx + (P.y - linePos.y) * dy;
}
/*
bool collisionSegLine(const Vector2d& A, const Vector2d& B, const Vector2d& linePos, double lineAng, double& intersectionDist) {
    double dx = std::cos(lineAng);
    double dy = std::sin(lineAng);

    double detA = (A.x - linePos.x) * dy - (A.y - linePos.y) * dx;
    double detB = (B.x - linePos.x) * dy - (B.y - linePos.y) * dx;

    if (detA * detB > 0) return false;

    double t = detA / (detA - detB);
    Vector2d intersection = {A.x + t * (B.x - A.x), A.y + t * (B.y - A.y)};

    intersectionDist = pointLineProjection(intersection, linePos, lineAng);
    return true;
}

bool collisionRectLine(const Vector2d& rectPos, const Vector2d& rectSize, const Vector2d& linePos, double lineAng, double& firstHitDist, double& entryExitDist) {
    Vector2d corners[4] = {
        {rectPos.x, rectPos.y},
        {rectPos.x + rectSize.x, rectPos.y},
        {rectPos.x + rectSize.x, rectPos.y + rectSize.y},
        {rectPos.x, rectPos.y + rectSize.y}
    };

    firstHitDist = std::numeric_limits<double>::max();
    double maxDist = -std::numeric_limits<double>::max();
    bool hit = false;

    for (int i = 0; i < 4; ++i) {
        double intersectionDist;
        if (collisionSegLine(corners[i], corners[(i + 1) % 4], linePos, lineAng, intersectionDist)) {
            hit = true;
            if (intersectionDist < firstHitDist) firstHitDist = intersectionDist;
            if (intersectionDist > maxDist) maxDist = intersectionDist;
        }
    }

    if (hit) {
        entryExitDist = maxDist - firstHitDist;
        return true;
    }
    return false;
}
*/
bool collisionSegLine(const Vector2d& A, const Vector2d& B, const Vector2d& linePos, const double lineAng, Vector2d& coordinate) {
    const double dx = std::cos(lineAng);
    const double dy = std::sin(lineAng);

    const double detA = (A.x - linePos.x) * dy - (A.y - linePos.y) * dx;
    const double detB = (B.x - linePos.x) * dy - (B.y - linePos.y) * dx;

    if (detA * detB > 0) return false;

    const double t = detA / (detA - detB);
    coordinate = {A.x + t * (B.x - A.x), A.y + t * (B.y - A.y)};

    return true;
}

bool collisionFacePlane(const Vector3d face[3], const Vector2d& planPos, double planAng, std::pair<Vector2d, Vector2d>& seg) {
    const Vector2d faces2d[3] = {{face[0].x, face[0].z}, {face[1].x, face[1].z}, {face[2].x, face[2].z}};
    bool hit = false;

    for (int i = 0; i < 3; i++) {
        if (collisionSegLine(faces2d[i], faces2d[(i + 1) % 3], planPos, planAng, seg.first)) {
            hit = true;
        }
        if (hit) {
            collisionSegLine(faces2d[i], faces2d[(i + 1) % 3], planPos, planAng, seg.second);
        }
    }

    return false;
}
