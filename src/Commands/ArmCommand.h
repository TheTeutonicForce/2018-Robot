#ifndef ArmCommand_H
#define ArmCommand_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Robotmap.h"

class ArmCommand : public Command {
public:
	ArmCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ArmCommand_H
