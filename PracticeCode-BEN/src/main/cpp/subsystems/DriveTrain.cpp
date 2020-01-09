/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "../include/subsystems/DriveTrain.h"
#include <frc/smartdashboard/smartdashboard.h>

DriveTrain::DriveTrain() : Subsystem("ExampleSubsystem") {}

void DriveTrain::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());

}

  double Power = 1.0/2;
  double noPower = 0.0;

  void DriveTrain :: IntHardware()
  {
    m_gyro.Calibrate();
  }

  void DriveTrain :: ForwardMax() 
  {
    //Moves motors forward at max speed
    m_motorL.Set(-Power);
    m_motorR.Set(Power);
  }

  void DriveTrain :: BackwardsMax() 
  {
    //Moves motors forward at max speed
    m_motorL.Set(Power);
    m_motorR.Set(-Power);
  }

  void DriveTrain :: Stop()
  {
    //Stops all motors
    m_motorL.Set(noPower);
    m_motorR.Set(noPower);
  }

  double DriveTrain :: GetAngle() 
  {
    //Gets the angle from the Gyro
    double currentAngle = m_gyro.GetAngle();
    SmartDashboard::PutNumber("GyroAngle", currentAngle);
    return currentAngle;
  }

  void DriveTrain :: MotorTurnRight()
  {
    //Left motor goes forward and right motor goes backwards
    m_motorL.Set(-Power);
    m_motorR.Set(-Power);
  }

  void DriveTrain :: MotorTurnLeft()
  {
    //Left motor goes backwards and right motor goes forwards
    m_motorL.Set(Power);
    m_motorR.Set(Power);
  }


  void DriveTrain :: ForwardInSeconds(double timeInSeconds)
  {
   frc::Timer clock;
   double startTime = clock.Get(); 
   ForwardMax();
   while (clock.Get() - startTime < timeInSeconds)
   {
   }
   Stop();
  }

  void DriveTrain :: BackwardInSeconds(double timeInSeconds)
  {
   frc::Timer clock;
   double startTime = clock.Get(); 
   BackwardsMax();
   while (clock.Get() - startTime < timeInSeconds)
   {
   }
   Stop();
  }

  void DriveTrain :: Turn(double angle)
  {
    double startingAngle = GetAngle();
    if (angle < 0) 
    {
      MotorTurnLeft();
      double wantedAngle = startingAngle + angle;
      double currentAngle = GetAngle();
      while(currentAngle > wantedAngle)
      {
        currentAngle = GetAngle();
      }
    } else
    {
      MotorTurnRight();
      double wantedAngle = startingAngle + angle;
      double currentAngle = GetAngle();
      while(currentAngle < wantedAngle)
      {
        currentAngle = GetAngle();
      }
    }
    Stop();
  }

// Put methods for controlling this subsystem
// here. Call these from Commands.
