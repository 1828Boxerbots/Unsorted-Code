/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "SpitOutCMD.h"

#include "Robot.h"

SpitOutCMD::SpitOutCMD()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());

}

// Called just before this Command runs the first time
void SpitOutCMD::Initialize()
{

}

// Called repeatedly when this Command is scheduled to run
void SpitOutCMD::Execute()
{
	Robot::pickup->Down(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool SpitOutCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void SpitOutCMD::End()
{
	Robot::pickup->Down(Robot::oi->GetJoystick());
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SpitOutCMD::Interrupted()
{

}
