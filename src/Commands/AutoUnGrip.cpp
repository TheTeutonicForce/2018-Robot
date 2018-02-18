#include "AutoUnGrip.h"

AutoUnGrip::AutoUnGrip() {

	count = 0;
}

// Called just before this Command runs the first time
void AutoUnGrip::Initialize() {
	count = 0;
}

// Called repeatedly when this Command is scheduled to run
void AutoUnGrip::Execute() {;
	Robot::arm->OpenGripper();
	count = -1;

}

// Make this return true when this Command no longer needs to run execute()
bool AutoUnGrip::IsFinished() {
	if (count==-1){
			return true;
		}
		return false;
}

// Called once after isFinished returns true
void AutoUnGrip::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoUnGrip::Interrupted() {

}
