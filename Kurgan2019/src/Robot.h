/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/drive/DifferentialDrive.h>
#include <frc/XboxController.h>
#include <frc/SampleRobot.h>
#include <frc/DigitalInput.h>
#include <frc/SmartDashboard/SendableChooser.h>
#include <frc/Spark.h>


/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * The SampleRobot class is the base of a robot application that will
 * automatically call your Autonomous and OperatorControl methods at the right
 * time as controlled by the switches on the driver station or the field
 * controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use IterativeRobot or Command-Based
 * instead if you're new.
 */
class Robot : public frc::SampleRobot
{
public:
	Robot();

	void RobotInit() override;
	//void Autonomous() override;
	void OperatorControl() override;
	//void Test() override;

private:
	// Robot drive system
	/*frc::Spark m_leftMotor{0};
	frc::Spark m_rightMotor{1};
	frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};



	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";*/

	const int Drive_Front_Right = 3;
	const int Drive_Back_Right = 4;
	const int Drive_Front_Left = 1;
	const int Drive_Back_Left = 2;

	const int Shooter_Front_Right = 5;
	const int Shooter_Back_Right = 8;
	const int Shooter_Front_Left = 6;
	const int Shooter_Back_Left = 7;
 
	const int Pickup = 0;

	const int Pickup_Sensor = 0;

	const int Xbox = 1;

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
};
