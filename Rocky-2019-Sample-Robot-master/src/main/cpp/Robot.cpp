/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <frc/smartdashboard/SmartDashboard.h>
Robot::Robot() {

}

void Robot::RobotInit() {
  m_leftMotor.SetInverted(true);
  m_shootMotor.SetInverted(true);

}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::Autonomous() {
  
}

/**
 * Runs the motors with arcade steering.
 */
void Robot::OperatorControl() {
  while (IsOperatorControl() && IsEnabled()) {
    double X = m_controller.GetX(frc::GenericHID::kLeftHand);
    double Y = m_controller.GetY(frc::GenericHID::kLeftHand);

    m_leftMotor.Set(Y + X);
    m_rightMotor.Set(Y - X);

    bool leftBumper = m_controller.GetBumper(frc::GenericHID::kLeftHand);
    bool rightBumper = m_controller.GetBumper(frc::GenericHID::kRightHand);

    if(leftBumper && !rightBumper)
    {
      m_liftMotor.Set(-1.0);
    }
    if(rightBumper && !leftBumper)
    {
      m_liftMotor.Set(1.0);
    }
    else
    {
      m_liftMotor.Set(0.0);
    }

    double leftTrigger = m_controller.GetTriggerAxis(frc::GenericHID::kLeftHand);
    
    m_shootMotor.Set(leftTrigger);

    double rightX = m_controller.GetX(frc::GenericHID::kRightHand);

    m_turrentMotor.Set(rightX);


    

 


  }
}

/**
 * Runs during test mode
 */
void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
