#include "Drivers/imu.hpp"

Imu::Imu(){
m_pDevice = new frc::ADIS16448_IMU;
}
float Imu::getAngle(angle axis){
if (axis==x){
return m_pDevice->GetGyroAngleX();
}
else if (axis==y){
return m_pDevice->GetGyroAngleY();
}else{
return m_pDevice->GetGyroAngleZ();
}

}
void Imu::Reset(){
m_pDevice->Reset();
}