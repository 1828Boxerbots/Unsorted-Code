/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <WPILib.h>
#include <XboxController.h>

#include "RobotMap.h"

#pragma once

class OI
{
public:
	OI();
	XboxController* GetJoystick();

private:
	XboxController controller {XBOX_PORT};

	JoystickButton m_leftBumper{&controller, 5};
	JoystickButton m_rightBumper{&controller, 6};
};
