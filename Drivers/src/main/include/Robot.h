// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#pragma once
#include <frc/Victor.h>
#include <frc/encoder.h>
#include <string>
#include "Drivers/imu.hpp"
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

class Robot : public frc::TimedRobot {
 public:
  float m_Speed();
  void RobotInit() override;
  void RobotPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void TestInit() override;
  void TestPeriodic() override;

 private:
 frc::Victor m_shooterMotor{3};
float dist_old;
float time_old;
frc2::Timer m_timer;  
Imu* m_pImurBoi = new Imu();
  frc::Encoder m_encoder1{0, 1, false, frc::Encoder::EncodingType::k4X};
  frc::Encoder m_encoder3{4, 5, false, frc::Encoder::EncodingType::k4X};
  frc::Encoder m_encoder2{2, 3, true, frc::Encoder::EncodingType::k4X}; 
  frc::SendableChooser<std::string> m_chooser;
  const std::string kAutoNameDefault = "Default";
  const std::string kAutoNameCustom = "My Auto";
  std::string m_autoSelected;
};
