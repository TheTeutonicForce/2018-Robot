#include "AutoGrip.h"

AutoGrip::AutoGrip() {

	count = 0;
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void AutoGrip::Initialize() {
	count = 0;
}

// Called repeatedly when this Command is scheduled to run
void AutoGrip::Execute() {
	Robot::arm->CloseGripper();
	count=-1;
}

// Make this return true when this Command no longer needs to run execute()
bool AutoGrip::IsFinished() {
	if (count==-1){
		return true;
	}
	return false;
}

// Called once after isFinished returns true
void AutoGrip::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void AutoGrip::Interrupted() {

}
