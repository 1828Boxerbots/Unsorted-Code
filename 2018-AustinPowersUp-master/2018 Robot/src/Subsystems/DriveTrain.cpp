/* testing github */

#include <WPILib.h>

#include "DriveTrain.h"
#include "../RobotMap.h"
#include "Util.h"

using namespace frc;
using namespace util;

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem")
{

}

void DriveTrain::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::ResetMotors()
{
	m_leftDriveMotor.Set(0);
	m_rightDriveMotor.Set(0);
}

void DriveTrain::StopMotors()
{
	/* Implement a PID to Ramp the motors down */

	m_leftDriveMotor.Set(0);
	m_rightDriveMotor.Set(0);
}

void DriveTrain::Drive(double left, double right)
{
	drive.ArcadeDrive(left, right);
}

void DriveTrain::TeleopDrive(XboxController* controller)
{
	Drive(-controller->GetX(GenericHID::kRightHand),
			-controller->GetY(GenericHID::kRightHand));
}

void DriveTrain::AutoDriveTimed(double motorValue)
{
	/* Reset on Startup */
	timer->Reset();

	/* Start the timer */
	timer->Start();

	/* Enter when timer is less than and equal to 15 seconds */
	if(timer->Get() <= 15)
	{
		/* Inverts the left motors */
		m_leftDriveMotor.SetInverted(true);

		/* Set the drive motors to run at 50% power for duration on the timer */
		m_leftDriveMotor.Set(motorValue);
		m_rightDriveMotor.Set(motorValue);
	}
	/* Enter once time is no longer less than or equal to 15 seconds */
	else
	{
		timer->Reset();
	}

}

void DriveTrain::AutoDrive()
{
	/* Inverts the left motors */
	m_leftDriveMotor.SetInverted(true);

	/* Set the drive motors to run at 75%*/
	m_leftDriveMotor.Set(0.75);
	m_rightDriveMotor.Set(0.75);

	/*Waits for a little bit to at lest allow the entire loop to execute */
	Wait(0.1);
}
