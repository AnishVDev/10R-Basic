// include/lady_brown.h

#pragma once
#include "pros/motors.hpp"
#include "robot_config.h"

class LadyBrown {
public:
    LadyBrown();  // Constructor
    void moveToPosition(int targetPosition); // Moves arm to a specific position in degrees
    bool isAtPosition() const; // Checks if arm is at target position
    void stopMotor(); // Stops the motor

private:
    pros::Motor ladyBrownMotor;
    int currentPosition; // Tracks current position in degrees
};
