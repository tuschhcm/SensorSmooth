#include "SensorSmooth.h"	//include the declaration for this class

int sensorPin;				//pin to listen on
int numReadings;			//size of array to average
int readings[numReadings];	//initialize array to hold sensor data
int index = 0;				//current reading
int total = 0;				//running total
int smoothedValue = 0;		//the average of sensor values

//<<contructor>> set the size of the array
SensorSmooth::SensorSmooth(int n){
	numReadings = n;
}

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