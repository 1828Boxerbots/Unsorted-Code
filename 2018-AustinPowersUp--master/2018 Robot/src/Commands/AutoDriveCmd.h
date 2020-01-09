//#ifndef AutoDriveCmd_H
//#define AutoDriveCmd_H

#pragma once

//#include <WPILib.h>

#include "Subsystems/DriveTrain.h"

//#include <Commands/Command.h>

//#include "Robot.h"
//#include "OI.h"

class AutoDriveCmd : public Command
{
public:
	explicit AutoDriveCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

//#endif  // AutoDriveCmd_H
