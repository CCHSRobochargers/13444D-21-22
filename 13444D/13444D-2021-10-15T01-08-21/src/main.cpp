// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// Controller1          controller                    
// Motor18              motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// Controller1          controller                    
// Motor18              motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// Controller1          controller                    
// Motor18              motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// Controller1          controller                    
// Motor18              motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// Controller1          controller                    
// Motor18              motor         18              
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 19           
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 2            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 2            
// Controller1          controller                    
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   9, 2            
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// MotorGroup9          motor_group   19, 9           
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20          
// ---- END VEXCODE CONFIGURED DEVICES ----
// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    10, 20
// MotorGroup9          motor_group   9, 19
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----
/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Code                                          */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// Drivetrain           drivetrain    20, 10
// Controller1          controller
// ---- END VEXCODE CONFIGURED DEVICES ----

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;

// define your global instances of motors and other devices here
double speed = 1.0;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT10, ratio18_1, false);
motor RightDriveSmart = motor(PORT20, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 40, mm, 1);
motor MotorGroup9MotorA = motor(PORT9, ratio18_1, false);
motor MotorGroup9MotorB = motor(PORT19, ratio18_1, true);
motor_group MotorGroup9 = motor_group(MotorGroup9MotorA, MotorGroup9MotorB);
controller Controller1 = controller(primary);
controller Controller2 = controller(partner);
motor Motor18 = motor(PORT18, ratio18_1, false);
motor Motor17 = motor(PORT17, ratio36_1, true);
motor Motor15 = motor(PORT15, ratio18_1, false);
motor Motor16 = motor(PORT16, ratio18_1, true);
motor_group MotorGroup15 = motor_group(Motor15, Motor16);
// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;
// define variables used for controlling motors based on controller inputs
bool Controller2LeftShoulderControlMotorsStopped = true;
bool DrivetrainLNeedsToBeStopped_Controller1 = true;
bool DrivetrainRNeedsToBeStopped_Controller1 = true;

// define a task that will handle monitoring inputs from Controller1
int rc_auto_loop_function_Controller1() {
  // process the controller input every 20 milliseconds
  // update the motors based on the input values
  while(true) {
    if(RemoteControlCodeEnabled) {
      // calculate the drivetrain motor velocities from the controller joystick axies
      // left = Axis3
      // right = Axis2
      int drivetrainLeftSideSpeed = Controller1.Axis3.position();
      int drivetrainRightSideSpeed = Controller1.Axis2.position();
      
      // check if the value is inside of the deadband range
      if (drivetrainLeftSideSpeed < 5 && drivetrainLeftSideSpeed > -5) {
        // check if the left motor has already been stopped
        if (DrivetrainLNeedsToBeStopped_Controller1) {
          // stop the left drive motor
          LeftDriveSmart.stop();
          // tell the code that the left motor has been stopped
          DrivetrainLNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the left motor nexttime the input is in the deadband range
        DrivetrainLNeedsToBeStopped_Controller1 = true;
      }
      // check if the value is inside of the deadband range
      if (drivetrainRightSideSpeed < 5 && drivetrainRightSideSpeed > -5) {
        // check if the right motor has already been stopped
        if (DrivetrainRNeedsToBeStopped_Controller1) {
          // stop the right drive motor
          RightDriveSmart.stop();
          // tell the code that the right motor has been stopped
          DrivetrainRNeedsToBeStopped_Controller1 = false;
        }
      } else {
        // reset the toggle so that the deadband code knows to stop the right motor next time the input is in the deadband range
        DrivetrainRNeedsToBeStopped_Controller1 = true;
      }
      
      // only tell the left drive motor to spin if the values are not in the deadband range
      if (DrivetrainLNeedsToBeStopped_Controller1) {
        LeftDriveSmart.setVelocity(drivetrainLeftSideSpeed * speed, percent);
        LeftDriveSmart.spin(forward);
      }
      // only tell the right drive motor to spin if the values are not in the deadband range
      if (DrivetrainRNeedsToBeStopped_Controller1) {
        RightDriveSmart.setVelocity(drivetrainRightSideSpeed * speed, percent);
        RightDriveSmart.spin(forward);
      }
      // check the ButtonL1/ButtonL2 status to control MotorGroup9
      if (Controller2.ButtonL1.pressing()) {
        MotorGroup9.spin(forward);
        Controller2LeftShoulderControlMotorsStopped = false;
      } else if (Controller2.ButtonL2.pressing()) {
        MotorGroup9.spin(reverse);
        Controller2LeftShoulderControlMotorsStopped = false;
      } else if (!Controller2LeftShoulderControlMotorsStopped) {
        MotorGroup9.stop();
        // set the toggle so that we don't constantly tell the motor to stop when the buttons are released
        Controller2LeftShoulderControlMotorsStopped = true;
      }
      if (Controller1.ButtonR1.pressing()) {
        speed = 1.0;
      }
      if (Controller1.ButtonR2.pressing()) {
        speed = 0.5;
      }
      if (Controller2.ButtonUp.pressing()) {
        Motor18.spin(forward);
      }
      if (Controller2.ButtonDown.pressing()) {
        Motor18.spin(reverse);
      }
      if (Controller2.ButtonR1.pressing()) {
        Motor17.spin(forward);
      } else if (Controller2.ButtonR2.pressing()) {
        Motor17.spin(reverse);
      } else {
        Motor17.stop();
      }
      if (Controller2.ButtonUp.pressing()) {
        MotorGroup15.spin(forward);
      }
      else if (Controller2.ButtonDown.pressing()) {
        MotorGroup15.spin(reverse);
      } else {
        MotorGroup15.stop();
      }
    }
    // wait before repeating the process
    wait(20, msec);
  }
  return 0;
}

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  task rc_auto_loop_task_Controller1(rc_auto_loop_function_Controller1);
}

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();

  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void auto_yellow_goal(void) {
  Drivetrain.setDriveVelocity(500, percent);
  MotorGroup9.setVelocity(100, percent);
  MotorGroup9.spinFor(reverse, 160 * -3.0 * 1.75, degrees);
  Drivetrain.driveFor(forward, 54, inches);
  MotorGroup9.spinFor(forward, 100 * -3.0 * 1.75, degrees);
  Drivetrain.driveFor(reverse, 54, inches);
  //MotorGroup9.spinFor(reverse, 175 * 1.75, degrees);
}

void left_auto_alliance_goal(void) {
  Drivetrain.setDriveVelocity(500, percent);
  MotorGroup9.spinFor(reverse, 160 * -3.0 * 1.75, degrees);
  Drivetrain.turnFor(left, 10, degrees);
  Drivetrain.driveFor(forward, 15, inches);
  MotorGroup9.spinFor(forward,  100 * -3.0 * 1.75, degrees);
  Drivetrain.driveFor(reverse, 15, inches);
}

void right_auto_alliance_goal(void) {
  Drivetrain.driveFor(forward, 9, inches);
  MotorGroup9.spinFor(reverse, 160 * -3.0 * 1.75, degrees);
  Drivetrain.driveFor(forward, 7, inches);
  MotorGroup9.spinFor(reverse, 160 * -3.0 * 1.75, degrees);
  Drivetrain.driveFor(forward, 40, inches);
  MotorGroup9.spinFor(forward, 160 * -3.0 * 1.75, degrees);

}

void skills(void) {
Drivetrain.setDriveVelocity(100, percent);  
// MotorGroup9.spinFor(-120 * -3.0 * 1.75, degrees);
Drivetrain.driveFor(forward, 15, inches);
// MotorGroup9.spinFor(200, degrees);
Drivetrain.driveFor(50, inches);
MotorGroup9.spinFor(-100 * -3.0 * 1.75, degrees);
Drivetrain.driveFor(reverse, 1, inches);
}

void skills2(void) {
  Drivetrain.turnFor(right, 10, degrees);
  Drivetrain.driveFor(forward, 12.5, inches);
  MotorGroup9.spinFor(forward, 160 * -3.0 * 1.75, degrees);
  Drivetrain.driveFor(reverse, 12.5, inches);
}




void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
  auto_yellow_goal();
  //left_auto_alliance_goal();
  //right_auto_alliance_goal();
  //skills();
  //skills2();
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  Drivetrain.setDriveVelocity(70, percent);
  MotorGroup9.setStopping(hold);
  Motor17.setStopping(hold);
  MotorGroup15.setStopping(hold);
  MotorGroup9.setVelocity(100, percent);
  Drivetrain.setTurnVelocity(70, percent);
  MotorGroup9.setMaxTorque(100, percent);
  MotorGroup15.setMaxTorque(100, percent);
  Motor17.setMaxTorque(100, percent);
  
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

//
// Main will set up the competition functions and callbacks.
//
int main() {
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
