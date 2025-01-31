//
// Created by tallyboy on 1/29/25.
//

#ifndef VIEW_HPP
#define VIEW_HPP

#include <SDL2/SDL.h>

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

    void drawCircle(int x, int y, int radius) const;
};



#endif //VIEW_HPP
