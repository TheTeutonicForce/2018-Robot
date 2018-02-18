#ifndef JogForward_H
#define JogForward_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Robotmap.h"

class JogForward : public Command {
private:
	frc::Timer * timer;

public:
	JogForward();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
	bool m_completed;
	double m_distance;
	double m_targetDistance;

};

#endif  // JogForward_H
