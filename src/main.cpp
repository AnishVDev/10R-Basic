/**
 *
 * @file main.cpp
 * @brief This file contains the main code for the robot's operation.
 *
 * Robot Controller:
 *
 * Tank Drive
 * Left Joystick (Vertical): Controls left side of drivetrain (forward/backward).
 * Right Joystick (Vertical): Controls right side of drivetrain (forward/backward).
 *
 * Arcade Drive
 * Left Joystick (Vertical): Controls movement of the drivetrain (forward/backward).
 * Right Joystick (Horizontal): Controls rotation of the drivetrain (left/right).
 *
 * Controller Settings:
 * R1 - Press once to start the intake moving forward. Press again to stop the intake (if it's already running forward).
 * R2 - Press once to start the intake moving in reverse. Press again to stop the intake (if it's already running in reverse).
 * L1 - Opens the clamp by activating the pistons.
 * L2 - Closes the clamp by deactivating the pistons.
 * X - Extend lady brown
 * B - Retract lady brown
 *
 * Motor Settings:
 * Motor Ports: Ports 1-6 (left ports: 1, 2, and 3; right ports: 4, 5, and 6)
 * Intake Port: Port 7
 * Lady Brown Port: Port 10
 * Pneumatics (Clamp Pistons): ADI Port A
 * Controller: USB Ports to wirelessly connect to VEX Brain
 * 
 * Sensors:
 * IMU - Inertial sensor for tracking movement
 * Vertical encoder (Vertical Tracking Wheel) - uses a rotational sensor to track vertical movement specifically
 *  * Ports:
 * 1 - Left motor (controls wheels 1 & 2)
 * 2 - Left motor (controls wheels 2 & 3)
 * 3 - Left motor (controls wheels 3 & 4)
 * 4 - Right motor (controls wheels 5 & 6)
 * 5 - Right motor (controls wheels 6 & 7)
 * 6 - Right motor (controls wheels 7 & 8)
 * 7 - Intake and Flexwheel motor
 * 8 - IMU
 * 9 - Rotational Sensor
 * 10 - Lady Brown
 * 11 - Radar
 *    _____         .__       .__  ____   ____________                
 *   /  _  \   ____ |__| _____|  |_\   \ /   /\______ \   _______  __ 
 *  /  /_\  \ /    \|  |/  ___/  |  \   Y   /  |    |  \_/ __ \  \/ / 
 * /    |    \   |  \  |\___ \|   Y  \     /   |    `   \  ___/\   /  
 * \____|__  /___|  /__/____  >___|  /\___/   /_______  /\___  >\_/   
 *         \/     \/        \/     \/                 \/     \/       
 *  ___________ __________ 
 * /_   \   _  \\______   \
 *  |   /  /_\  \|       _/
 *  |   \  \_/   \    |   \
 *  |___|\_____  /____|_  /
 *             \/       \/ 
 *
 */

#include "main.h"
#include "drivetrain.h"
#include "intake.h"
#include "pneumatics.h"

pros::Controller master(pros::E_CONTROLLER_MASTER);
Drivetrain drivetrain;
Intake intake;
Pneumatics pneumatics;
LadyBrown ladyBrown;

void initialize() {
    // Initialization code here
}

/**Skills
*/
void autonomous() {
    ladyBrown.moveToPosition(-1200); 
    pros::delay(600);
    drivetrain.autonomousDrive(400, 200);
    intake.setIntake(400);
    pros::delay(1000); 
    drivetrain.autonomousDrive(-800, 100); 
    pros::delay(1000); 
    drivetrain.autonomousTurn(57, 200, true); 
    pros::delay(700); 
    drivetrain.autonomousDrive(870, 100); 
    pros::delay(740); 
    pneumatics.setClampState(true);
    pros::delay(300);
    drivetrain.autonomousTurn(75, 200, false);
    pros::delay(500);
    drivetrain.autonomousDrive(-1600, 100);
    pros::delay(600);
    drivetrain.autonomousTurn(42, 200, false);
    pros::delay(500);
    drivetrain.autonomousDrive(-10000, 100);
/**
    pros::delay(600);
    drivetrain.autonomousTurn(35, 200, false);
    pros::delay(200);
    drivetrain.autonomousDrive(-850, 100);
    */
/**
    ladyBrown.moveToPosition(-1200);
    drivetrain.autonomousDrive(600, 100);
    pros::delay(200);
    pneumatics.setClampState(true);
    pros::delay(1000);                          // Delay to ensure the clamp has time  to actuate
    intake.setIntake(130);                      // Turn intake on
    pros::delay(500);                           // Run intake for 0.5 seconds
    drivetrain.autonomousTurn(88, 110, true);
    pros::delay(1000);
    drivetrain.autonomousDrive(-1200, 100);
    pros::delay(1100);
    drivetrain.autonomousDrive(-200, 100);
    pros::delay(400);
    drivetrain.autonomousTurn(55, 110, true);
    pros::delay(700);
    drivetrain.autonomousDrive(-300, 100);
    pros::delay(1000);
    drivetrain.autonomousTurn(82.5, 110, true);
    pros::delay(1000);
    drivetrain.autonomousDrive(-2000, 100);
    pros::delay(1100);
    drivetrain.autonomousTurn(55, 110, false);
    pros::delay(700);
    drivetrain.autonomousDrive(-1800, 100);
    pros::delay(800);
    drivetrain.autonomousTurn(27.5, 110, true);
    pros::delay(700);
    drivetrain.autonomousDrive(2300, 100);
    pros::delay(1200);
*/
}


/**
Right Side Auton

void autonomous() {
    ladyBrown.moveToPosition(1200);
    drivetrain.autonomousDrive(2000, 100);
    pros::delay(1100);
    pneumatics.setClampState(true);
    pros::delay(1000);                          // Delay to ensure the clamp has time  to actuate
    intake.setIntake(130);                      // Turn intake on
    pros::delay(500);                           // Run intake for 0.5 seconds
    drivetrain.autonomousTurn(55, 110, true);
    pros::delay(1000);
    drivetrain.autonomousDrive(-1500, 100);
    pros::delay(5000);
    drivetrain.autonomousTurn(135, 110, true);
    pros::delay(1000);
    drivetrain.autonomousDrive(-3400, 50);
    pros::delay(2300);
    intake.stopIntake();                        // Stop the intake
}
*/

/**
Left Side Auton

void autonomous() {
    ladyBrown.moveToPosition(1200);
    drivetrain.autonomousDrive(2000, 100);
    pros::delay(1100);
    pneumatics.setClampState(true);
    pros::delay(1000);                          // Delay to ensure the clamp has time  to actuate
    intake.setIntake(130);                      // Turn intake on
    pros::delay(500);                           // Run intake for 0.5 seconds
    drivetrain.autonomousTurn(65, 120, false);
    pros::delay(1000);
    drivetrain.autonomousDrive(-1400, 100);
    pros::delay(5000);
    drivetrain.autonomousTurn(130, 120, false);
    pros::delay(1000);
    drivetrain.autonomousDrive(-3500, 50);
    pros::delay(2000);
    intake.stopIntake();                        // Stop the intake
}
*/

void opcontrol() {
    while (true) {
        drivetrain.driveControl();
        intake.controlIntake();
        pneumatics.controlClamp();
        // Elevate Lady Brown Toggle ("X" button)
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_X)) {
            ladyBrown.moveToPosition(-3000); // Move arm to 130 degrees
        }
        // Retract Lady Brown Toggle ("B" button)
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_B)) {
            ladyBrown.moveToPosition(0);     // Move arm to 0 degrees (retract)
        }
        // If "A" button is pressed, stop the motor
        if (master.get_digital_new_press(pros::E_CONTROLLER_DIGITAL_A)) {
            ladyBrown.stopMotor();
        }
        pros::delay(20);
    }
}