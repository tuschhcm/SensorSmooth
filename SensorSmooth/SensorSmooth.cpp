#include "SensorSmooth.h"	//include the declaration for this class

//<<contructor>>
SensorSmooth::SensorSmooth(){}

//<<destructor>>
SensorSmooth::~SensorSmooth(){}

// get the pin to listen on for sensor data
void SensorSmooth::setSensor(int inputPin){
	sensorPin = inputPin;
}

// calculate and return the value of the smoothing algorithim
int SensorSmooth::getValue(){
	//subtract last reading
	total = total - readings[index];
	
	//read from sensor
	readings[index] = analogRead(sensorPin);
	
	//add reading to total
	total = total + readings[index];
	
	//advance to next index in array
	index++;

	//if we reach end of array, wrap around
	if(index >= numReadings){
		index = 0;
	}

	//calculate the average:
	smoothedValue = total/numReadings;

	//return the smoothed value
	return smoothedValue;
}