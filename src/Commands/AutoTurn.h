#ifndef AutoTurn_H
#define AutoTurn_H

#include "../Robot.h"
#include "Commands/Subsystem.h"

class AutoTurn : public Command {
public:
	AutoTurn(double distance, double speed, double scaler);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	double m_targetDistance;
	double turnSpeed;
	double m_scaler;
	bool m_finished;

};

#endif  // AutoTurn_H
