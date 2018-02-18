#ifndef AutoAccel_H
#define AutoAccel_H

#include "Commands/Subsystem.h"
#include "../Robot.h"
#include "../Robotmap.h"


class AutoAccel : public Command {
public:
	AutoAccel(double distance, double speed, double scaler, double heading);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	bool m_completed;
	double m_distance;
	double m_targetDistance;
	double m_rampSpeed;
	double m_distanceRemaining;
	double m_scaledValue;
	double m_speedValue;
	double m_heading;

	static constexpr double startspeed = 0.28;
	static constexpr double fullspeed = 0.45;
	static constexpr double rampFactor = 0.4;
	static constexpr double fastStartRampFactor = 1.0;
	static constexpr double minSpeed = 0.1;

};

#endif  // AutoAccel_H
