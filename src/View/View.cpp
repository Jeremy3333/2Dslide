//
// Created by tallyboy on 1/29/25.
//

#include <iostream>

#include "View.hpp"
#include "Controller/Controller.hpp"
#include "Utils/Utils.hpp"

View::View(Controller& controller) : controller_(controller), windowWidth_(WINDOW_WIDTH), windowHeight_(WINDOW_HEIGHT), lastFrameTime_(0) {
    if(SDL_Init(SDL_INIT_VIDEO) != 0) {
        std::cerr << "SDL_Init Error: " << SDL_GetError() << std::endl;
        exit(1);
    }

    window_ = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
    if (window_ == nullptr) {
        std::cerr << "SDL_CreateWindow Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }

    renderer_ = SDL_CreateRenderer(window_, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    if (renderer_ == nullptr) {
        SDL_DestroyWindow(window_);
        std::cerr << "SDL_CreateRenderer Error: " << SDL_GetError() << std::endl;
        SDL_Quit();
        exit(1);
    }
}

View::~View() {
    SDL_DestroyRenderer(renderer_);
    SDL_DestroyWindow(window_);
    SDL_Quit();
}

void View::input() const {
    SDL_Event event;
    while (SDL_PollEvent(&event)) {
        if (event.type == SDL_QUIT ||
            (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
            controller_.stop();
            }
    }

    // Vérification de l'état des touches indépendamment des événements
    const Uint8* keyState = SDL_GetKeyboardState(nullptr);
    if (keyState[SDL_SCANCODE_Q]) {
        controller_.rotatePlayer(static_cast<double>(-TIME_PER_FRAME) / 1000.0f);
    }
    if (keyState[SDL_SCANCODE_E]) {
        controller_.rotatePlayer(static_cast<double>(TIME_PER_FRAME) / 1000.0f);
    }
}


void View::draw() const {
    clear();
    const double dir = controller_.getPlayerDirection();
    const Vector3d playerPos = controller_.getPlayerPosition();
    drawCompas(dir);
    for (const auto& object : controller_.getObjects()) {
        drawObject2D(object->getCut(dir, Vector2d(playerPos.x, playerPos.z)));
    }
    SDL_RenderPresent(renderer_);
}

void View::waitFrame() {
    const int currentTime = static_cast<int>(SDL_GetTicks());
    if (const int timeToWait = TIME_PER_FRAME - (currentTime - lastFrameTime_); timeToWait > 0) {
        SDL_Delay(static_cast<Uint32>(timeToWait));
    }
    lastFrameTime_ = currentTime;
}

void View::clear() const {
    SDL_SetRenderDrawColor(renderer_, 255, 255, 255, 255);
    SDL_RenderClear(renderer_);
}

void View::drawCompas(const double dir) const {
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    drawCircle(windowWidth_ - 60, 60, 50);
    SDL_SetRenderDrawColor(renderer_, 169, 169, 169, 255);
    drawCircle(windowWidth_ - 60, 60, 48);
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer_, windowWidth_ - 60, 60, static_cast<int>(windowWidth_ - 60 + 50 * cos(dir)), static_cast<int>(60 + 50 * sin(dir)));
    SDL_Vertex vertices[4];
    vertices[0] = {static_cast<float>(windowWidth_ - 60 + 50 * cos(dir)), static_cast<float>(60 + 50 * sin(dir)), {255}};
    vertices[1] = {static_cast<float>(windowWidth_ - 60 + 10 * cos(dir + M_PI / 2)), static_cast<float>(60 + 10 * sin(dir + M_PI / 2)), {255}};
    vertices[2] = {static_cast<float>(windowWidth_ - 60 + 10 * cos(dir - M_PI / 2)), static_cast<float>(60 + 10 * sin(dir - M_PI / 2)), {255}};
    vertices[3] = {static_cast<float>(windowWidth_ - 60 + 15 * cos(dir - M_PI)), static_cast<float>(60 + 15 * sin(dir - M_PI)), {255}};
    const int indices[] = {0, 1, 2, 1, 2, 3};
    SDL_RenderGeometry(renderer_, nullptr, vertices, 4, indices, 6);
    std::cout <<  SDL_GetError() << std::endl;
}

void View::drawObject2D(const std::unique_ptr<Object2D> &object) const {
    if (object == nullptr) {
        return;
    }
    if (dynamic_cast<Rectangle*>(object.get())) {
        drawRectangle(*dynamic_cast<Rectangle*>(object.get()));
        return;
    }
    std::cerr << "Unknown object type" << std::endl;
}

void View::drawRectangle(const Rectangle& rectangle) const {
    SDL_Rect rect;
    rect.x = static_cast<int>(std::floor(rectangle.getPosition().x * 2)) + windowWidth_ / 2;
    rect.y = static_cast<int>(std::floor(rectangle.getPosition().y * 2)) + windowHeight_ / 2;
    rect.w = static_cast<int>(std::ceil(rectangle.getWidth() * 2));
    rect.h = static_cast<int>(std::ceil(rectangle.getHeight() * 2));
    SDL_SetRenderDrawColor(renderer_, 100, 100, 255, 255);
    SDL_RenderFillRect(renderer_, &rect);
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderDrawRect(renderer_, &rect);
}


void View::drawCircle(const int x, const int y, const int radius) const {
    for (int w = 0; w < radius * 2; w++)
    {
        for (int h = 0; h < radius * 2; h++)
        {
            const int dx = radius - w;
            if (const int dy = radius - h; dx*dx + dy*dy <= radius * radius)
            {
                SDL_RenderDrawPoint(renderer_, x + dx, y + dy);
            }
        }
    }
}
