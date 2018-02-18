// RobotBuilder Version: 2.0
//
// This file was generated by RobotBuilder. It contains sections of
// code that are automatically generated and assigned by robotbuilder.
// These sections will be updated in the future when you export to
// C++ from RobotBuilder. Do not put any code or make any change in
// the blocks indicating autogenerated code or it will be lost on an
// update. Deleting the comments indicating the section will prevent
// it from being updated in the future.


#ifndef DRIVING_H
#define DRIVING_H
#include "Commands/Subsystem.h"
#include "WPILib.h"

/**
 *
 *
 * @author ExampleAuthor
 */
class Driving: public frc::Subsystem {
private:
	// It's desirable that everything possible is private except
	// for methods that implement subsystem capabilities
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
	std::shared_ptr<frc::SpeedController> rightFront;
	std::shared_ptr<frc::SpeedController> leftFront;
	std::shared_ptr<frc::SpeedController> leftBack;
	std::shared_ptr<frc::SpeedController> rightBack;
	std::shared_ptr<frc::RobotDrive> robotDrive41;
	std::shared_ptr<frc::ADXRS450_Gyro> gyro;
	std::shared_ptr<AnalogInput> rangeFinder;


    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=DECLARATIONS
public:
	Driving();
	void InitDefaultCommand() override;
	void Periodic() override;
	void Drive(double forward, double twist);
	double Gyro();
	double Range();
	void GyroReset();
	void MaintainHeading(double m_speed,double m_heading);
	double m_gyroAngle;
	double m_ultra;
	// double m_speed;
	// double m_heading;
	// BEGIN AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS

    // END AUTOGENERATED CODE, SOURCE=ROBOTBUILDER ID=CONSTANTS
};

#endif
