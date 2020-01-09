/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/subsystems/DriveTrain.h"

DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}

void DriveTrain::InitDefaultCommand() {
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
  m_motorL.SetInverted(false);
  m_motorR.SetInverted(true);
}

const double NOPOWER = 0.0;

double DriveTrain::Limit(double value, double lowerLimit, double upperLimit)
{
  if(lowerLimit > upperLimit)
  {
    double replace = lowerLimit;
    lowerLimit = upperLimit;
    upperLimit = replace;
  }

  if(value < lowerLimit)
  {
    value = lowerLimit;
  }

  if(value > upperLimit)
  {
    value = upperLimit;
  }
  return(value);
}

void DriveTrain::MoveTank(double left, double right)
{
  left = Limit(left);
  right = Limit(right);
  m_motorL.Set(left * m_scale);
  m_motorR.Set(right * m_scale);
}

void DriveTrain::MoveArcade(double X, double Y)
{
  double left = -X + Y;
  double right = -X + Y;
  MoveTank(left, right);
}

void DriveTrain::Stop()
{
  m_motorL.Set(NOPOWER);
  m_motorR.Set(NOPOWER);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
