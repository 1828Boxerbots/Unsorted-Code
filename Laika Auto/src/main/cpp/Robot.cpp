/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>

#include <frc/Timer.h>
#include <frc/smartdashboard/SmartDashboard.h>

Robot::Robot() 
{
  // Note SmartDashboard is not initialized here, wait until RobotInit() to make
  // SmartDashboard calls
  //m_robotDrive.SetExpiration(0.1);
}

void Robot::RobotInit() 
{
  m_gyro.Reset();
  m_gyro.Calibrate();

  m_leftMotor.SetInverted(true);
  m_rightMotor.SetInverted(false);

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
void Robot::Autonomous()
{
  m_leftMotor.Set(.25);
  m_rightMotor.Set(-.25);
  Wait (2);
  m_leftMotor.Set(0);
  m_rightMotor.Set(0);
  /*
  double gyroAngle = m_gyro.GetAngle();
  if ((gyroAngle < 0.10) && (gyroAngle > -0.10))
  {
    m_leftMotor.Set(.25);
    m_rightMotor.Set(.25);
  }
  else
  {
    m_leftMotor.Set(0);
    m_rightMotor.Set(0);
  }
  */

}

/**
 * Runs the motors with arcade steering.
 */
void Robot::OperatorControl() 
{
  while (IsOperatorControl() && IsEnabled()) 
  {
    // Drive with arcade style (use right stick)
    //m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
    double leftY = m_xbox.GetY(GenericHID::kLeftHand);
    double leftX = m_xbox.GetX(GenericHID::kLeftHand);
    
    m_leftMotor.Set(leftY - leftX);
    m_rightMotor.Set(-leftY + leftX);

    double gyro = m_gyro.GetAngle();

    SmartDashboard::PutNumber("Gyro Angle", gyro);

    // The motors will be updated every 5ms
    frc::Wait(0.005);
  }
}

/**
 * Runs during test mode
 */
void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
