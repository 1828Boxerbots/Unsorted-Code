// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include <frc/motorcontrol/Victor.h>
#include <frc2/command/SubsystemBase.h>
class DriveTrain : public frc2::SubsystemBase {
 public:
  DriveTrain();
void SetLeft(float power);
void SetRight(float power);
  /**
   * Will be called periodically whenever the CommandScheduler runs.
   */
 void Periodic() override;

 private:
  frc::Victor m_motorL{1};
  frc::Victor m_motorR{0};
  // Components (e.g. motor controllers and sensors) should generally be
  // declared private and exposed only through public methods.
};
