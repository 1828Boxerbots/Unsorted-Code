/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <WPILib.h>

#include "Turrent.h"
#include "../RobotMap.h"

using namespace frc;
Turrent::Turrent() : Subsystem("ExampleSubsystem")
{

}

void Turrent::InitDefaultCommand()
{
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void Turrent::InvertMotor()
{
	m_turrent.SetInverted(false);
}

void Turrent::Movement(XboxController* controller)
{
	double rightX = controller->GetX(GenericHID::kRightHand);

	m_turrent.Set(rightX);

}
