#include "JogForward.h"

JogForward::JogForward() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_completed = false;
	m_targetDistance = 0.06;
	m_distance = 0.0;
	Robot::accel->ResetAccel();
	timer = new frc::Timer;

}

// Called just before this Command runs the first time
void JogForward::Initialize() {
	Robot::accel->ResetAccel();
	timer->Reset();
}

// Called repeatedly when this Command is scheduled to run
void JogForward::Execute() {
	m_distance = Robot::accel->GetDistanceY();
	if (m_distance < m_targetDistance)    // we are assuming we are moving forward here
	{
		Robot::driving->Drive(-0.2,0);  // move forward
	}
	else
	{
		timer->Start();
		while (timer->Get()<0.5) Robot::driving->Drive(0.1,0);  //apply the breaks
		Robot::driving->Drive(0,0);  // and turn off motors
		m_completed = true;		//and terminate the command
	}
}

// Make this return true when this Command no longer needs to run execute()
bool JogForward::IsFinished() {
	return m_completed;
}

// Called once after isFinished returns true
void JogForward::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void JogForward::Interrupted() {

}
