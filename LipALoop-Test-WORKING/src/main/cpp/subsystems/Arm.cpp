/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/


#include "../include/subsystems/Arm.h"

Arm::Arm() : Subsystem("Arm") {}

void Arm::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  m_handAngle = 0.0;
  m_armAngle = 0.0;
  m_wristAngle = 90.0;
}

void Arm::Open()
{
  OpenHand(++m_handAngle);
}

void Arm::Close()
{
  OpenHand(--m_handAngle);
}

void Arm::OpenHand(double angle)
{
  m_servoHand.SetAngle(angle);
}

void Arm::Lift()
{
  LiftArm(++m_armAngle);
}

void Arm::Lower()
{
  LiftArm(--m_armAngle);
}

void Arm::LiftArm(double angle)
{
  m_servoArm.SetAngle(angle);
  m_servoWrist.SetAngle(m_wristAngle + angle);
}

void Arm::TiltDown()
{
  m_servoWrist.SetAngle(--m_wristAngle);
}

void Arm::TiltUp()
{
  m_servoWrist.SetAngle(++m_wristAngle);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
