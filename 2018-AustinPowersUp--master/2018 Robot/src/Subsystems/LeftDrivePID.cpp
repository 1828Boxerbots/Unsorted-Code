/*
#include "LeftDrivePID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>

#include "../RobotMap.h"

LeftDrivePID::LeftDrivePID() : PIDSubsystem("LeftDrivePID", 1.0, 0.0, 0.0)
{
	m_joystick = 0.0;

	SetSetpoint(leftEncoderRate);

	Enable();
}

double LeftDrivePID::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return m_leftDriveEncoder->Get();;

}

void LeftDrivePID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	m_leftDriveMotor->Set(output);
}

void LeftDrivePID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
*/
