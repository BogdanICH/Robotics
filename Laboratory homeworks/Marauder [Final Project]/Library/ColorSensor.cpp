#include "ColorSensor.h"
#include "Arduino.h"

ColorSensor::ColorSensor(int S0, int S1, int S2, int S3, int sensorOut) {
        pinS0 = S0;
        pinS1 = S1;
        pinS2 = S2;
        pinS3 = S3;
        pinOut = sensorOut;
        redPW = 0;
        greenPW = 0;
        bluePW = 0;
}

void ColorSensor::PinSetup() {
        pinMode(pinS0, OUTPUT);
        pinMode(pinS1, OUTPUT);
        pinMode(pinS2, OUTPUT);
        pinMode(pinS3, OUTPUT);
        
        // Set Sensor output as input
        pinMode(pinOut, INPUT);
        
        // Set Pulse Width scaling to 20%
        digitalWrite(pinS0, HIGH);
        digitalWrite(pinS1, LOW);
}

// Function with which I can get the color of the object
int ColorSensor::getColor() {
        int countRed = 0, countGreen = 0, countBlue = 0, maxim = 0, color = 0;
      
        // This is a loop for calculate with precision the color
       for (int i = 0; i < 2; i++) {
             // Read Red Pulse Width
            redPW = getRedPW();
            // Delay to stabilize sensor
            delay(200);
            
            // Read Green Pulse Width
            greenPW = getGreenPW();
            // Delay to stabilize sensor
            delay(200);
            
            // Read Blue Pulse Width
            bluePW = getBluePW();
            // Delay to stabilize sensor
            delay(200);
      
            if (redPW < greenPW && redPW < bluePW) {
                countRed++; 
                if (maxim < countRed) {
                   maxim = countRed;
                   color = 1;
                }
            }
            if (greenPW < redPW && greenPW < bluePW) {
                countGreen++; 
                if (maxim < countGreen) {
                   maxim = countGreen;
                   color = 2;
                }
            }
            if (bluePW < greenPW && bluePW < redPW){
                countBlue++; 
                if (maxim < countBlue) {
                   maxim = countBlue;
                   color = 3;
                }
            }
            
        }
        return color;
}

// Function to read Red Pulse Widths
int ColorSensor::getRedPW() {
       
        // Set sensor to read Red only
        digitalWrite(pinS2, LOW);
        digitalWrite(pinS3, LOW);

        // Define integer to represent Pulse Width
        int PW;

        // Read the output Pulse Width
        PW = pulseIn(pinOut, LOW);

        // Return the value
        return PW;
      }

// Function to read Green Pulse Widths
int ColorSensor::getGreenPW() {
       
        // Set sensor to read Green only
        digitalWrite(pinS2, HIGH);
        digitalWrite(pinS3, HIGH);

        // Define integer to represent Pulse Width
        int PW;

        // Read the output Pulse Width
        PW = pulseIn(pinOut, LOW);

        // Return the value
        return PW;
}
       
// Function to read Blue Pulse Widths
int ColorSensor::getBluePW() {
       
        // Set sensor to read Blue only
        digitalWrite(pinS2, LOW);
        digitalWrite(pinS3, HIGH);

        // Define integer to represent Pulse Width
        int PW;

        // Read the output Pulse Width
        PW = pulseIn(pinOut, LOW);

        // Return the value
        return PW;
}