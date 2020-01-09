/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>

#include <XboxController.h>
#include <Spark.h>

#include "RobotMap.h"

using namespace frc;

class Shooter : public Subsystem
{
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	Spark m_shooter {SHOOTER_PORT};
public:
	Shooter();
	void InitDefaultCommand() override;
	void Fire(XboxController* trigger);
	void InvertMotor();
};

