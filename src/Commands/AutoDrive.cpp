#include "AutoDrive.h"

AutoDrive::AutoDrive(double distance) : m_targetDistance(distance)
{
//  Constants in CAPITAL LETTERS below are #define-ed in ROBOTMAP.H
	timer = new frc::Timer;
	timer->Start();
	m_completed = false;
	m_targetDistance = distance * scaler;
	m_distance = 0.0;
	m_rampSpeed = 0.0;
	m_distanceRemaining = 0.0;
	count = 0;
	drivecounter = new frc::Timer;
	drivecounter->Start();
}

// Called just before this Command runs the first time
void AutoDrive::Initialize() {
	count=0;
}

// Called repeatedly when this Command is scheduled to run
void AutoDrive::Execute() {

	if (count == 0){
		drivecounter->Reset();
		drivecounter->Start();
	}
	frc::SmartDashboard::PutNumber("Target Distance:", m_targetDistance);
// 	frc::SmartDashboard::PutNumber("Time in", drivecounter->Get() );
	//count = drivecounter->Get();
	count++;
	if (drivecounter->Get() < m_targetDistance)
	{
		Robot::driving->Drive(-.3,0);
	}
	else
		{Robot::driving->Drive(0,0);
		count=-1;
		}
	// frc::SmartDashboard::PutNumber("Time out ", drivecounter->Get());
}

// Make this return true when this Command no longer needs to run execute()
bool AutoDrive::IsFinished() {
	if (count==-1){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoDrive::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoDrive::Interrupted() {

}
