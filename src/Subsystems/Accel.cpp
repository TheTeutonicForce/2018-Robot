#include "Accel.h"
#include "../RobotMap.h"
// added a zeroing feature to SmoothY  2/24/17
//
//
//

Accel::Accel() : Subsystem("Accel") {
    	accelTimer = new frc::Timer();  // we will need timing information to calculate distance moved
    	accelTimer->Start();
    	for (int i=0; i<samples ; i++) accelVectorX[i]=0.0;
    	m_DistanceX = 0.0;
    	m_velocityX = 0.0;
    	m_subtractGravityX = 0.0; //Change this as necessary if the RoboRIO is not mounted level on the robot
    	for (int i=0; i<samples ; i++) accelVectorY[i]=0.0;
    	m_DistanceY = 0.0;
    	m_velocityY = 0.0;
    	m_subtractGravityY = 0.00; //Change this as necessary if the RoboRIO is not mounted level on the robot
    }

    void Accel::InitDefaultCommand()
    {
    	// Set the default command for a subsystem here.
    	//SetDefaultCommand(new MySpecialCommand());
    }

    // Put methods for controlling this subsystem
    // here. Call these from Commands.

    void Accel::ResetDistance()
    {
    	InitializeForGravity();  // commented out 2/20 - tests showed poor gravity correction - added back 4/21 do better job of measurement
    	m_DistanceX = 0.0;
    	m_velocityX = 0.0;
    	m_AverageSmoothX = 0.0;
    	m_TotalSmoothX = 0.0;
    	m_elapsedTimeX = 0.0;
    	// and Y
    	m_DistanceY = 0.0;
    	m_velocityY = 0.0;
    	m_AverageSmoothY = 0.0;
    	m_TotalSmoothY = 0.0;
    	m_elapsedTimeY = 0.0;

    	m_Smooth_Reading_Count = 0;
    	accelTimer->Reset();
    }

    void Accel::ResetVelocity()
    {
    	m_velocityX = 0.0;
    	m_elapsedTimeX = 0.0;
    	m_velocityY = 0.0;
    	m_elapsedTimeY = 0.0;
    	accelTimer->Reset();
    }

    void Accel::ResetAccel()
    {
    	for (int i=0; i<samples ; i++) accelVectorX[i]=0.0;
    	for (int i=0; i<samples ; i++) accelVectorY[i]=0.0;
    	ResetVelocity();
    	ResetDistance();
    }
    void Accel::InitializeForGravity()
    {
/*
 * This method disabled 2/24/17 on the belief that it was better replaced by a constant.
 * Remove the comment lines from line 28 and delete lines 14 and 78 if you want it back in...
*/

		 // Let's measure gravity's X and Y components in case the RoboRio is not mounted level
    	m_subtractGravityX = 0.0;
    	m_subtractGravityY = 0.0;
    //
     		int b=0;
    		while (b<samples) {
    			ReadAccelerometerX();
    			ReadAccelerometerY();
 //   			frc::SmartDashboard::PutNumber("Read Accelerometer:",b);
    			b++;
    		}
    		m_subtractGravityX = SmoothAccelX();
    		m_subtractGravityY = SmoothAccelY();
        	frc::SmartDashboard::PutNumber("Y Gravity Subtract: ",m_subtractGravityY);

    		// Now fill the X and Y arrays with gravity-adjusted readings;
    		for (int i=0; i<samples ; i++) {
    			accelVectorX[i] = -RobotMap::accelCop1->GetY() - m_subtractGravityX;
    		}

    		for (int i=0; i<samples ; i++) {
    			accelVectorY[i] = -RobotMap::accelCop1->GetY() - m_subtractGravityY;
    		}
 //   		frc::SmartDashboard::PutNumber("Gravity SubtractY:",m_subtractGravityY);
    } //end of the initialization function

    void Accel::ReadAccelerometerX()
    {
       	if (index_X == samples) index_X=0;   //index will be used to populate the five vector locations with latest readings
    	// velocity is delta acceleration per delta time
    	accelVectorX[index_X] = -RobotMap::accelCop1->GetX() - m_subtractGravityX;
    	frc::SmartDashboard::PutNumber("Raw Accelerometer X",accelVectorX[index_X]);
    	m_TempAccel = SmoothAccelX();
    	CalcVelocityX();
    	CalcDistanceX();
    	++index_X;
    }

    void Accel::ReadAccelerometerY()
    {
       	if (index_Y == samples) index_Y=0;   //index will be used to populate the five vector locations with latest readings
    	// velocity is delta acceleration per delta time
    	accelVectorY[index_Y] = -RobotMap::accelCop1->GetY() - m_subtractGravityY;
    	frc::SmartDashboard::PutNumber("Raw Accelerometer Y",accelVectorY[index_Y]);
    	frc::SmartDashboard::PutNumber("Y Gravity Subtract: ",m_subtractGravityY);
    	m_TempAccel = SmoothAccelY();
    	CalcVelocityY();
    	CalcDistanceY();
    	++index_Y;
    }


    double Accel::SmoothAccelX()
    {
    	/* What I want to do here is to calculate the average acceleration of all of the samples and assign that value to
    	 * the middle sample.  I want to use the mid-point time delta to calculate the change in velocity and distance.
    	 */
    	m_averageAccelX = 0.0;
    	for (int i=0; i<samples; ++i) m_averageAccelX += accelVectorX[i];
    	m_averageAccelX /= samples;
/*
 *
 * This version takes a shot at cutting out the noise when the robot is standing still
 *
 */

    	if (m_averageAccelX<0.01 && m_averageAccelX>-0.01) m_averageAccelX=0.0;
 /*
  *
  */

    	return m_averageAccelX;
    }

    double Accel::SmoothAccelY()
    {
    	/* What I want to do here is to calculate the average acceleration of all of the samples and assign that value to
    	 * the middle sample.  I want to use the mid-point time delta to calculate the change in velocity and distance.
    	 */
    	m_averageAccelY = 0.0;
    	for (int i=0; i<samples; ++i) m_averageAccelY += accelVectorY[i];
    	m_averageAccelY /= samples;
/*
 *
 * This version takes a shot at cutting out the noise when the robot is standing still
 *
 */

    	if (m_averageAccelY<0.01 && m_averageAccelY>-0.01) m_averageAccelY=0.0;
 /*
  *
  */
    	m_TotalSmoothY += m_averageAccelY;
    	m_Smooth_Reading_Count++;
    	m_AverageSmoothY = m_TotalSmoothY/m_Smooth_Reading_Count;
    // 	frc::SmartDashboard::PutNumber("Average Overall Acceleration:",m_AverageSmoothY);

    	return m_averageAccelY;
    }

    void Accel::CalcDistanceX()
    {
    	/* What I want to do here is to calculate the average acceleration of all of the samples and assign that value to
    	 * the middle sample.  I want to use the mid-point time delta to calculate the change in velocity and distance.
    	 */
    	m_DistanceX += m_velocityX * m_CentralDeltaTimeX;  //distance = velocity times delta time

    	frc::SmartDashboard::PutNumber("Accelerometer X",m_TempAccel);
    	frc::SmartDashboard::PutNumber("Distance X",m_DistanceX);
    	frc::SmartDashboard::PutNumber("Velocity X",m_velocityX);
    }

    void Accel::CalcDistanceY()
    {
    	/* What I want to do here is to calculate the average acceleration of all of the samples and assign that value to
    	 * the middle sample.  I want to use the mid-point time delta to calculate the change in velocity and distance.
    	 */
    	m_DistanceY += m_velocityY * m_CentralDeltaTimeY;  //distance = velocity times delta time

    	frc::SmartDashboard::PutNumber("Accelerometer Y",m_TempAccel);
    	frc::SmartDashboard::PutNumber("Distance Y",m_DistanceY);
    	frc::SmartDashboard::PutNumber("Velocity Y",m_velocityY);
    }

    void Accel::CalcVelocityX()
    {
    	/* What I want to do here is to calculate the average acceleration of all of the samples and assign that value to
    	 * the middle sample.  I want to use the mid-point time delta to calculate the change in velocity and distance.
    	 */
    	m_elapsedTimeX = accelTimer->Get();
    	m_deltaTimeX = m_elapsedTimeX - m_oldTimeX;
    	m_oldTimeX = m_elapsedTimeX;
    	timeVectorX[index_X] = m_deltaTimeX;
    	if ((index_X - (samples / 2)) >= 0) m_timeindex_X = index_X - (samples / 2);
    	else m_timeindex_X = samples - (samples / 2) + index_X;

    	m_CentralDeltaTimeX = timeVectorX[m_timeindex_X];
        m_velocityX += m_TempAccel *32 * m_CentralDeltaTimeX;  //velocity = acceleration times time valueof 32 added for 32 f/sec^2 of gravity
    }

    void Accel::CalcVelocityY()
    {
    	/* What I want to do here is to calculate the average acceleration of all of the samples and assign that value to
    	 * the middle sample.  I want to use the mid-point time delta to calculate the change in velocity and distance.
    	 */
    	m_elapsedTimeY = accelTimer->Get();
    	m_deltaTimeY = m_elapsedTimeY - m_oldTimeY;
    	m_oldTimeY = m_elapsedTimeY;
    	timeVectorY[index_Y] = m_deltaTimeY;
    	if ((index_Y - (samples / 2)) >= 0) m_timeindex_Y = index_Y - (samples / 2);
    	else m_timeindex_Y = samples - (samples / 2) + index_Y;

    	m_CentralDeltaTimeY = timeVectorY[m_timeindex_Y];
//     	frc::SmartDashboard::PutNumber("Central Delta Time:",m_CentralDeltaTimeY);  // this is the time for the center of the samples
        m_velocityY += m_TempAccel *32 * m_CentralDeltaTimeY;  //velocity = acceleration times time valueof 32 added for 32 f/sec^2 of gravity
    }

    double Accel::GetDistanceX()
    {
    	ReadAccelerometerX();
    	return m_DistanceX;
    }

    double Accel::GetDistanceY()
    {
    	ReadAccelerometerY();
    	return m_DistanceY;
    }

