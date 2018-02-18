#include "ArmCommand.h"

ArmCommand::ArmCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void ArmCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void ArmCommand::Execute() {

	Robot::arm->MoveBody(Robot::oi->getJoystick2()->GetY());
	frc::SmartDashboard::PutNumber("Height",Robot::oi->getJoystick2()->GetY() );

}

// Make this return true when this Command no longer needs to run execute()
bool ArmCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void ArmCommand::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ArmCommand::Interrupted() {

}
