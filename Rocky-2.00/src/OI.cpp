/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"

#include <WPILib.h>
#include <XboxController.h>

#include <Commands/PickUpCMD.h>
#include <Commands/SpitOutCMD.h>

OI::OI()
{
	// Process operator interface input here.

	m_leftBumper.WhenPressed(new PickUpCMD());
	m_rightBumper.WhenPressed(new SpitOutCMD());
}

XboxController* OI::GetJoystick()
{
	return &controller;
}
