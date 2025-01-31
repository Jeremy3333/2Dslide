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
        src/Utils/Vector3d.cpp
        src/Utils/Vector3d.hpp
        src/Model/Player.cpp
        src/Model/Player.hpp)

target_link_libraries(Blobux ${SDL2_LIBRARIES})