/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <memory>

#include <Commands/Command.h>
#include <SmartDashboard/SendableChooser.h>
#include <TimedRobot.h>


#include "OI.h"


#include "Commands/TeleOpDriveCMD.h"
#include "Commands/PickUpCMD.h"
#include "Commands/SpitOutCMD.h"
#include "Commands/TurrentCMD.h"

#include "Subsystems/DriveTrain.h"
#include "Subsystems/PickUp.h"
#include "Subsystems/Shooter.h"
#include "Subsystems/Turrent.h"


using namespace frc;
using namespace std;
class Robot : public frc::TimedRobot
{
private:

	TeleOpDriveCMD m_teleopDriveCMD;
	PickUpCMD m_pickUpCMD;
	SpitOutCMD m_spitOutCMD;
	TurrentCMD m_turrent;


	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestPeriodic() override;

public:
	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.
	static shared_ptr<DriveTrain> drivetrain;
	static shared_ptr<PickUp> pickup;
	static shared_ptr<Shooter> shooter;
	static shared_ptr<Turrent> turrent;

	static shared_ptr<OI> oi;
};
