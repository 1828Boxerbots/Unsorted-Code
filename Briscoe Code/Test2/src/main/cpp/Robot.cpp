// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include <frc/motorcontrol/Victor.h>
#include <frc/TimedRobot.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/Encoder.h>
#include <frc/Timer.h>

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

void TeleopInit() override
{
  double N = 363;
  double dia = 5.5; //In inches
  double c = 3.14*dia;
  m_encoderL.Reset();
  m_encoderR.Reset();
  m_encoderS.Reset();
m_encoderL.SetDistancePerPulse(c/N*1);
m_encoderR.SetDistancePerPulse(c/N*1);

m_Shooter.Set(0.1);

}
  void TeleopPeriodic() override 
  {
    double pR = m_encoderR.Get();
    double pL = m_encoderL.Get();
    double pS = m_encoderS.Get();
    double dL = m_encoderL.GetDistance();
    double dR = m_encoderR.GetDistance();
    units::second_t CurT = m_clock.Get();
    double Rate = m_encoderS.GetRate();
   double Calcrate = (pS-m_PrePS)/(double)(CurT-m_PreT);

    frc::SmartDashboard::PutNumber("Right Distance: ", dR);
    frc::SmartDashboard::PutNumber("Left Distance: ", dL);
    frc::SmartDashboard::PutNumber("Right Pulses: ", pR);
    frc::SmartDashboard::PutNumber("Left Pulses: ", pL);
    frc::SmartDashboard::PutNumber("Shooter Pulses: ", pS);
    frc::SmartDashboard::PutNumber("Shooter Speed: ", (double)CurT);
    frc::SmartDashboard::PutNumber("Shooter Rate: ", Rate);
    frc::SmartDashboard::PutNumber("Shooter CalcRate: ", Calcrate);

    m_PreT = CurT;
    m_PrePS = pS;
  }

 private:
 frc::Victor m_Shooter{3};
  frc::Encoder m_encoderR{0,1};
  frc::Encoder m_encoderL{2,3};
  frc::Encoder m_encoderS{4,5};
    frc::Timer m_clock;
    units::second_t m_PreT;
double m_PrePS;

};

#ifndef RUNNING_FRC_TESTS
int main() {
  return frc::StartRobot<Robot>();
}
#endif
