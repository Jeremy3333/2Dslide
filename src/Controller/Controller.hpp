//
// Created by tallyboy on 1/29/25.
//

#ifndef CONTROLLER_HPP
#define CONTROLLER_HPP

#include "Model/Model.hpp"
#include "View/View.hpp"

class Controller {
public:
    Controller();
    void run();
    void stop();

    [[nodiscard]] Vector3d getPlayerPosition() const;
    [[nodiscard]] double getPlayerDirection() const;
    [[nodiscard]] const std::vector<std::unique_ptr<Object3D>>& getObjects() const;

    void rotatePlayer(double delta);
private:
    View view_;
    Model model_;
    bool isRunning_;
};



#endif //CONTROLLER_HPP
