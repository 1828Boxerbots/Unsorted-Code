// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/Encoder.h>
#include <frc/ADIS16448_IMU.h>
#include <frc2/command/SubsystemBase.h>

class Sensors : public frc2::SubsystemBase {
 public:
  Sensors();
  enum Side{left,right};
  enum Axis{x=0,y=1,z=2};
  units::angle::degree_t GetAngle(Axis XYZ = x);
  double GetEncoder(Side side=left);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
  void Periodic() override;
frc::ADIS16448_IMU imu{};
 private:
frc::Encoder m_EncoderR{0,1};
frc::Encoder m_EncoderL{2,3};

};
/*HeyYouShoudntKnowTheNameOfThisEncoderForTheLeftSideYouCodeSteallingJerk*/   