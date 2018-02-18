#ifndef ApproachTarget_H
#define ApproachTarget_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Robotmap.h"

class ApproachTarget : public Command {
public:
	ApproachTarget(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	double m_distance;
	bool m_complete;
};

#endif  // ApproachTarget_H
