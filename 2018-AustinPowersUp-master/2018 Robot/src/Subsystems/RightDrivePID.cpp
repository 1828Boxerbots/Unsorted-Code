/*
#include "RightDrivePID.h"

#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/PIDSubsystem.h>
#include <WPILib.h>

#include "../RobotMap.h"


RightDrivePID::RightDrivePID() : PIDSubsystem("RightDrivePID", 1.0, 0.0, 0.0)
{
	m_joystick = 0.0;

	SetSetpoint(rightEncoderRawRate);

	Enable();
}

double RightDrivePID::ReturnPIDInput() {
	// Return your input value for the PID loop
	// e.g. a sensor, like a potentiometer:
	// yourPot->SetAverageVoltage() / kYourMaxVoltage;
	return  m_rightDriveEncoder->GetRate();;
}

void RightDrivePID::UsePIDOutput(double output) {
	// Use output to drive your system, like a motor
	// e.g. yourMotor->Set(output);
	m_rightDriveMotor->Set(output);
}

void RightDrivePID::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
*/
