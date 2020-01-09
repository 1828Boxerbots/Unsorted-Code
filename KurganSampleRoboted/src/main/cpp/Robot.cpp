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

using namespace frc;

Robot::Robot() {

}

void Robot::RobotInit() 
{
  //left side inverted
    m_driveOne.SetInverted(true);
    m_driveTwo.SetInverted(true);
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
 * Runs the motors with TANK steering.
 */
void Robot::OperatorControl() 
{
  while (IsOperatorControl() && IsEnabled())
  {
    //drive 
      double rightY = m_controller.GetY(GenericHID::kRightHand);
      double leftY = m_controller.GetY(GenericHID::kLeftHand);
      //set left side
        m_driveOne.Set(leftY);
        m_driveTwo.Set(leftY);
      //set right side
        m_driveThree.Set(rightY);
        m_driveFour.Set(rightY);
      //set load  
      bool pullIn = m_controller.GetAButton();
      if (pullIn){
        m_pwmLoader.Set(-1.0);
      }
      //set eject
      bool eject = m_controller.GetBButton();
      if (eject){
        m_pwmLoader.Set(1.0);
      }
      //set non-load
      if((!pullIn && !eject) || (pullIn && eject)){
        m_pwmLoader.Set(0.0);
      }
      //set shooter
      double shootValue = m_controller.GetTriggerAxis(GenericHID::kRightHand);
      m_shootOne.Set(shootValue);
      m_shootTwo.Set(shootValue);
      m_shootThree.Set(shootValue);
      m_shootFour.Set(shootValue);
  }
}

/**
 * Runs during test mode
 */
void Robot::Test() {}

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
