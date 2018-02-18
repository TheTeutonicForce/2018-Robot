#ifndef AutoGrip_H
#define AutoGrip_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoGrip : public Command {
public:
	AutoGrip();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float count;
};

#endif  // AutoGrip_H
