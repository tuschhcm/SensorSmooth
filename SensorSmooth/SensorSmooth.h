#ifndef SensorSmooth_h
#define SensorSmooth_h

#include <Arduino.h>

class SensorSmooth
{
  public:
    SensorSmooth(int pin);
    void setSensor(int pin);
    int getValue();
  private:
    int sensorPin;	//pin to listen on
    int index;		//current reading
    int total;		//running total
    int smoothedValue;	//the average of sensor values
    int readings[10];	//initialize array to hold sensor data
    int numReadings;    //total number of readings in the array
};

#endif