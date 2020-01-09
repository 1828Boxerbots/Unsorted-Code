/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/Spark.h>
#include <frc/ADXRS450_Gyro.h>
#include <frc/commands/Subsystem.h>
#include "../include/RobotMap.h"

using namespace frc;

class DriveTrain : public frc::Subsystem
{
 private:
  // It's desirable that everything possible under private except
  // for methods that implement subsystem capabilities

 public:
  DriveTrain();
  void InitDefaultCommand() override;

    //objects
    frc::Spark m_motorL {PMW_MOTOR_LEFT};
    frc::Spark m_motorR {PMW_MOTOR_RIGHT};
    frc::ADXRS450_Gyro m_gyro {SPI::Port::kOnboardCS0};
    //functions
    void IntHardware();
    void ForwardInSeconds(double timeInSeconds);
    void BackwardInSeconds(double timeInSeconds);
    void Turn(double angle);
    void ForwardMax();
    void BackwardsMax();
    void Stop();
    void MotorTurnRight();
    void MotorTurnLeft();
    double GetAngle();

};
