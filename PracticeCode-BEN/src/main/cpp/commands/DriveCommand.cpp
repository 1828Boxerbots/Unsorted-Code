/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveCommand.h"
#include "Robot.h"

DriveCommand::DriveCommand() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(&Robot::m_drivetrain);
}

// Called just before this Command runs the first time
void DriveCommand::Initialize() 
{
  Robot::m_drivetrain.IntHardware();
}
 
// Called repeatedly when this Command is scheduled to run
void DriveCommand::Execute() 
{
  Robot::m_drivetrain.ForwardInSeconds(5);
  Robot::m_drivetrain.Stop();
  Robot::m_drivetrain.BackwardInSeconds(5);
  Robot::m_drivetrain.Stop();
}

// Make this return true when this Command no longer needs to run execute()
bool DriveCommand::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveCommand::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveCommand::Interrupted() {}
