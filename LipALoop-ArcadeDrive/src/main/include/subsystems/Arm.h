/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/commands/Subsystem.h>
#include "../include/RobotMap.h"
#include <frc/Servo.h>

class Arm : public frc::Subsystem {
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  Arm();
  void InitDefaultCommand() override;

  //objects
  frc::Servo m_servoArm {PWM_SERVO_ARM};
  frc::Servo m_servoWrist {PWM_SERVO_WRIST};
  frc::Servo m_servoHand {PWM_SERVO_HAND};
  //functions 

};
