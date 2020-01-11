/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "commands/Autonomous.h"

Autonomous::Autonomous() 
{
  // Use Requires() here to declare subsystem dependencies
  // eg. Requires(Robot::chassis.get());
}
// Called just before this Command runs the first time
void Autonomous::Initialize() 
{
//Read shuffle board
m_auto = false; //TBD
m_fieldPosition = 1; // TBD

}

// Called repeatedly when this Command is scheduled to run
void Autonomous::Execute()
 {
  Switch(m_fieldPosition)
  {
  case 1:
    AutoOne();
    break;
  case 2:
    AutoTwo();
    break;
  case 3:
    AutoThree();
    break;
  }
}
// Make this return true when this Command no longer needs to run execute()
bool Autonomous::IsFinished() { return false; }

// Called once after isFinished returns true
void Autonomous::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Autonomous::Interrupted() {}
