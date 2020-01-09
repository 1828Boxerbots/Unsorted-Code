/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/XboxController.h>
#include <frc/Spark.h>
#include <frc/SampleRobot.h>
#include <frc/smartdashboard/SendableChooser.h>

/**
 * This is a demo program showing the use of the DifferentialDrive class. The
 * SampleRobot class is the base of a robot application that will automatically
 * call your Autonomous and OperatorControl methods at the right time as
 * controlled by the switches on the driver station or the field controls.
 *
 * WARNING: While it may look like a good choice to use for your code if you're
 * inexperienced, don't. Unless you know what you are doing, complex code will
 * be much more difficult under this system. Use TimedRobot or Command-Based
 * instead if you're new.
 */
class Robot : public frc::SampleRobot {
 public:
  Robot();

  void RobotInit() override;
  void Autonomous() override;
  void OperatorControl() override;
  void Test() override;

 private:
  // RobotMap
    const int PWM_LEFT_MOTOR = 2;
    const int PWM_RIGHT_MOTOR =3;
    const int PWM_TURRRENT_MOTOR = 4;
    const int PWM_SHOOT_MOTOR = 5;
    const int USB_XBOXCONTROLLER = 0;
  //Lift
    const int PWM_LIFT_MOTOR = 9;

  //Turrent Motor

  frc::Spark m_turrentMotor{PWM_TURRRENT_MOTOR};
  //Shoot Motor 
    frc::Spark m_shootMotor{PWM_SHOOT_MOTOR};

  //Controller 
    frc::XboxController m_controller{USB_XBOXCONTROLLER};
  
  //Lift Motor
    frc::Spark m_liftMotor{PWM_LIFT_MOTOR};

  //Drive Motor
    frc::Spark m_leftMotor{PWM_LEFT_MOTOR};
    frc::Spark m_rightMotor{PWM_RIGHT_MOTOR};
};
