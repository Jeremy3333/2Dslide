//
// Created by tallyboy on 1/29/25.
//

#ifndef VIEW_HPP
#define VIEW_HPP

#include <memory>
#include <SDL2/SDL.h>

#include "Utils/GenericObject/Generic3DObject.hpp"
#include "Utils/Object2D/Object2D.hpp"
#include "Utils/Object2D/Rectangle.hpp"

// define class Controller to avoid circular dependency
class Controller;

class View {
public:
    explicit View(Controller& controller);
    ~View();
    void input() const;
    void draw() const;

    void waitFrame();
private:
    Controller& controller_;

    SDL_Window* window_;
    SDL_Renderer* renderer_;
    int windowWidth_;
    int windowHeight_;
    int lastFrameTime_;

    void clear() const;

    void drawCompas(double dir) const;

    void drawObject2D(const std::unique_ptr<Generic2Dobject> &object) const;
    void drawRectangle(const Rectangle& rectangle) const;

    void drawCircle(int x, int y, int radius) const;
};



#endif //VIEW_HPP
