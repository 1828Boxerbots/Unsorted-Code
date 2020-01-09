/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include <string>

#include <wpilib.h>
#include <RobotDrive.h>
#include <XboxController.h>
#include <Drive/DifferentialDrive.h>
#include <SampleRobot.h>
#include <Talon.h>
#include <DigitalInput.h>
#include <AnalogPotentiometer.h>
#include <Limit.h>

using namespace frc;
using namespace std;

class Robot : public frc::SampleRobot
{
public:
	Robot();

	void RobotInit() override;
	void StopScrew();
	void MoveScrew(bool up);

	//void Autonomous() override;
	void OperatorControl() override;
	//void Test() override;

private:
	const int USB_PORT_JOYSTICK = 0;
	const int PMW_DRIVE_LEFT = 0;
	const int PWM_DRIVE_RIGHT = 1;
	const int LEAD_SCREW_LEFT = 3;
	const int LEAD_SCREW_RIGHT = 2;
	const int ARM = 4;
	const int TOP_LIMIT = 7;
	const int BOTTOM_LIMIT = 6;
	const int MAX_SCREW_SPEED = 0.25;
	const int POT_PORT = 0;

	DigitalInput m_top {TOP_LIMIT};
	DigitalInput m_bottom {BOTTOM_LIMIT};

	AnalogPotentiometer m_arm_Pot {POT_PORT};

	XboxController joystick {USB_PORT_JOYSTICK};

	DifferentialDrive drive {m_drive_Left,m_drive_Right};
	Talon m_drive_Left {PMW_DRIVE_LEFT};
	Talon m_drive_Right {PWM_DRIVE_RIGHT};

	Talon m_lead_Screw_Left {LEAD_SCREW_LEFT};
	Talon m_lead_Screw_Right {LEAD_SCREW_RIGHT};

	Talon m_arm {ARM};
};
