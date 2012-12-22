#ifndef SensorSmooth
#define SensorSmooth

#include <Arduino.h>

class SensorSmooth{
public:
        SensorSmooth(int numReadings);
        ~SensorSmooth();
        void setSensor(int inputPin);
        int getValue();
};

#endif