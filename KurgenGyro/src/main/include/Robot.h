/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <string>


#include <frc/ADXRS450_Gyro.h>
#include <frc/XboxController.h>
#include <frc/Victor.h>
#include <frc/SampleRobot.h>
#include <frc/drive/DifferentialDrive.h>
#include <frc/smartdashboard/SendableChooser.h>
#include <frc/IterativeRobot.h>

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
    const int PWM_DRIVE_ONE = 1;
    const int PWM_DRIVE_TWO = 2;
    const int PWM_DRIVE_THREE = 3;
    const int PWM_DRIVE_FOUR = 4;

    const int USB_XBOXCONTROLLER = 0;

    //Left side
    frc::Victor m_driveOne{PWM_DRIVE_ONE};
    frc::Victor m_driveTwo{PWM_DRIVE_TWO};
    //Right side
    frc::Victor m_driveThree{PWM_DRIVE_THREE};
    frc::Victor m_driveFour{PWM_DRIVE_FOUR};
    //Joystick
    frc::XboxController controller{USB_XBOXCONTROLLER};

    //Gyro
    frc::ADXRS450_Gyro m_gyro{frc::SPI::Port::kOnboardCS0};

};
