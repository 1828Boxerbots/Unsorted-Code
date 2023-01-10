#include "commands/HouseCommand.h"
#include <frc/smartdashboard/SmartDashboard.h>

HouseCommand::HouseCommand(DriveTrain *trainChooChoo, Sensors *ISenseYourPresence) {
  // Use addRequirements() here to declare subsystem dependencies.
m_pDriveTrain= trainChooChoo;
m_pSensor = ISenseYourPresence;
AddRequirements(m_pDriveTrain);
AddRequirements(ISenseYourPresence);
}

// Called when the command is initially scheduled.
void HouseCommand::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void HouseCommand::Execute() 
{
  int dist1=60;
  int dist2=36;
  Move(dist1);
  Turn(40,Sensors::right);  
  Move(dist2);
  Turn(80,Sensors::right);
  Move(dist2);
  Turn(45,Sensors::right);
  Move(dist1);
  Turn(80,Sensors::right);
  Move(sqrt(2*(dist2*dist2))+7);
  Turn(90,Sensors::right);
  m_IsDone = true;
}
void HouseCommand::Turn(double angle, Sensors::Side side)
{
  switch (side){
    case Sensors::Side::left:
    Right(-fabs(angle));
    break;
    case Sensors::Side::right:
    Right(fabs(angle));
    break;
  }
}
void HouseCommand::Right(double angle){
  double old = -double(m_pSensor->GetAngle(Sensors::x));
  double New = -double(m_pSensor->GetAngle(Sensors::x));
  while(New-old<angle){
frc::SmartDashboard::PutNumber("IMU",New-old);
  New = -double(m_pSensor->GetAngle(Sensors::x));
  m_pDriveTrain->SetLeft(0.1);
  m_pDriveTrain->SetRight(0.1);
  }
  m_pDriveTrain->SetLeft(0);
  m_pDriveTrain->SetRight(0);
}
void HouseCommand::Move(double distance){
  double oldL = m_pSensor->GetEncoder(Sensors::Side::left);
  double oldR = m_pSensor->GetEncoder(Sensors::Side::right);
  double r=0.0;
  double l=0.0;
  while((l<distance)&&(r<distance)){
  r=m_pSensor->GetEncoder(Sensors::right)-oldR;
  l=m_pSensor->GetEncoder(Sensors::left)-oldL;
  m_pDriveTrain->SetLeft(0.5);
  m_pDriveTrain->SetRight(-0.5);
  frc::SmartDashboard::PutNumber("oldL",l);
  frc::SmartDashboard::PutNumber("oldR",r);
  }
  m_pDriveTrain->SetLeft(0);
  m_pDriveTrain->SetRight(0);
  
}

// Called once the command ends or is interrupted.
void HouseCommand::End(bool interrupted) {}

// Returns true when the command should end.
bool HouseCommand::IsFinished() {
  return m_IsDone;
}
