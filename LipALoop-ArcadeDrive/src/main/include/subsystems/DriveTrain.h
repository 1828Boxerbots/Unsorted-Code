/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Spark.h>
#include "../include/RobotMap.h"
#include <frc/XboxController.h>
#include <frc/commands/Subsystem.h>

class DriveTrain : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;

  //objects
  frc::Spark m_motorL {PMW_MOTOR_LEFT};
  frc::Spark m_motorR {PMW_MOTOR_RIGHT};
  //functions
  void Move (frc::XboxController * PController);

};
