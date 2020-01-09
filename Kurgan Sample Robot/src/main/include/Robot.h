/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/XboxController.h>
#include <frc/Victor.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>

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
  Victor m_backLeftMotor{3};
  Victor m_frontLeftMotor{4};
  Victor m_backRightMotor{1};
  Victor m_frontRightMotor{2};

  Victor m_shooterBackRight{5};
  Victor m_shooterFrontRight{8};
  Victor m_shooterBackLeft{6};
  Victor m_shooterFrontLeft{7};

  Victor m_pickUp{0};

  XboxController m_xbox{0};
};
