// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.
#define ROTATION double(17.3/360)
#include "Robot.h"
#include <frc2/Timer.h>
#include "Drivers/imu.hpp"
#include <iostream>
#include <frc/Encoder.h>
#define boi m_pImurBoi->
#include <frc/shuffleboard/BuiltInWidgets.h>
#include <frc/smartdashboard/SmartDashboard.h>

void Robot::RobotInit() {
  m_chooser.SetDefaultOption(kAutoNameDefault, kAutoNameDefault);
  m_chooser.AddOption(kAutoNameCustom, kAutoNameCustom);
  frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
}

/*
 * This function is called every robot packet, no matter the mode. Use
 * this for items like diagnostics that you want ran during disabled,
 * autonomous, teleoperated and test.
 *
 * This runs after the mode specific periodic functions, but before
 * LiveWindow and SmartDashboard integrated updating.
 */
void Robot::RobotPeriodic() {}

/*
 * This autonomous (along with the chooser code above) shows how to select
 * between different autonomous modes using the dashboard. The sendable chooser
 * code works with the Java SmartDashboard. If you prefer the LabVIEW Dashboard,
 * remove all of the chooser code and uncomment the GetString line to get the
 * auto name from the text box below the Gyro.
 *
 * You can add additional auto modes by adding additional comparisons to the
 * if-else structure below with additional strings. If using the SendableChooser
 * make sure to add them to the chooser code above as well.
 */
void Robot::AutonomousInit() {
  m_autoSelected = m_chooser.GetSelected();
  // m_autoSelected = SmartDashboard::GetString("Auto Selector",
  //     kAutoNameDefault);
  std::cout << "Auto selected: " << m_autoSelected << std::endl;

  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}

void Robot::AutonomousPeriodic() {
  if (m_autoSelected == kAutoNameCustom) {
    // Custom Auto goes here
  } else {
    // Default Auto goes here
  }
}
void Robot::TeleopInit() {}

void Robot::TeleopPeriodic() {}

void Robot::DisabledInit() {} 

void Robot::DisabledPeriodic() {}

void Robot::TestInit() {
dist_old = m_encoder3.GetDistance();
m_timer.Start();
m_pImurBoi->Reset();
m_encoder1.Reset();
m_encoder2.Reset();
m_encoder1.SetDistancePerPulse(ROTATION);
m_encoder2.SetDistancePerPulse(ROTATION );
m_encoder3.SetDistancePerPulse(0.05);
}

float Robot::m_Speed(){
float speed= m_encoder3.GetDistance() - dist_old;
if(m_timer.HasElapsed(1_s)){
  dist_old = m_encoder3.GetDistance();
  m_timer.Reset();
}
  return (speed)*60;
}

void Robot::TestPeriodic() {
m_shooterMotor.SetSpeed(-0.25);
frc::SmartDashboard::PutNumber("Imurboi's X",boi getAngle(Imu::x));
frc::SmartDashboard::PutNumber("Imurboi's Y",boi getAngle(Imu::y));
frc::SmartDashboard::PutNumber("Imurboi's Z",boi getAngle(Imu::z));
frc::SmartDashboard::PutNumber("Encoder1",m_encoder1.GetRaw());
frc::SmartDashboard::PutNumber("Encoder2",m_encoder2.GetRaw());
frc::SmartDashboard::PutNumber("Encoder1Dist",m_encoder1.GetDistance());
frc::SmartDashboard::PutNumber("Encoder2Dist",m_encoder2.GetDistance());
frc::SmartDashboard::PutNumber("SPEEEEEEEDY",m_encoder3.GetRate()*60);
frc::SmartDashboard::PutNumber("Janky Speed",m_Speed());
frc::SmartDashboard::PutNumber("Diffrence", m_Speed()-(m_encoder3.GetRate()*60));
frc::SmartDashboard::PutNumber("Get Shooter", m_encoder3.Get());
}

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif