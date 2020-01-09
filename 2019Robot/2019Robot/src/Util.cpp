#include "src/Util.h"

double Utility::ToggleSwitch(bool thirdToggle)
{
    Utility::timer.Reset();

    Utility::motorEncoder.SetDistancePerPulse(1.0 / 360 * 2.0 * Utility::pi * 29);
    //double distance = Utility::motorEncoder.GetDistance();

    //Control for Default Position; 90 degrees
    while(Utility::controller.GetAButtonPressed() == true && thirdToggle == true)
    {
        Utility::timer.Start();

        if(Utility::timer.Get() >= 10)
        {
            Utility::angle = 90;
            Utility::var = 2;
        }
    }

    //Control for Postion 2; 0 degrees
    if(Utility::controller.GetAButtonPressed() == true && Utility::var == 2 && Utility::angle == 0)
    {
        Utility::angle = 0;
        Utility::var = 1;
    }

    //Controlfor Postion 1; 45 degrees
    if(Utility::controller.GetAButtonPressed() == true && Utility::var == 1 && Utility::angle == 0)
    {
        Utility::angle = 45;
        Utility::var = 2;
    }
    
    //Converts the degrees to radians
    double degrees =  Utility::angle * (Utility::pi / 180);

    return degrees;
}