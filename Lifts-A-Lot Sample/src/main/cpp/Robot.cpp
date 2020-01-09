/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <frc/Joystick.h>
#include <frc/Talon.h>
#include <frc/TimedRobot.h>
#include <frc/drive/DifferentialDrive.h>

using namespace frc;
/**
 * This is a demo program showing the use of the DifferentialDrive class.
 * Runs the motors with arcade steering.
 */
class Robot : public frc::TimedRobot 
{
  Talon m_leftMotor{1};
  Talon m_rightMotor{0};
  frc::DifferentialDrive m_robotDrive{m_leftMotor, m_rightMotor};
  frc::Joystick m_stick{0};

 public:
  void TeleopPeriodic() 
  {
    // Drive with arcade style
    m_robotDrive.ArcadeDrive(m_stick.GetY(), m_stick.GetX());
  }
};

#ifndef RUNNING_FRC_TESTS
int main() { return frc::StartRobot<Robot>(); }
#endif
