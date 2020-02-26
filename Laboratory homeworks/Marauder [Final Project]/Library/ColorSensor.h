#ifndef ColorSensor_h
#define ColorSensor_h
#include "Arduino.h"

// A class for color sensor
class ColorSensor {
   private:
    int pinS0;
    int pinS1;
    int pinS2;
    int pinS3;  
    
    // Pin for output
    int pinOut; 

    // Variables for Color Pulse Width Measurements
    int redPW;
    int greenPW;
    int bluePW;
    
    public: 
        ColorSensor(int S0, int S1, int S2, int S3, int sensorOut);
        void PinSetup();
        int getColor();	
	int getRedPW();
        int getGreenPW();
        int getBluePW();
};
#endif