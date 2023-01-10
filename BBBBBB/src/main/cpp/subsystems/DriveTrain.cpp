// Copyright (c) FIRST and other WPILib contributors.
// Open Source Software; you can modify and/or share it under the terms of
// the WPILib BSD license file in the root directory of this project.

#include "subsystems/DriveTrain.hpp"

DriveTrain::DriveTrain() = default;

// This method will be called once per scheduler run
void DriveTrain::Periodic() {}
void DriveTrain::SetLeft(float power){
    m_motorL.Set(power);
}
void DriveTrain::SetRight(float power){
    m_motorR.Set(power);
}