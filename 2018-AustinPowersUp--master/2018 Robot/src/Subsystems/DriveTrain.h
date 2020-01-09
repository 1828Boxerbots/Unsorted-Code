#ifndef DriveTrain_H
#define DriveTrain_H

#include <WPILib.h>

#include <Spark.h>
#include <XboxController.h>
#include <Timer.h>
#include <Encoder.h>
#include <PIDController.h>
#include <Drive/DifferentialDrive.h>

#include "RobotMap.h"

#include <Commands/Subsystem.h>

class DriveTrain : public Subsystem
{
private:
	Spark m_leftDriveMotor {LEFT_DRIVE_MOTOR_PORT};
	Spark m_rightDriveMotor {RIGHT_DRIVE_MOTOR_PORT};

	Encoder *m_leftDriveEncoder = new Encoder(LEFT_DRIVE_ENCODER_PORT, LEFT_DRIVE_ENCODER_PORT, false, Encoder::EncodingType::k4X);
	Encoder *m_rightDriveEncoder = new Encoder(RIGHT_DRIVE_ENCODER_PORT, RIGHT_DRIVE_ENCODER_PORT, false, Encoder::EncodingType::k4X);

	Timer *timer = new Timer();

	DifferentialDrive drive {m_leftDriveMotor, m_rightDriveMotor};

public:
	DriveTrain();
	void InitDefaultCommand();
	void ResetMotors();
	void StopMotors();
	void Drive(double left, double right);
	void TeleopDrive(XboxController* controller);
	void AutoDriveTimed(double motorValue);
	void AutoDrive();
};

#endif  // DriveTrain_H
