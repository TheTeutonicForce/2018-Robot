#ifndef Delay_H
#define Delay_H

#include "../Robot.h"

class Delay : public Command {
public:
	Delay(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	frc::Timer* timer;
	bool m_completed;
	double m_time;
};

#endif  // Delay_H
