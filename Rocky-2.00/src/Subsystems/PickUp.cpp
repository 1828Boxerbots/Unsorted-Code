/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PickUp.h"
#include "../RobotMap.h"

#include <WPILib.h>

using namespace frc;

PickUp::PickUp() : Subsystem("ExampleSubsystem")
{

}

void PickUp::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void PickUp::InvertMotor()
{
	m_pickUp.SetInverted(false);
}

void PickUp::Up(XboxController* bumper)
{
	bool rightBumper = bumper->GetBumper(GenericHID::kRightHand);

	if (rightBumper == true)
	{
		m_pickUp.Set(1);
	}
	else
	{
		m_pickUp.Set(0);
	}
}

void PickUp::Down(XboxController* bumper)
{
	bool leftBumper = bumper->GetBumper(GenericHID::kLeftHand);

	if (leftBumper == true)
	{
		m_pickUp.Set(1);
	}
	else
	{
		m_pickUp.Set(0);
	}
}
