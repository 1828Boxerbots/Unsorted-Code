/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>

#include <frc/Joystick.h>
#include <frc/Spark.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/XboxController.h>

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
class Robot : public frc::SampleRobot {
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
  // Robot drive system
  const int LEFT_DRIVE_MOTOR_PORT = 2;
  const int RIGHT_DRIVE_MOTOR_PORT = 3;
  const int PICKUP_PORT = 9;
  const int SHOOTER_PORT = 4;
  const int TURRET_PORT = 5;

  const int XBOX_PORT = 0;

  Spark m_leftDrive{LEFT_DRIVE_MOTOR_PORT};
  Spark m_rightDrive{RIGHT_DRIVE_MOTOR_PORT};

  Spark m_pickUp{PICKUP_PORT};

  Spark m_shooter{SHOOTER_PORT};

  Spark m_turret{TURRET_PORT};

  XboxController m_controller{XBOX_PORT};
};
