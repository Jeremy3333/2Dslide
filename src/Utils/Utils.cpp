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