/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Talon.h>
#include <frc/commands/Subsystem.h>
#include <RobotMap.h>
#include <frc/drive/DifferentialDrive.h>

using namespace frc;

class DriveTrain : public frc::Subsystem {
 private:
 //Defines Drive motors and attaches them to port numbs
 Talon m_lDriveMotor{LEFT_DRIVE_MOTOR_PORT};
 Talon m_rDriveMotor{RIGHT_DRIVE_MOTOR_PORT};
 //Hooks up drive to motors
DifferentialDrive mainDrive{m_lDriveMotor, m_rDriveMotor};
 public:DriveTrain();
  void ResetMotors();
  void StopMotors();
  void TeleopDrive(XboxController* controller);
  
};
