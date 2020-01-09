/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/XboxController.h>
#include <frc/Talon.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/DigitalInput.h>
#include <frc/AnalogInput.h>
#include <frc/interfaces/Potentiometer.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class. The
 * SampleRobot class is the base of a robot application that will automatically
 * call your Autonomous and OperatorControl methods at the right time as
 * controlled by the switches on the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use TimedRobot or Command-Based
 * instead if you're new.
 */
using namespace frc;
class Robot : public frc::SampleRobot 
{
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
  // Robot drive system
  Talon m_leftMotor{1};
  Talon m_rightMotor{0};
  DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};

  XboxController m_xbox{0};

  Talon m_leftLeadScrew{2};
  Talon m_rightLeadScrew{3};

  Talon m_arm{4};

  DigitalInput m_topLimit{7};
  DigitalInput m_bottomLimit{6};

  AnalogInput m_armPot{3};
};
