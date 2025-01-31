//
// Created by tallyboy on 1/29/25.
//

#include "Controller.hpp"

Controller::Controller() : view_(*this), isRunning_(true){}


void Controller::run() {
    while (isRunning_) {
        view_.input();
        view_.draw();
        view_.waitFrame();
    }
}

void Controller::stop() {
    isRunning_ = false;
}

Vector3d Controller::getPlayerPosition() const {
    return model_.getPlayerPosition();
}

double Controller::getPlayerDirection() const {
    return model_.getPlayerDirection();
}

void Controller::rotatePlayer(const double delta) {
    model_.rotatePlayer(delta);
}
