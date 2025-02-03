#include<iostream>
#include<string>

//#include<ImplantApi.h>

#define Pulse 75

#define Temp 36.6

#define Signal 90
#define Battery 80

namespace Implant
{
    class PseudoImplant
    {
        public:
            PseudoImplant()
            {
                srand(time(0));
            }

            unsigned short GetPulse()
            {
                return Pulse;
            }

            double GetTemp()
            {
                return Temp;
            }

            unsigned short GetSignalStrength()
            {
                return Signal;
            }

            unsigned short GetBattery()
            {
                return Battery;
            }

            std::string GetAll()
            {
                return "Pulse: " + std::to_string(Pulse) + " bpm; " + 
                "Temp: " + std::to_string(Temp) + " C; " + 
                "Signal Strength: " + std::to_string(Signal) + "%; " + 
                "Battery: " + std::to_string(Battery) + "%;";
            }

            std::string GetRandomParameters()
            {
                short RandomNum = rand() % 4;

                switch (RandomNum)
                {
                case 0:
                    return "Pulse: " + std::to_string(GetPulse());
                    break;

                case 1:
                    return "Temp: " + std::to_string(GetTemp());
                    break;

                case 2:
                    return "Signal: " + std::to_string(GetSignalStrength());
                    break;

                case 3:
                    return "Battery: " + std::to_string(GetBattery());
                    break;
                    
                default:
                    break;
                }
                return "";
            }
    };
}
