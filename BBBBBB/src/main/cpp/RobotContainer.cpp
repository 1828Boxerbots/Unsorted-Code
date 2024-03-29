// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "RobotContainer.h" 

void RobotContainer::INIT(){
m_pDriveTrain = new DriveTrain;
m_pSensor = new Sensors;
m_pStuffAndPuffCommand = new HouseCommand(m_pDriveTrain,m_pSensor);
}
RobotContainer::RobotContainer(){};

void RobotContainer::ConfigureButtonBindings() {
  // Configure your button bindings here
}

frc2::Command* RobotContainer::GetAutonomousCommand() {
  // An example command will be run in autonomous
  return m_pStuffAndPuffCommand;
}