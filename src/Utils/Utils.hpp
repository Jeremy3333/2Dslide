//
// Created by tallyboy on 1/29/25.
//

#ifndef UTILS_HPP
#define UTILS_HPP

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600
#define WINDOW_TITLE "Blobux"
#define TIME_PER_FRAME 16 // 60 FPS
#include <vector>
#include "Object2D/Vector2d.hpp"
#include "Object3D/Vector3d.hpp"

//--- fonction ---

// bool collisionRectLine(const Vector2d& rectPos, const Vector2d& rectSize, const Vector2d& linePos, double lineAng, double& firstHitDist, double& entryExitDist);
bool collisionFacePlane(const Vector3d face[3], const Vector2d& planPos, double planAng, std::pair<Vector2d, Vector2d>& seg);

#endif //UTILS_HPP
