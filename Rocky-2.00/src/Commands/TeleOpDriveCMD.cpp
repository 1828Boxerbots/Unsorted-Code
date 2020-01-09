/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "TeleOpDriveCMD.h"

#include "Robot.h"
#include "OI.h"
#include "Subsystems/DriveTrain.h"

using namespace frc;
using namespace std;
TeleOpDriveCMD::TeleOpDriveCMD()
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void TeleOpDriveCMD::Initialize()
{
	Robot::drivetrain->ResetMotors();
}

// Called repeatedly when this Command is scheduled to run
void TeleOpDriveCMD::Execute()
{
	Robot::drivetrain->TeleopDrive(Robot::oi->GetJoystick());
}

// Make this return true when this Command no longer needs to run execute()
bool TeleOpDriveCMD::IsFinished()
{
	return false;
}

// Called once after isFinished returns true
void TeleOpDriveCMD::End()
{
	Robot::drivetrain->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleOpDriveCMD::Interrupted()
{
	Robot::drivetrain->StopMotors();
}
