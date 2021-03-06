/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <frc/TimedRobot.h>
#include <frc/commands/Command.h>
#include <frc/smartdashboard/SendableChooser.h>

#include "OI.h"
#include "commands/DriveTrainCMD.h"
#include "commands/ShooterCMD.h"
#include "commands/ArmCMD.h"


#include "subsystems/DriveTrain.h"
#include "subsystems/Shooter.h"
#include "subsystems/Arm.h"

using namespace frc;

class Robot : public frc::TimedRobot 
{
 public:
  static OI m_oi;

  static std::shared_ptr <DriveTrain> m_driveTrain;
  static std::shared_ptr <Shooter> m_shooter;
  static std::shared_ptr <Arm> m_arm;

  void RobotInit() override;
  void RobotPeriodic() override;
  void DisabledInit() override;
  void DisabledPeriodic() override;
  void AutonomousInit() override;
  void AutonomousPeriodic() override;
  void TeleopInit() override;
  void TeleopPeriodic() override;
  void TestPeriodic() override;

 private:
  // Have it null by default so that if testing teleop it
  // doesn't have undefined behavior and potentially crash.

  DriveTrainCMD m_driveTrainCMD;
  ShooterCMD m_shooterCMD;
  ArmCMD m_armCMD;
};
