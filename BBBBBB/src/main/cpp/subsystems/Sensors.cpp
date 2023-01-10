// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/Sensors.h"
#include <frc/SmartDashboard/SmartDashboard.h>
Sensors::Sensors(){
m_EncoderL.SetDistancePerPulse(17.3/360);
m_EncoderR.SetDistancePerPulse(17.3/360);
}
units::angle::degree_t Sensors::GetAngle(Axis XYZ){
switch(XYZ){
case x:
    return imu.GetGyroAngleX();
case y:
    return imu.GetGyroAngleY();
case z:
    return imu.GetGyroAngleZ();
default:
        frc::SmartDashboard::PutString("Sus","You Messed Up BIG TIME");
        return 0xfffffffff_deg;
    } 
}
double Sensors::GetEncoder(Side side){
    switch(side){
        case left:
        return double(m_EncoderL.GetDistance());
        break;
        case right:
        return double(m_EncoderR.GetDistance());
        break;
        default:
        return 0xffffffffffffffffffffffffffffffff;
    }
}
// This method will be called once per scheduler run
void Sensors::Periodic() {}
