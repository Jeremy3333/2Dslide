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
    drawCompas(dir);
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
    SDL_SetRenderDrawColor(renderer_, 0, 0, 0, 255);
    SDL_RenderClear(renderer_);
}

void View::drawCompas(const double dir) const {
    SDL_SetRenderDrawColor(renderer_, 169, 169, 169, 255);
    drawCircle(windowWidth_ - 60, 60, 50);
    SDL_SetRenderDrawColor(renderer_, 255, 0, 0, 255);
    SDL_RenderDrawLine(renderer_, windowWidth_ - 60, 60, static_cast<int>(windowWidth_ - 60 + 50 * cos(dir)), static_cast<int>(60 + 50 * sin(dir)));
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
