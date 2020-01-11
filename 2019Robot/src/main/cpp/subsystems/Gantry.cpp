/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Gantry.h"
#include "Util.h"
#include <frc/SmartDashboard/SmartDashboard.h>

using namespace frc;
Gantry::Gantry() : Subsystem("Gantry") 
{
  
}
void Gantry::InvertMotors()
{
  m_gantryMotorLeft.SetInverted(true);
  m_gantryMotorRight.SetInverted(false);
}

void Gantry::TeleopGantry(XboxController* pController)
{
    //Hooks up the bumper variables to the actual bumpers on the controller
    bool rightBumper = pController->GetBumper(GenericHID::kRightHand);
    bool leftBumper = pController->GetBumper(GenericHID::kLeftHand);
    //m_pGantryEncoder->SetDistancePerPulse(1.0 / 360 * 2.0 * 3.1415 * 1.5);
    if(rightBumper == true && leftBumper == false)
    {
       MoveUp();
    }
    else
    {
        if(leftBumper == true && rightBumper == false)
        {
            MoveDown();
        }
        else
        {
            StopMotors();
        }
    }
}

void Gantry::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}

void Gantry::MoveUp()
{
    //When the right bumper is pressed, move gantry up
    if (m_topLimit.Get() == true)
    {
        return;
    }
    m_gantryMotorLeft.Set(0.5);
    m_gantryMotorRight.Set(0.5);
}
void Gantry::MoveDown()
{
    //When the left bumper is pressed, move gantry down
    if (m_bottomLimit.Get() == true)
    {
        return;
    }
    m_gantryMotorLeft.Set(-0.5);
    m_gantryMotorRight.Set(-0.5);
}
void Gantry::StopMotors()
{
    //stop both motors
    m_gantryMotorLeft.Set(0.0);
    m_gantryMotorRight.Set(0.0);
}