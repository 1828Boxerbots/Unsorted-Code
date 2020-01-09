/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <iostream>

using namespace std;
using namespace frc;

shared_ptr<DriveTrain> Robot::drivetrain = make_shared<DriveTrain>();
shared_ptr<PickUp> Robot::pickup = make_shared<PickUp>();
shared_ptr<Turrent> Robot::turrent = make_shared<Turrent>();
shared_ptr<Shooter> Robot::shooter = make_shared<Shooter>();
shared_ptr<OI> Robot::oi = make_shared<OI>();

void Robot::RobotInit()
{

}

/**
 * This function is called once each time the robot enters Disabled mode. You
 * can use it to reset any subsystem information you want to clear when the
 * robot is disabled.
 */
void Robot::DisabledInit() {}

void Robot::DisabledPeriodic()
{
	Scheduler::GetInstance()->Run();
}

/**
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString code to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional commands to the
 * chooser code above (like the commented example) or additional comparisons to
 * the if-else structure below with additional strings & commands.
 */
void Robot::AutonomousInit()
{

}

void Robot::AutonomousPeriodic()
{
	Scheduler::GetInstance()->Run();
}

void Robot::TeleopInit()
{
	// This makes sure that the autonomous stops running when
	// teleop starts running. If you want the autonomous to
	// continue until interrupted by another command, remove
	// this line or comment it out.
	m_teleopDriveCMD.Start();
	m_pickUpCMD.Start();
	m_spitOutCMD.Start();
	m_turrent.Start();

}

void Robot::TeleopPeriodic()
{
	frc::Scheduler::GetInstance()->Run();
}

void Robot::TestPeriodic() {}

START_ROBOT_CLASS(Robot)
