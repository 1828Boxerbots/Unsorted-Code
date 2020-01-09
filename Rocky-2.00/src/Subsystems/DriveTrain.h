/*
 * DriveTrain.h
 *
 *  Created on: Nov 12, 2018
 *      Author: FIRSTMentor
 */

#ifndef SRC_SUBSYSTEMS_DRIVETRAIN_H_
#define SRC_SUBSYSTEMS_DRIVETRAIN_H_

#include <WPILib.h>

#include <Spark.h>
#include <XboxController.h>
#include <Drive/DifferentialDrive.h>

#include "RobotMap.h"

#include <Commands/Subsystem.h>

class DriveTrain : public Subsystem
{
private:
	Spark m_leftDriveMotor{LEFT_DRIVE_MOTOR_PORT};
	Spark m_rightDriveMotor{RIGHT_DRIVE_MOTOR_PORT};

	DifferentialDrive drive {m_leftDriveMotor, m_rightDriveMotor};

public:
	DriveTrain();
	void StopMotors();
	void ResetMotors();
	void TeleopDrive (XboxController* controller);
	void Drive (double left, double right);
	void InvertMotors();
	double Limit(double upperLimit, double lowerLimit, double value);

};


#endif /* SRC_SUBSYSTEMS_DRIVETRAIN_H_ */
