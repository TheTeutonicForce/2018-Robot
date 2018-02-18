#include "AutoAccel.h"

AutoAccel::AutoAccel(double distance, double speed, double scaler, double heading) : m_targetDistance(distance), m_speedValue(speed), m_scaledValue(scaler), m_heading(heading)
{
//  Constants in CAPITAL LETTERS below are #define-ed in ROBOTMAP.H
	m_completed = false;
	m_distance = 0.0;
	m_rampSpeed = 0.0;
	m_distanceRemaining = 0.0;
	Robot::accel->ResetAccel();

}

// Called just before this Command runs the first time
void AutoAccel::Initialize() {
	Robot::accel->ResetAccel();
}

// Called repeatedly when this Command is scheduled to run
void AutoAccel::Execute() {
	Robot::accel->ResetAccel();

	frc::SmartDashboard::PutNumber("Target Distance:", m_targetDistance);
// problem
	if (m_targetDistance > 0) {  //In this part of the IF statement we are moving forward
		while (Robot::accel->GetDistanceY() < m_targetDistance*m_scaledValue)    // we are assuming we are moving forward here
			{
				Robot::driving->MaintainHeading(-m_speedValue,m_heading);
			}

			Robot::driving->MaintainHeading(0,m_heading);  //stop the thing
			m_completed = true;		//and terminate the command

	}
	else {		//In this part of the IF statement we are moving backward
			while (Robot::accel->GetDistanceY() > m_targetDistance*m_scaledValue)    // we are assuming we are moving backward here
			{
				Robot::driving->MaintainHeading(m_speedValue,m_heading);
			}

			Robot::driving->MaintainHeading(0,m_heading);  //stop the thing
			m_completed = true;		//and terminate the command

	}
}

// Make this return true when this Command no longer needs to run execute()
bool AutoAccel::IsFinished() {
		return m_completed;
}

// Called once after isFinished returns true
void AutoAccel::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoAccel::Interrupted() {

}
