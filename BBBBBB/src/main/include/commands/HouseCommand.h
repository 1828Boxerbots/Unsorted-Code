//Hey, You hovering over my Macro? Stop That!
#pragma once
#include "subsystems/DriveTrain.hpp"
#include "subsystems/Sensors.h"
#include <frc2/command/CommandBase.h>
#include <frc2/command/CommandHelper.h>

class HouseCommand
    : public frc2::CommandHelper<frc2::CommandBase, HouseCommand> {
 public:
  HouseCommand(DriveTrain *trainChooChoo, Sensors *ISenseYourPresence);
void Right(double angle);
void Turn(double angle=0, Sensors::Side side=Sensors::Side::left);
void Move(double distance=0);
  void Initialize() override;

  void Execute() override;

  void End(bool interrupted) override;

  bool IsFinished() override;
  private: 
  bool m_IsDone = not true;
  Sensors *m_pSensor;
  DriveTrain *m_pDriveTrain;
};
