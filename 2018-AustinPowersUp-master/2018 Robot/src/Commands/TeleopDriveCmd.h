#ifndef TeleopDriveCmd_H
#define TeleopDriveCmd_H

// #include <WPILib.h>
#include <Subsystems/DriveTrain.h>

//#include "Robot.h"
//#include "OI.h"

#include <Commands/Command.h>

class TeleopDriveCmd : public Command
{
public:
	explicit TeleopDriveCmd();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleopDriveCmd_H
