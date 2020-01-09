/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/commands/DriveCMD.h"
#include "Robot.h"
#include "../include/OI.h"
#include <frc/smartdashboard/smartdashboard.h>

DriveCMD::DriveCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void DriveCMD::Initialize() 
{
  Robot::m_drivetrain.InitDefaultCommand();
}

// Called repeatedly when this Command is scheduled to run
void DriveCMD::Execute() 
{
  frc::XboxController * pController = Robot::m_oi.getController();
  //double leftX = pController -> GetX(frc::GenericHID::kLeftHand);
  double leftY = pController -> GetY(frc::GenericHID::kLeftHand);
  double rightY= pController-> GetY(frc::GenericHID::kRightHand);
  //Arcade
  /*
  Robot::m_drivetrain.MoveArcade(leftX, leftY);
  */
  //Tank
  Robot::m_drivetrain.MoveTank(leftY, rightY);

  frc::SmartDashboard::SmartDashboard::PutNumber("LeftY", leftY);
  frc::SmartDashboard::SmartDashboard::PutNumber("RightY", rightY);

}

// Make this return true when this Command no longer needs to run execute()
bool DriveCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCMD::Interrupted() {}
