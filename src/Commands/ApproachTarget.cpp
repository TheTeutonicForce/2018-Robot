#include "ApproachTarget.h"

ApproachTarget::ApproachTarget(double distance) : m_distance(distance) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_distance = distance;
	m_complete = false;
}

// Called just before this Command runs the first time
void ApproachTarget::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ApproachTarget::Execute() {
	while ((9*Robot::driving->Range())>m_distance) {
		frc::SmartDashboard::PutNumber("Approaching Target Distance:",(9*Robot::driving->Range()));
		Robot::driving->Drive(-0.25,0.018);  //need this much twist to go straight
		m_complete = false;
	}
	Robot::driving->Drive(0,0);
	m_complete = true;
}

// Make this return true when this Command no longer needs to run execute()
bool ApproachTarget::IsFinished() {
	return m_complete;
}

// Called once after isFinished returns true
void ApproachTarget::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ApproachTarget::Interrupted() {

}
