/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Spark.h>
#include <frc/XboxController.h>
#include <frc/Encoder.h>
#include "RobotMap.h"
#include "Util.h"
#include <frc/ADXRS450_Gyro.h>

using namespace frc;
class DriveTrain : public frc::Subsystem 
{
 private:
  
  //Encoder m_leftMotorEncoder {LEFT_ENCODER_CHANNEL_A, LEFT_ENCODER_CHANNEL_B, false , Encoder::EncodingType::k4X};
  //Encoder m_rightMotorEncoder {RIGHT_ENCODER_CHANNEL_A, RIGHT_ENCODER_CHANNEL_B, false , Encoder::EncodingType::k4X};
  Spark m_leftMotor {LEFTMOTOR};
  Spark m_rightMotor {RIGHTMOTOR};
  Util util;
  ADXRS450_Gyro m_gyro{SPI::kOnboardCS0};

  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;
  void TeleopDrive(XboxController* controller);
  void StopDriveMotors();
  void InvertMotors();
  void DriveForward(double motorPower, double gyroAngle, double negativeGyroAngle);
  void TurnRight(double motorPower, double gyroAngle, double negativeGyroAngle);
  void TurnLeft(double motorPower, double gyroAngle, double negativeGyroAngle);
  void DriveBackwards(double motorPower, double gyroAngle, double negativeGyroAngle);
};