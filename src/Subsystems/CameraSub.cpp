/*
 * CameraSub.cpp
 *
 *  Created on: Jan 18, 2018
 *      Author: frc5096
 */




#include "CameraSub.h"
#include "../Robot.h"

using namespace cs;


// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=INCLUDES

// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

CameraSub::CameraSub() : Subsystem("CameraSub") {

//	table->GetTable("")->PutString("CameraSelection", camera0.GetName());
//	std::thread visionThread(VisionThread);
//	visionThread.detach();
	// END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS

}

void CameraSub::InitDefaultCommand() {
    // Set the default command for a subsystem here.
    // SetDefaultCommand(new MySpecialCommand());
    // BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
//	 SmartDashboard::PutData("camera", new frc::CameraServer);
	// frc::SmartDashboard::PutData("Camera", cameraSubcameraServer());
    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DEFAULT_COMMAND
}

void CameraSub::VisionThread(){
//	cs::CvSink cvSink=Robot::cam0->GetVideo();
	cs::CvSink cvSink=frc::CameraServer::GetInstance()->GetVideo();
}


