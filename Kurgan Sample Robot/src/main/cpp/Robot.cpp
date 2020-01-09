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
}

void Robot::RobotInit() 
{
  m_frontLeftMotor.SetInverted(false);
  m_backLeftMotor.SetInverted(false);
  m_frontRightMotor.SetInverted(false);
  m_backRightMotor.SetInverted(false);

  m_shooterBackRight.SetInverted(false);
  m_shooterFrontRight.SetInverted(false);
  m_shooterBackLeft.SetInverted(false);
  m_shooterFrontLeft.SetInverted(false);

  m_pickUp.SetInverted(true);
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
  
}

/**
 * Runs the motors with arcade steering.
 */
void Robot::OperatorControl() 
{
  while (IsOperatorControl() && IsEnabled()) 
  {
    // Drive with tank style
    double leftY = -m_xbox.GetY(GenericHID::kLeftHand);
    double rightY = m_xbox.GetY(GenericHID::kRightHand);

    m_backLeftMotor.Set(rightY);
    m_frontLeftMotor.Set(rightY);
    m_backRightMotor.Set(leftY);
    m_frontRightMotor.Set(leftY);

    //Shooter
    bool rightBumper = m_xbox.GetBumper(GenericHID::kRightHand);
    bool leftBumper = m_xbox.GetBumper(GenericHID::kLeftHand);

    if (((rightBumper == true) && (leftBumper == true)) || ((rightBumper == false) && (leftBumper == false)))
    {
      m_shooterBackLeft.Set(0);
      m_shooterBackRight.Set(0);
      m_shooterFrontLeft.Set(0);
      m_shooterFrontRight.Set(0);
    }
    else
    {
      if (rightBumper == true)
      {
        m_shooterBackLeft.Set(0.7);
        m_shooterBackRight.Set(0.7);
        m_shooterFrontLeft.Set(0.7);
        m_shooterFrontRight.Set(0.7);
      }
      if (leftBumper == true)
      {
       m_shooterBackLeft.Set(0.7);
        m_shooterBackRight.Set(0.7);
        m_shooterFrontLeft.Set(0.7);
        m_shooterFrontRight.Set(0.7); 
      }
    }

    //PickUp
    bool aButton = m_xbox.GetAButton();
    bool bButton = m_xbox.GetBButton();

    if (((aButton == true) && (bButton == true)) || ((aButton == false) && (bButton == false)))
    {
      m_pickUp.Set(0);
    }
    else
    {
      if (aButton == true)
      {
        m_pickUp.Set(1);
      }
      if (bButton == true)
      {
        m_pickUp.Set(-1);
      }
    }

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
