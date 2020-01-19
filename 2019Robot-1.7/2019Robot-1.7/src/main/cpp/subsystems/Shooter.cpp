/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "subsystems/Shooter.h"
#include <frc/SmartDashboard/SmartDashboard.h>


using namespace frc;
Shooter::Shooter() : Subsystem("Shooter") {}

void Shooter::InitDefaultCommand() 
{
  // Set the default command for a subsystem here.
  // SetDefaultCommand(new MySpecialCommand());
}
void Shooter::Intialize()
{
	m_shooterEncoder.SetLimitsVoltage(3.2, 3.4);
	m_counter = new Counter(m_shooterEncoder);
	m_speedPrevious = 0;
	m_Position = 0;
}

double Shooter::CheckDirectionChange()
{
  SmartDashboard::PutNumber("New Speed", m_newSpeed);
  bool triggerState = m_shooterEncoder.GetTriggerState();
  SmartDashboard::PutBoolean("Trigger State", triggerState);
	// update position accumulator if changing direction
	// encoder doesn't know the direction so we have to remember the direction for it
	if ((m_speedPrevious <= 0 && m_newSpeed >= 0) || (m_speedPrevious >= 0 && m_newSpeed < 0))
	{
		m_Position = GetPosition(); // changing directions so save what we have
		m_counter->Reset(); // and start counting in the new direction
		m_speedPrevious = m_newSpeed; // return input speed for ease of use (may include it in the Set() argument => Set(CheckDirectionChange(speed)))
	}
  else
  {
		return m_newSpeed;
  }
}

int Shooter::GetPosition()
{
  SmartDashboard::PutNumber("Position", m_Position);
	// position from previous direction change plus what's been accumulated so far in this direction
	if (m_speedPrevious >= 0)
  {
	  return m_Position + m_counter->Get(); // been going forward so add counter
  }
  else
  {
	  return m_Position - m_counter->Get(); // been going backward so subtract counter
  }
  //SmartDashboard::PutNumber("Counter", m_counter);
}

void Shooter::SetAngle(XboxController* controller)
{

  //"shooterTick" get the current tick number of the encoder
  /*double shooterTick = m_pShooterEncoder->GetRaw();

  //get button state (true or false)
  bool xButton = controller->GetXButton();
  bool aButton = controller->GetAButton();

  // this is setting angle to tick numbers
  const double ANGLE_45 = 21.0;
  const double ANGLE_90 = 43.0;

  // set the target tick number to the angle we want
  double position = m_util.ToggleSwitch(xButton, aButton, ANGLE_45, ANGLE_90, true, &m_joystickpress);

  //if the current tick read is less than target then set motor either foward or backwards 
  if (shooterTick < position)
  {
    m_shooterAim.Set(0.75);
  }
  else
  {
    m_shooterAim.Set(-0.75);
  }
  // stop the motor if it is in the range
  if ((shooterTick < position-1.0) || (shooterTick > position+1.0))
  {
    m_shooterAim.Set(0);
  }
  */

}
void Shooter::TeleopPickUp(XboxController* controller)
{
  /*
  m_shooterEncoder.SetLimitsVoltage(3.2, 3.4);
  m_counter = new Counter(m_shooterEncoder);
  double speedPrevious = 0;
  double position = 0;

  while (true)
  {
  //SmartDashboard::PutNumber("Seat Motor", encoder);
  }
  */
  m_shooterAim.Set(controller->GetY(GenericHID::kRightHand));

  //Get the trigger as double 1 and double 0
  double GetRightTrigger = controller->GetTriggerAxis(GenericHID::kRightHand);
  double GetLeftTrigger = controller->GetTriggerAxis(GenericHID::kLeftHand);

  double MotorSpeedPickup = 0.75;
  //check right trigger, right override left if both are press
  if (GetRightTrigger > 0.1)
  {
    m_shooterPickupTop.Set(MotorSpeedPickup);
    m_shooterPickupBottom.Set(MotorSpeedPickup);
  }
  else
  {
    // run only after reading right trigger as false 
    if (GetLeftTrigger > 0.1)
    {
      m_shooterPickupTop.Set(MotorSpeedPickup);
      m_shooterPickupBottom.Set(MotorSpeedPickup);
    }
    else 
    {
      //if both trigger are false the it stop the motors 
      m_shooterPickupTop.Set(0);
      m_shooterPickupBottom.Set(0);
    }
  }

}
void Shooter::InvertMotorsPickUp()
{
  m_shooterPickupBottom.SetInverted(true);
  m_shooterPickupTop.SetInverted(false);
  m_shooterAim.SetInverted(false);
}
void Shooter::StopMotors()
{
  m_shooterPickupBottom.Set(0);
  m_shooterPickupTop.Set(0);
  m_shooterAim.Set(0);
}
// Put methods for controlling this subsystem
// here. Call these from Commands.
