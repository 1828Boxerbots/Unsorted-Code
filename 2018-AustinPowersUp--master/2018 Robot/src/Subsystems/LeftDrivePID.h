/*
#include <Encoder.h>
#include <Spark.h>

#include "RobotMap.h"

#ifndef LeftDrivePID_H
#define LeftDrivePID_H

#include <Commands/PIDSubsystem.h>

class LeftDrivePID : public PIDSubsystem {
public:
	LeftDrivePID();
	double ReturnPIDInput(double encoderRate);
	void UsePIDOutput(double output);
	void InitDefaultCommand();

private:

	double m_joystick;

	Encoder	*encoderRate = new Encoder(LEFT_DRIVE_ENCODER_PORT, LEFT_DRIVE_ENCODER_PORT, false, Encoder::EncodingType::k4X);

	Spark *m_leftDriveMotor = new Spark(LEFT_DRIVE_MOTOR_PORT);

	double encoder = encoderRate->Get();
};

#endif  // LeftDrivePID_H
*/
