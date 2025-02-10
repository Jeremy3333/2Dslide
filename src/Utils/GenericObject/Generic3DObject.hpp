//
// Created by tallyboy on 2/10/25.
//

#ifndef GENERIC3DOBJECT_HPP
#define GENERIC3DOBJECT_HPP

#include <memory>
#include <vector>

#include "Utils/Object3D/Vector3d.hpp"
#include "Face.hpp"
#include "Generic2Dobject.hpp"

class Generic3DObject {
public:
  Generic3DObject(const Vector3d& min, const Vector3d& max); // Rectangular cuboid construct
  bool isClosed();
  std::unique_ptr<Generic2Dobject> getCut(double ang, const Vector2d& origin) const;
private:
  int countEdge();
  std::vector<Face> _faces;
  std::vector<Vector3d> _vertices;
};



#endif //GENERIC3DOBJECT_HPP
