/*
#include <Encoder.h>
#include <Spark.h>

#include "RobotMap.h"

#ifndef RightDrivePID_H
#define RightDrivePID_H

#include <Commands/PIDSubsystem.h>

class RightDrivePID : public PIDSubsystem {
public:
	RightDrivePID();
	double ReturnPIDInput();
	void UsePIDOutput(double output);
	void InitDefaultCommand();

private:
	double m_joystick;

	Encoder *m_rightDriveEncoder = new Encoder(RIGHT_DRIVE_MOTOR_PORT, RIGHT_DRIVE_MOTOR_PORT, false, Encoder::EncodingType::k4X);

	Spark *m_rightDriveMotor = new Spark(RIGHT_DRIVE_MOTOR_PORT);

	double rightEncoderRawRate = m_rightDriveEncoder->Get();
};

#endif  // RightDrivePID_H
*/
