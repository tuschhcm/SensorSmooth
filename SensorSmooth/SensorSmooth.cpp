#include "SensorSmooth.h"	//include the declaration for this class
#include "Arduino.h"

//<<contructor>>
SensorSmooth::SensorSmooth(int pin){
	sensorPin = pin;
	numReadings = 10;
}

// get the pin to listen on for sensor data
void SensorSmooth::setSensor(int pin){
	sensorPin = pin;
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