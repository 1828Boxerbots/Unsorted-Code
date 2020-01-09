/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include <frc/Talon.h>
#include <frc/Encoder.h>
#include <frc/XboxController.h>
#include <frc/ADXRS450_Gyro.h>
#include <Robotmap.h>
using namespace frc;
class DriveTrain : public frc::Subsystem {
 private:
  Talon m_leftMotor{LEFT_DRIVE_MOTOR_PWM};
  Talon m_rightMotor{RIGHT_DRIVE_MOTOR_PWM};

  Encoder m_leftMotorEncoder {LEFT_ENCODER_CHANNEL_A, LEFT_ENCODER_CHANNEL_B, false , Encoder::EncodingType::k4X};
  Encoder m_rightMotorEncoder {RIGHT_ENCODER_CHANNEL_A, RIGHT_ENCODER_CHANNEL_B, false , Encoder::EncodingType::k4X};

  ADXRS450_Gyro m_gyro{SPI::kOnboardCS0};

  const double WHEEL_RADIUS = 3;
  void LogData();

  

 public:
  DriveTrain();
  void InitDefaultCommand() override;
  void Teleop(XboxController* pController);
  void Move(double speed, double time);
  void Turn(double angle);
  void TurnRelitive(double angle);
  void StopMotor();
  void Init();




};
