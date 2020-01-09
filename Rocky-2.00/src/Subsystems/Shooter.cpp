/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <WPILib.h>

#include "Shooter.h"
#include "../RobotMap.h"

Shooter::Shooter() : Subsystem("ExampleSubsystem")
{

}

void Shooter::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void Shooter::InvertMotor()
{
	m_shooter.SetInverted(false);
}

void Shooter::Fire(XboxController* trigger)
{
	double leftTrigger = trigger->GetTriggerAxis(GenericHID::kLeftHand);

	m_shooter.Set(leftTrigger);
}
