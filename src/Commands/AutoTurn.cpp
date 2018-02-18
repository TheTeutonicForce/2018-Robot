#include "AutoTurn.h"

AutoTurn::AutoTurn(double distance, double speed, double scaler) : m_targetDistance(distance), turnSpeed(speed), m_scaler(scaler)
{
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	m_finished=false;
}

// Called just before this Command runs the first time
void AutoTurn::Initialize() {
	Robot::driving->GyroReset();
}

// Called repeatedly when this Command is scheduled to run
void AutoTurn::Execute() {
	frc::SmartDashboard::PutNumber("Target Distance:", m_targetDistance);

	if (m_targetDistance*m_scaler>0){
		while(Robot::driving->Gyro()< m_targetDistance*m_scaler){
			Robot::driving->Drive(0,turnSpeed);
		}
	}
	else if(m_targetDistance*m_scaler<0){
		while(Robot::driving->Gyro()> m_targetDistance*m_scaler){
			Robot::driving->Drive(0,-turnSpeed);
		}
	}
	m_finished=true;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoTurn::IsFinished() {
	return m_finished;
}

// Called once after isFinished returns true
void AutoTurn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoTurn::Interrupted() {

}
