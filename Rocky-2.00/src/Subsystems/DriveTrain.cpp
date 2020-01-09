/*
 * DriveTrain.cpp
 *
 *  Created on: Nov 12, 2018
 *      Author: FIRSTMentor
 */

#include <WPILib.h>

#include "DriveTrain.h"
#include "../RobotMap.h"

using namespace frc;

DriveTrain::DriveTrain() : Subsystem("DriveTrain")
{

}

void DriveTrain::ResetMotors()
{
	m_leftDriveMotor.Set(0);
	m_rightDriveMotor.Set(0);
}
void DriveTrain::InvertMotors()
{
	m_leftDriveMotor.SetInverted(true);
	m_rightDriveMotor.SetInverted(false);
}

void DriveTrain::StopMotors()
{
	m_leftDriveMotor.Set(0);
	m_rightDriveMotor.Set(0);
}

void DriveTrain::Drive(double left, double right)
{
	drive.ArcadeDrive(left, right);
}

void DriveTrain::TeleopDrive(XboxController* controller)
{
	double leftY = controller->GetY(GenericHID::kLeftHand);
	double leftX = controller->GetX(GenericHID::kLeftHand);

	leftY = Limit(1, -1, leftY);
	leftX = Limit(1, -1, leftX);

	Drive(-leftY, leftX);
}

double DriveTrain::Limit (double upperLimit, double lowerLimit, double value)
{
	if(value >= upperLimit)
	{
		value = upperLimit;
		return value;
	}

	if(value <= lowerLimit)
	{
		value = lowerLimit;
		return value;
	}

	else
	{
		return value;
	}
}
