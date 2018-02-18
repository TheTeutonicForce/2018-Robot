#ifndef AutoArm_H
#define AutoArm_H

#include "Commands/Subsystem.h"
#include "../Robot.h"

class AutoArm : public Command {
public:
	AutoArm(double height);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();

private:
	float count;
	bool m_completed;
	double m_targetDistance;
	double m_distanceRemaining;
	frc::Timer* timer;
	frc::Timer * armcounter;
	double goalTime;
};

#endif  // AutoArm_H
