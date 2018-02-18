#include "AutoArm.h"

AutoArm::AutoArm(double height) {
	timer = new frc::Timer;
	timer->Start();
	goalTime =0;
	m_completed = false;
	count = 0;
	m_targetDistance = height;
	m_distanceRemaining =0.0;
	armcounter = new frc::Timer;
	armcounter->Start();
}

// Called just before this Command runs the first time
void AutoArm::Initialize() {
	count = 0;
}

// Called repeatedly when this Command is scheduled to run
void AutoArm::Execute() {
	if (count == 0){
			armcounter->Reset();
			armcounter->Start();
		}
	frc::SmartDashboard::PutNumber("Target Distance:", m_targetDistance);
		frc::SmartDashboard::PutNumber("Time in", armcounter->Get() );
	count++;
	if(armcounter->Get() < m_targetDistance){
		Robot::arm->MoveBody(.3);
	}
	else{
		Robot::arm->MoveBody(0);
		count=-1;
	}
	frc::SmartDashboard::PutNumber("Time out ", armcounter->Get());
}

// Make this return true when this Command no longer needs to run execute()
bool AutoArm::IsFinished() {
	if (count==-1){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoArm::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoArm::Interrupted() {

}
