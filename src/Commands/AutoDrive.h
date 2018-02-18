#ifndef AutoDrive_H
#define AutoDrive_H

#include "Commands/Subsystem.h"
#include "../Robot.h"


class AutoDrive : public Command {
public:
	AutoDrive(double distance);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
private:
	float count;
	bool m_completed;
	double m_distance;
	double m_targetDistance;
	double m_rampSpeed;
	double m_distanceRemaining;
	frc::Timer* timer;
	frc::Timer * drivecounter;
	static constexpr double startspeed = 0.28;
	static constexpr double fullspeed = 0.45;
	static constexpr double scaler = 1.0;
	static constexpr double rampFactor = 0.4;
	static constexpr double fastStartRampFactor = 1.0;
	static constexpr double minSpeed = 0.1;

};

#endif  // AutoDrive_H
