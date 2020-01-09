/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <frc/XboxController.h>
#include "RobotMap.h"

class OI {
 public:
  OI();
  frc::XboxController* getController(int num = 0)
  {
    return &m_controller1;
  }
  private:
  frc::XboxController m_controller1 {USB_CONTROLLLER_ONE};
};
