//
// Created by ijpark on 8/22/17.
//


#include <stdio.h>
#include "Aria.h"

class ActionTurn : public ArAction {
public:
    ActionTurn(double turnThreshold, double turnAmount) {
        this->turnThreshold = turnThreshold;
        this->turnAmount = turnAmount;
    }

    virtual ~ActionTurn() {}

    void setRobot(ArRobot* robot) {
        robot->findRangeDevice("sonar");
    }
};


int main(int argc, char** argv) {
    return printf ("hello world\n");
}
