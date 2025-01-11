// src/intake.cpp

#include "intake.h"

int intakeSpeed = 85;

Intake::Intake() 
    : intakeMotor(INTAKE_MOTOR_PORT),
      intakeRunningForward(false), intakeRunningReverse(false) {}

void Intake::controlIntake() {
    if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R2)) {
        intakeRunningForward = !intakeRunningForward;
        intakeRunningReverse = false;
        intakeMotor.move(intakeRunningForward ? intakeSpeed : 0);
    } else if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_R1)) {
        intakeRunningReverse = !intakeRunningReverse;
        intakeRunningForward = false;
        intakeMotor.move(intakeRunningReverse ? -intakeSpeed : 0);
    }
}

// Directly sets the intake motor power
void Intake::setIntake(int speed) {
    intakeMotor.move(-intakeSpeed); // Positive for intake, negative for outtake
}

// Stops the intake motor
void Intake::stopIntake() {
    intakeMotor.move(0);
}
