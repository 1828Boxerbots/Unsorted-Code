// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <cmath>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Encoder.h>
#include <frc/motorcontrol/Victor.h>
#include <frc/ADIS16448_IMU.h>

/**
 * This sample program shows how to control a motor using a joystick. In the
 * operator control part of the program, the joystick is read and the value is
 * written to the motor.
 *
 * Joystick analog values range from -1 to 1 and speed controller inputs as
 * range from -1 to 1 making it easy to work together.
 */
class Robot : public frc::TimedRobot {
 public:

  void Forward(double distance, double Speed)
  {
    double startingposition = m_encoderS.GetDistance();

    m_motorS.Set(Speed);

    double currentdistance;

    do
    {
      frc::SmartDashboard::PutNumber("CurrentDistance", currentdistance);
      double currentposition = m_encoderS.GetDistance();

      currentdistance = currentposition - startingposition;
      
      } while(currentdistance < distance);

      m_motorS.Set(0);
  }

  void Turn(double angle, double speed)
  {
    units::degree_t startingangle = m_imu.GetGyroAngleX();

    if (angle < 0)
    {
      m_motorS.Set(fabsf(speed));
    }
    else
    {
      m_motorS.Set(-fabsf(speed));
    }

      double difangle;
    do
    {
      
      units::degree_t currentangle = m_imu.GetGyroAngleX();

      difangle = (double)(currentangle - startingangle);

frc::SmartDashboard::PutNumber("Difference Angle", difangle);
      frc::SmartDashboard::PutNumber("Current Angle", (double)currentangle);
      frc::SmartDashboard::PutNumber("Starting Angle", (double)startingangle);

    }while (fabsf(difangle) <fabsf(angle));
    
    m_motorS.Set(0);
  }

  void TeleopInit() override 
  { 
    double N = 363;
    double diameter = 5.5;
    double circumference = 3.14*diameter;
    double distanceperpulse = circumference/N;

    m_encoderS.SetDistancePerPulse(distanceperpulse);
     m_encoderS.Reset();
    m_motorS.Set(0);
    m_imu.Reset();

    House();
  }

  void House()
  {
    double dist = 12;
    double spd = -0.1;
   // Forward(dist, spd);
    double angle =  -45;
    Turn(angle,spd);
  }

 private:
  frc::Victor m_motorS{3};
  frc::Encoder m_encoderS{4,5};
  frc::ADIS16448_IMU m_imu;
};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
