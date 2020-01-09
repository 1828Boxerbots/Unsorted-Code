/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Victor.h>
#include "../include/RobotMap.h"
#include <frc/commands/Subsystem.h>
#include <frc/XBoxController.h>

class DriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;

  //objects
  frc::Victor m_motorL {PWM_MOTOR_LEFT};
  frc::Victor m_motorR {PWM_MOTOR_RIGHT};
  double m_scale = 0.3;
  //functions
  void MoveArcade(double X, double Y);
  void MoveTank(double left, double right);
  double Limit(double value, double lowerLimit = -1.0, double upperLimit = 1.0);
  void Stop();

};
