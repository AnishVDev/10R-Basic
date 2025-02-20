// src/lady_brown.cpp

#include "lady_brown.h"

// Constructor initializes motor and current position
LadyBrown::LadyBrown()
    : ladyBrownMotor(LADYBROWN_MOTOR_PORT), currentPosition(0) {}

// Moves the arm to a specific position (in degrees)
void LadyBrown::moveToPosition(int targetPosition) {
    ladyBrownMotor.move_absolute(targetPosition, 3000); // Move to target at 100 velocity
    currentPosition = targetPosition; // Update current position after command
}

// Check if the arm has reached the target position
bool LadyBrown::isAtPosition() const {
    return ladyBrownMotor.get_position() == currentPosition;
}

// Stop the motor (useful for safety or halting the movement)
void LadyBrown::stopMotor() {
    ladyBrownMotor.move_velocity(0); // Stop motor movement
}
