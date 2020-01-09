/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace frc;
DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::TeleopDrive(XboxController* controller)
{
  double gyro = m_gyro.GetAngle();
  SmartDashboard::PutNumber("Gyro Angle", gyro);

  bool yButton = controller->GetYButton();
  bool bButton = controller->GetBButton();

  if (yButton == true)
  {
    double leftX = controller->GetX(frc::GenericHID::kLeftHand);
    double leftY = -controller->GetY(frc::GenericHID::kLeftHand);

    double rightoverallValue = -leftX + leftY;
    double leftoverallValue = leftX + leftY;

    double limitedRightOverallValue = util.Limit(.85, -.85, rightoverallValue);
    double limitedLeftOverallValue = util.Limit(.85, -.85, leftoverallValue);

    m_leftMotor.Set(limitedLeftOverallValue);
    m_rightMotor.Set(limitedRightOverallValue);
  }
  else
  {
    if (bButton == true)
    {
      double leftX = controller->GetX(frc::GenericHID::kLeftHand);
      double leftY = controller->GetY(frc::GenericHID::kLeftHand);

      double rightoverallValue = -leftX + leftY;
      double leftoverallValue = leftX + leftY;

      double limitedRightOverallValue = util.Limit(.5, -.5, rightoverallValue);
      double limitedLeftOverallValue = util.Limit(.5, -.5, leftoverallValue);

      m_leftMotor.Set(limitedLeftOverallValue);
      m_rightMotor.Set(limitedRightOverallValue);
    }
    else
    {
    double leftX = controller->GetX(frc::GenericHID::kLeftHand);
    double leftY = controller->GetY(frc::GenericHID::kLeftHand);

    double rightoverallValue = -leftX + leftY;
    double leftoverallValue = leftX + leftY;

    double limitedRightOverallValue = util.Limit(.85, -.85, rightoverallValue);
    double limitedLeftOverallValue = util.Limit(.85, -.85, leftoverallValue);

    m_leftMotor.Set(limitedLeftOverallValue);
    m_rightMotor.Set(limitedRightOverallValue);
    }
  }
}

void DriveTrain::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void DriveTrain::StopDriveMotors()
{
  m_leftMotor.Set(0.0);
  m_rightMotor.Set(0.0);
}
void DriveTrain::InvertMotors()
{
  m_leftMotor.SetInverted(false);
  m_rightMotor.SetInverted(true);
  m_gyro.Calibrate();
  m_gyro.Reset();
}
void DriveTrain::DriveForward(double motorPower, double gyroAngle, double negativeGyroAngle)
{
  double gyro = m_gyro.GetAngle();
  if ((gyro < gyroAngle) && (gyro > negativeGyroAngle))
  {
    m_leftMotor.Set(motorPower);
    m_rightMotor.Set(motorPower);
  }
}
void DriveTrain::TurnRight(double motorPower, double gyroAngle, double negativeGyroAngle)
{
  double gyro = m_gyro.GetAngle();
  if (gyro < gyroAngle)
  {
  m_leftMotor.Set(-motorPower);
  m_rightMotor.Set(motorPower);
  }
  else
  {
    StopDriveMotors();
  }
}
void DriveTrain::TurnLeft(double motorPower, double gyroAngle, double negativeGyroAngle)
{
  double gyro = m_gyro.GetAngle();
  if (gyro > negativeGyroAngle)
  {
  m_leftMotor.Set(motorPower);
  m_rightMotor.Set(-motorPower);
  }
  else
  {
    StopDriveMotors();
  }
}
void DriveTrain::DriveBackwards(double motorPower, double gyroAngle, double negativeGyroAngle)
{
  double gyro = m_gyro.GetAngle();
  if ((gyro < gyroAngle) && (gyro > negativeGyroAngle))
  {
    m_leftMotor.Set(-motorPower);
    m_rightMotor.Set(-motorPower);
  }
}