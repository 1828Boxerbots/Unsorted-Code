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
  m_leftMotor.SetInverted(true);
  m_rightMotor.SetInverted(false);

  m_leftLeadScrew.SetInverted(true);
  m_rightLeadScrew.SetInverted(false);

  m_arm.SetInverted(false);
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
    double leftY = -m_xbox.GetY(GenericHID::kLeftHand);
    double leftX = -m_xbox.GetX(GenericHID::kLeftHand);
    // Drive with arcade style (use right stick)
  m_robotDrive.ArcadeDrive(leftX, leftY);


    //LeadScrew
    bool topLimit = m_topLimit.Get();
    bool bottomLimit = m_bottomLimit.Get();
    SmartDashboard::PutBoolean("TopLimit", topLimit);
    SmartDashboard::PutBoolean("BottomLimit", bottomLimit);

    bool rightBumper = m_xbox.GetBumper(GenericHID::kRightHand);
    bool leftBumper = m_xbox.GetBumper(GenericHID::kLeftHand);

    if (((topLimit  == true) && (bottomLimit == true)) || ((topLimit == false) && (bottomLimit == false)))
    {
      if (((rightBumper  == true) && (leftBumper == true)) || ((rightBumper == false) && (leftBumper == false)))
      {
         m_leftLeadScrew.Set(0);
        m_rightLeadScrew.Set(0);
      }
      else
      {
        if (leftBumper == true)
        {
          m_leftLeadScrew.Set(-0.75);
          m_rightLeadScrew.Set(-0.75);
        }
        if (rightBumper == true)
        {
          m_leftLeadScrew.Set(.75);
          m_rightLeadScrew.Set(.75);
        }
      }
    }
    else
    {
      if (topLimit == true)
      {
        if (leftBumper == true)
        {
          m_leftLeadScrew.Set(-0.75);
          m_rightLeadScrew.Set(-0.75);
        }
        else
        {
          m_leftLeadScrew.Set(0);
          m_rightLeadScrew.Set(0);
        }
      }
      if (bottomLimit == true)
      {
        if (rightBumper == true)
        {
          m_leftLeadScrew.Set(.75);
          m_rightLeadScrew.Set(.75);
        }
        else
        {
          m_leftLeadScrew.Set(0);
          m_rightLeadScrew.Set(0);
        }
      }
    }

    //Arm
    bool xButton = m_xbox.GetXButton();
    bool bButton = m_xbox.GetBButton();
    int potValue = m_armPot.GetValue();
    double potVoltage = m_armPot.GetVoltage();

    const double MAXVALUE = 0;
    const double MINVALUE = 9999;
    SmartDashboard::PutNumber("Arm Pot Value", potValue);
    SmartDashboard::PutNumber("Arm Pot Voltage", potVoltage);
    if (((xButton  == true) && (bButton == true)) || ((xButton == false) && (bButton == false)))
      {
        m_arm.Set(0);
      }
      else
      {
        if (xButton == true)
        {
          //This is closing the claw
          if (potValue > MAXVALUE) 
          {
            m_arm.Set(0.0);
          }
          else 
          {
            m_arm.Set(0.5);
          }
          
        }
        if (bButton == true)
        {
          //This is opening the claw
          if (potValue < MINVALUE) 
          {
            m_arm.Set(0.0);
          }
          else 
          {
            m_arm.Set(-0.5);
          }
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
