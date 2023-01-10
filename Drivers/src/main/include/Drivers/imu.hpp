#pragma once
#include <adi/ADIS16448_imu.h>
class Imu
{
    public:
    Imu();
void Reset();
    enum angle{x=0,y=1,z=2};
float getAngle(angle axis);
    private:
    frc::ADIS16448_IMU *m_pDevice = nullptr;
};