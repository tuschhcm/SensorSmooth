#include <SensorSmooth.h>

#define SENSORP0 0
#define SENSORP1 1
#define SENSORP2 2
#define LEDR 9
#define LEDG 10
#define LEDB 11

const int numReadings = 10; // set the number of readings to average

// create new sensor smoothing objects
SensorSmooth pot1(numReadings);
SensorSmooth pot2(numReadings);
SensorSmooth pot3(numReadings);

// Set the sensors the sensorsmooth objects listen too
pot1.setSensor(SENSORP0);
pot2.setSensor(SENSORP1);
pot3.setSensor(SENSORP2);

void setup(){
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop(){
  // Write the values to the LED's
  analogWrite(LEDR, pot1.getValue());
  analogWrite(LEDG, pot2.getValue());
  analogWrite(LEDB, pot3.getValue());
}
