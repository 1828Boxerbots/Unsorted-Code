#include "AutoDriveCmd.h"

#include "Subsystems/DriveTrain.h"

#include "Robot.h"

AutoDriveCmd::AutoDriveCmd() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::drivetrain.get());
}

// Called just before this Command runs the first time
void AutoDriveCmd::Initialize()
{
	Robot::drivetrain->ResetMotors();
}

// Called repeatedly when this Command is scheduled to run
void AutoDriveCmd::Execute()
{
	Robot::drivetrain->AutoDriveTimed(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDriveCmd::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void AutoDriveCmd::End()
{
	Robot::drivetrain->StopMotors();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDriveCmd::Interrupted()
{
	Robot::drivetrain->StopMotors();
}
