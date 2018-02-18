#include "Delay.h"

Delay::Delay(double time): m_time(time) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	timer = new frc::Timer;
	m_completed = false;
}

// Called just before this Command runs the first time
void Delay::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void Delay::Execute() {
	timer->Reset();
	timer->Start();
	while(timer->Get()<m_time){
// 		frc::SmartDashboard::PutNumber("Wait Time:",timer->Get());
	}
	m_completed = true;

}

// Make this return true when this Command no longer needs to run execute()
bool Delay::IsFinished() {
	return m_completed;
}

// Called once after isFinished returns true
void Delay::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void Delay::Interrupted() {

}
