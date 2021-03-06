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
  m_gantryMotor.SetInverted(true);
}

void Gantry::TeleopGantry(XboxController* controller, XboxController* controller2)
{   
    //m_gantryMotor.Set(controller->GetY(GenericHID::kRightHand));

    bool topLimit = m_topLimit.Get();
    SmartDashboard::PutBoolean("Top Limit", topLimit);

    bool bottomLimit = m_bottomLimit.Get();
    SmartDashboard::PutBoolean("Bottom Limit", bottomLimit);

    double winchRadius = 1;
    m_pGantryEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * winchRadius);
    if (bottomLimit == true)
    {
        m_pGantryEncoder.Reset();
    }
    double encoderDistance = m_pGantryEncoder.GetDistance();
    SmartDashboard::PutNumber("Gantry Encoder", encoderDistance);

    bool abutton = controller2->GetAButton();
    bool bButton = controller2->GetBButton();
    bool xButton = controller2->GetXButton();
/*
    if ((abutton == true)  && (encoderDistance < 37))
    {
        MoveUp();
    }
    if ((abutton == true) && (encoderDistance > 37))
    {
        MoveDown();
    }
    if (bButton == true)
    {
        if (encoderDistance < 132)
        {
            MoveUp();
        }
        if (encoderDistance > 132)
        {
            MoveDown();
        }
    }
    if (xButton == true)
    {
        if (encoderDistance < 214)
        {
            MoveUp();
        }
        if (encoderDistance > 214)
        {
            MoveDown();
        }
    }*/
    //Hooks up the bumper variables to the actual bumpers on the controller
    bool rightBumper = controller->GetBumper(GenericHID::kRightHand);
    bool leftBumper = controller->GetBumper(GenericHID::kLeftHand);
    bool abutton2 = controller->GetAButton();
    //Makes a failsafe if both or neither of the bumpers are pressed
     if (((rightBumper == true) && (leftBumper == true)) || ((rightBumper == false) && (leftBumper == false)))
    {
        if (abutton == true)
        {
            if (encoderDistance > 38)
            {
                MoveDown();
            }
            else
            {
                MoveUp();
            }
        }
        else
        {
            if (bButton == true)
            {
                if (encoderDistance > 140)
                {
                    MoveDown();
                }
                else
                {
                    MoveUp();
                }
            }
            else
            {
                if (xButton == true)
                {
                    if (encoderDistance > 223)
                    {
                        MoveDown();
                    }
                    else
                    {
                        MoveUp();
                    }
                }
                else
                {
                    if (abutton2 == true)
                    {
                        if (encoderDistance > 25)
                        {
                            MoveDown();
                        }
                        else
                        {
                            MoveUp();
                        }
                    }
                    else
                    {
                        StopMotors();
                    }
                }
            }
        }
    }
    else
    {
        if(rightBumper == true)
        {
            MoveUp();
        }
        if(leftBumper == true)
        { 
            if (bottomLimit == true)
            {
                StopMotors();
            }
            else
            {
                MoveDown();
            }
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
    /*
    if (m_topLimit.Get() == true)
    {
        return;
    }*/
    m_gantryMotor.Set(-1);
}
void Gantry::MoveDown()
{
    //When the left bumper is pressed, move gantry down
    /*
    if (m_bottomLimit.Get() == true)
    {
        return;
    }*/
    m_gantryMotor.Set(0.8);
}
void Gantry::StopMotors()
{
    //stop both motors
    m_gantryMotor.Set(0.0);
}
void Gantry::MoveUntilPosition(double targetposition)
{
    double winchRadius = 1;
    m_pGantryEncoder.SetDistancePerPulse(1.0 / 360.0 * 2.0 * 3.1415 * winchRadius);
   
}