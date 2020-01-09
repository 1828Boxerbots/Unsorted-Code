/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"

#include <iostream>
#include <memory>
#include <string>

#include <RobotDrive.h>
#include <XboxController.h>
#include <wpilib.h>
#include <SampleRobot.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Timer.h>
#include <DigitalInput.h>
#include <AnalogPotentiometer.h>
#include "Limit.h"

using namespace std;
using namespace frc;

Robot::Robot()
{
	m_drive_Left.SetExpiration(0.1);
	m_drive_Right.SetExpiration(0.1);
	m_lead_Screw_Left.SetExpiration(0.1);
	m_lead_Screw_Right.SetExpiration(0.1);
	m_arm.SetExpiration(0.1);
}

void Robot::RobotInit()
{
	m_drive_Left.SetInverted(true);
	m_drive_Right.SetInverted(false);
	m_lead_Screw_Left.SetInverted(true);
	m_lead_Screw_Right.SetInverted(false);
	m_arm.SetInverted(false);
}

void Robot::OperatorControl()
{
	double leftX;
	double leftY;
	//double rightX;

	while (IsOperatorControl() && IsEnabled())
	{
		leftY = joystick.GetY(GenericHID::kLeftHand);
		leftX = joystick.GetX(GenericHID::kLeftHand);
		//rightX = joystick.GetX(GenericHID::kRightHand);

		// Drive with arcade style
		leftX = Limit(0.5,-0.5, leftX);
		leftY = Limit(0.5,-0.5, leftY);

		drive.ArcadeDrive(-leftX,leftY,false);

		//Arm
		double arm_pot = m_arm_Pot.Get();
		SmartDashboard::PutNumber("Arm_Pot", arm_pot);

		bool close = joystick.GetBButton();
		bool open = joystick.GetXButton();

		if (open == true)
		{
			if (arm_pot > 0.18)
			{
				m_arm.Set(-0.75);
			}
			else
			{
				m_arm.Set(0);
			}
		}
		if (close == true)
		{
			if (arm_pot < .54)
			{
				m_arm.Set(0.75);
			}
			else
			{
				m_arm.Set(0);
			}
		}
		else
		{
			m_arm.Set(0);
		}

		 bool top = m_top.Get();
		 bool bottom = m_bottom.Get();

		 bool leftBumper = joystick.GetBumper(GenericHID::kLeftHand);
		 bool rightBumper = joystick.GetBumper(GenericHID::kRightHand);

		 if (bottom == true)
		 {
			 StopScrew();
		 }
		 else
		 {
			 if (leftBumper == true)
			 {
				m_lead_Screw_Left.Set(1);
				m_lead_Screw_Right.Set(1);

			 }
			 else
			 {
				 StopScrew();
			 }
		 }
		 if (top == true)
		 {
			 StopScrew();
		 }
		 else
		 {
			 if (rightBumper == true)
			 {
				m_lead_Screw_Left.Set(-1);
				m_lead_Screw_Right.Set(-1);

			 }
			 else
			 {
				 StopScrew();
			 }
		 }

	}

	frc::Wait(0.005);
}
void Robot::StopScrew ()
{
	m_lead_Screw_Left.Set(0);
	m_lead_Screw_Right.Set(0);
}
void Robot::MoveScrew (bool up)
{
	if (up == true)
	{
		m_lead_Screw_Left.Set(-0.5);
		m_lead_Screw_Right.Set(-0.5);
	}
	else
	{
		m_lead_Screw_Left.Set(0.5);
		m_lead_Screw_Right.Set(0.5);
	}
}
START_ROBOT_CLASS(Robot)
