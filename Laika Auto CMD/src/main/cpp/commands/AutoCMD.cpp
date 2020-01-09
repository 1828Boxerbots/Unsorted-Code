/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/AutoCMD.h"
#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>

AutoCMD::AutoCMD() 
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_driveTrain.get());
}

// Called just before this Command runs the first time
void AutoCMD::Initialize() 
{
  Robot::m_driveTrain->InvertMotors();
}

// Called repeatedly when this Command is scheduled to run
void AutoCMD::Execute() 
{
  Robot::m_driveTrain->DriveForward(0.5, 1, -1);
  Wait(1);
  Robot::m_driveTrain->TurnRight(0.5, 90, 0);
  Wait(1);
  Robot::m_driveTrain->DriveBackwards(0.25, 1, -0.1);
  Wait(1);
  Robot::m_driveTrain->TurnLeft(0.25, -90, 0);
  Robot::m_driveTrain->StopDriveMotors();

}

// Make this return true when this Command no longer needs to run execute()
bool AutoCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void AutoCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoCMD::Interrupted() {}
