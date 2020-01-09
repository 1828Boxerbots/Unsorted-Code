#pragma once

#include <frc/XboxController.h>
#include <frc/Timer.h>
#include <frc/Encoder.h>

class Utility
{
public:
    
    Utility();

    double ToggleSwitch(bool thirdToggle);

private:
    frc::XboxController controller {0};
    frc::Timer timer;
    frc::Encoder motorEncoder {0,1, false, frc::Encoder::EncodingType::k4X};
    
    double var = NULL;
    //Put the angle in the degree form NOT radian
    double angle = 45;
    double pi = 3.1415;
};