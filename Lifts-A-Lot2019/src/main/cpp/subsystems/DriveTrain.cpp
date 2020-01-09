/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/DriveTrain.h"
#include <frc/XboxController.h>


DriveTrain::DriveTrain() : Subsystem("DriveTrain") {}
void DriveTrain::StopMotors()
{
  //Zeros motors
  m_lDriveMotor.Set(0.0);
  m_rDriveMotor.Set(0.0);
}
void DriveTrain::TeleopDrive(XboxController* controller)
{
  //Hooks up X to the controller X axis
double YLeft = controller->GetY(GenericHID::kLeftHand);
double XLeft = controller->GetX(GenericHID::kLeftHand);

mainDrive.ArcadeDrive(YLeft, XLeft);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
