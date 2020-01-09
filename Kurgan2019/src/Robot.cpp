/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <frc/smartdashboard/SmartDashboard.h>
#include <Timer.h>
#include <XboxController.h>


using namespace std;
using namespace frc;


	const int Drive_Front_Right = 3;
	const int Drive_Back_Right = 4;
	const int Drive_Front_Left =1;
	const int Drive_Back_Left =2;
	const int Shooter_Front_Right = 5;
	const int Shooter_Back_Right = 8;
	const int Shooter_Front_Left = 6;
	const int Shooter_Back_Left = 7;
	const int Pickup = 0;
	const int Pickup_Sensor = 0;
	const int Xbox = 1;
/*
	const int Drive_Front_Right = 3;
	const int Drive_Back_Right = 4;
	const int Drive_Front_Left =1;
	const int Drive_Back_Left =2;
	const int Shooter_Front_Right = 5;
	const int Shooter_Back_Right = 8;
	const int Shooter_Front_Left = 6;
	const int Shooter_Back_Left = 7;
	const int Pickup = 0;
	const int Pickup_Sensor = 0;
	const int Xbox = 0;
*/
	XboxController joystick {Xbox};

	Spark m_driveFrontRight {Drive_Front_Right};
	Spark m_driveBackRight {Drive_Back_Right};
	Spark m_driveFrontLeft {Drive_Front_Left};
	Spark m_driveBackLeft {Drive_Back_Left};

	Spark m_shooterFrontRight {Shooter_Front_Right};
	Spark m_shooterBackRight {Shooter_Back_Right};
	Spark m_shooterFrontLeft {Shooter_Front_Left};
	Spark m_shooterBackLeft {Shooter_Back_Left};

	Spark m_pickUp {Pickup};

	DigitalInput m_sensor {Pickup_Sensor};

Robot::Robot()
		{
			m_driveFrontRight.SetExpiration(0.01);
			m_driveBackRight.SetExpiration(0.01);
			m_driveFrontLeft.SetExpiration(0.01);
			m_driveBackLeft.SetExpiration(0.01);

			m_shooterFrontRight.SetExpiration(0.01);
			m_shooterBackRight.SetExpiration(0.01);
			m_shooterFrontLeft.SetExpiration(0.01);
			m_shooterBackLeft.SetExpiration(0.01);
		}


	void Robot::RobotInit()
		{
			m_driveFrontRight.SetInverted(false);
			m_driveBackRight.SetInverted(false);
			m_driveFrontLeft.SetInverted(true);
			m_driveBackLeft.SetInverted(true);

			m_shooterFrontRight.SetInverted(false);
			m_shooterBackRight.SetInverted(false);
			m_shooterFrontLeft.SetInverted(true);
			m_shooterBackLeft.SetInverted(true);
		}


	void Robot::OperatorControl()
	{

		double leftY;
		double rightY;

	while (IsOperatorControl() && IsEnabled())
		{
		leftY = joystick.GetY(GenericHID::kLeftHand);
		rightY = joystick.GetY(GenericHID::kRightHand);

		// Drive
		m_driveFrontRight.Set(rightY);
		m_driveBackRight.Set(rightY);
		m_driveFrontLeft.Set(leftY);
		m_driveBackLeft.Set(leftY);

		//PickUp
		bool dio = m_sensor.Get();
		bool buttonX = joystick.GetXButton();
		bool buttonB = joystick.GetBButton();
		bool buttonA = joystick.GetAButton();

		if (dio == true)
		{
			if (buttonA == true)
			{
				m_pickUp.Set(1);
			}
			else
			{
				m_pickUp.Set(0);
			}
		}
		else
		{
			if (buttonX == true)
			{
				m_pickUp.Set(1);
			}
			if (buttonB == true)
			{
				m_pickUp.Set(-1);
			}
			else
			{
				m_pickUp.Set(0);
			}
		}

	 //Shooter
		bool rightBumper = joystick.GetBumper(GenericHID::kRightHand);

		if (rightBumper == true)
		{
			m_shooterFrontRight.Set(1);
			m_shooterBackRight.Set(1);
			m_shooterFrontLeft.Set(1);
			m_shooterBackLeft.Set(1);
		}
		else
		{
			m_shooterFrontRight.Set(0);
			m_shooterBackRight.Set(0);
			m_shooterFrontLeft.Set(0);
			m_shooterBackLeft.Set(0);
		}


		// The motors will be updated every 5ms
		Wait(0.005);
	
		}
	
	}

START_ROBOT_CLASS(Robot)
