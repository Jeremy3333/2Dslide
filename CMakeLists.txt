cmake_minimum_required(VERSION 3.30)
project(Blobux)

set(CMAKE_CXX_STANDARD 20)

find_package(SDL2 REQUIRED)

include_directories(${SDL2_INCLUDE_DIRS})
include_directories(src)

add_executable(Blobux main.cpp
        src/Controller/Controller.cpp
        src/Controller/Controller.hpp
        src/View/View.cpp
        src/View/View.hpp
        src/Utils/Utils.hpp
        src/Model/Model.cpp
        src/Model/Model.hpp
        src/Utils/Object3D/Vector3d.cpp
        src/Utils/Object3D/Vector3d.hpp
        src/Model/Player.cpp
        src/Model/Player.hpp
        src/Utils/Object3D/Object3D.cpp
        src/Utils/Object3D/Object3D.hpp
        src/Utils/Object3D/Cube.cpp
        src/Utils/Object3D/Cube.hpp
        src/Utils/Object2D/Object2D.cpp
        src/Utils/Object2D/Object2D.hpp
        src/Utils/Object2D/Vector2d.cpp
        src/Utils/Object2D/Vector2d.hpp
        src/Utils/Object2D/Rectangle.cpp
        src/Utils/Object2D/Rectangle.hpp
        src/Utils/Utils.cpp)

target_link_libraries(Blobux ${SDL2_LIBRARIES})