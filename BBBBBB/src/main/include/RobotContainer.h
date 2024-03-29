// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#pragma once
#include "subsystems/DriveTrain.hpp"
#include "subsystems/Sensors.h"
#include "commands/HouseCommand.h"
#include <frc2/command/Command.h>

/**
 * This class is where the bulk of the robot should be declared.  Since
 * Command-based is a "declarative" paradigm, very little robot logic should
 * actually be handled in the {@link Robot} periodic methods (other than the
 * scheduler calls).  Instead, the structure of the robot (including subsystems,
 * commands, and button mappings) should be declared here.
 */
class RobotContainer {
 public:
  RobotContainer();
  frc2::Command* GetAutonomousCommand();
 void INIT();
HouseCommand *m_pStuffAndPuffCommand;
 private:
  // The robot's subsystems and commands are defined here...
Sensors *m_pSensor;/* = new Sensors;*/
DriveTrain *m_pDriveTrain;/* = new DriveTrain;*/
  void ConfigureButtonBindings();
};
