#ifndef AutoUnGrip_H
#define AutoUnGrip_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoUnGrip : public Command {
public:
	AutoUnGrip();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	float count;
};

#endif  // AutoUnGrip_H
