#ifndef SensorSmooth
#define SensorSmooth

#include <Arduino.h>

class SensorSmooth{
public:
        SensorSmooth();
        void setSensor(int inputPin);
        int getValue();
private:
	int sensorPin;			//pin to listen on
	int readings[10];		//initialize array to hold sensor data
	int index = 0;			//current reading
	int total = 0;			//running total
	int smoothedValue = 0;		//the average of sensor values
};

#endif