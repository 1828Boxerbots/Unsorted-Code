/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveCMD.h"
#include "Robot.h"

DriveCMD::DriveCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_pDriveTrain.get());
}

// Called just before this Command runs the first time
void DriveCMD::Initialize() {
  Robot::m_pDriveTrain->Init();
  Robot::m_pDriveTrain->StopMotor();
}

// Called repeatedly when this Command is scheduled to run
void DriveCMD::Execute() {
  Robot::m_pDriveTrain->Teleop(Robot::m_oi.GetController());
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCMD::Interrupted() {}
