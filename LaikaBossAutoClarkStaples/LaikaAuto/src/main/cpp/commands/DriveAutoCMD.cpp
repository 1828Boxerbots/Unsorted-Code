/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/DriveAutoCMD.h"
#include "Robot.h"
#include "frc/SmartDashboard/SmartDashboard.h"

DriveAutoCMD::DriveAutoCMD() {
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
  Requires(Robot::m_pDriveTrain.get());
}

// Called just before this Command runs the first time
void DriveAutoCMD::Initialize() {
  Robot::m_pDriveTrain->Init();
  m_state = 0;
}

// Called repeatedly when this Command is scheduled to run
void DriveAutoCMD::Execute() {
  SmartDashboard::PutNumber("Auto State", m_state);
  switch (m_state)
  {
    case 0:
      Move(0.5, 0.5);
      break;
    case 1:
      TurnRelitive(45);
      break;
    case 2:
      Move(0.5,1);
      break;
    case 3:
      TurnRelitive(-90);
      break;
    case 4:
      Move(0.5,2);
      break;
   
  }
  
}

void DriveAutoCMD::Move(double speed, double time)
{
  Robot::m_pDriveTrain->Move(speed, time);
  m_state++;
}
void DriveAutoCMD::Turn(double angle)
{
  Robot::m_pDriveTrain->Turn(angle);
  m_state++;
}
void DriveAutoCMD::TurnRelitive(double angle)
{
  Robot::m_pDriveTrain->TurnRelitive(angle);
  m_state++;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveAutoCMD::IsFinished() { return false; }

// Called once after isFinished returns true
void DriveAutoCMD::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveAutoCMD::Interrupted() {}
