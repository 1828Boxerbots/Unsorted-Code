/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/smartdashboard/SmartDashboard.h>
#include "subsystems/DriveTrain.h"


DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem")
{

}

void DriveTrain::Init()
{
  m_leftMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * WHEEL_RADIUS);
  m_rightMotorEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * WHEEL_RADIUS);
  m_gyro.Calibrate();
  m_leftMotor.SetInverted(true);
  m_rightMotor.SetInverted(false);
}

void DriveTrain::LogData()
{
  
  
  double leftEncoder = m_leftMotorEncoder.GetRate();
  double rightEncoder = m_rightMotorEncoder.GetRate();

  frc::SmartDashboard::PutNumber("Left Encoder", leftEncoder);
  frc::SmartDashboard::PutNumber("Right Encoder", rightEncoder);

  double angle = m_gyro.GetAngle();
  double rate = m_gyro.GetRate();

  frc::SmartDashboard::PutNumber("gyro angle", angle);
  frc::SmartDashboard::PutNumber("gyro rate", rate);

}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void DriveTrain::StopMotor()
{
  m_leftMotor.Set(0.0);
  m_rightMotor.Set(0.0);
}

void DriveTrain::Move(double speed, double time)
{
  m_leftMotor.Set(-speed);
  m_rightMotor.Set(-speed);
  
  LogData();
  Wait(time);
  StopMotor();
};
void DriveTrain::Turn(double angle)
{
  double gyroAngle = m_gyro.GetAngle();
  if (angle > 0.0)
  {
    while(angle > gyroAngle)
    {
      m_leftMotor.Set(-0.5);
      m_rightMotor.Set(0.5);
      gyroAngle = m_gyro.GetAngle();
      LogData(); 
    }
  }
  if(angle < 0.0)
  {
    while(angle < gyroAngle)
    {
      m_leftMotor.Set(0.5);
      m_rightMotor.Set(-0.5);
      gyroAngle = m_gyro.GetAngle(); 
      LogData();
    }
  }
  StopMotor();
}

void DriveTrain::TurnRelitive(double angle)
{
  double gyroAngle = m_gyro.GetAngle();
  Turn( gyroAngle + angle);
}

void DriveTrain::Teleop(XboxController* pController)
{
  double LeftX = pController->GetX(GenericHID::kLeftHand);
  double LeftY = pController->GetY(GenericHID::kLeftHand);

  m_leftMotor.Set(LeftY + LeftX);
  m_rightMotor.Set(LeftY - LeftX);

  LogData();


}



// Put methods for controlling this subsystem
// here. Call these from Commands.
