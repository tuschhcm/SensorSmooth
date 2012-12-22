#include <SensorSmooth.h>

#define SENSORP0 0
#define SENSORP1 1
#define SENSORP2 2
#define LEDR 9
#define LEDG 10
#define LEDB 11
  
// create new sensor smoothing objects
SensorSmooth pot1(SENSORP0);
SensorSmooth pot2(SENSORP1);
SensorSmooth pot3(SENSORP2);

void setup(){
  pinMode(LEDR, OUTPUT);
  pinMode(LEDG, OUTPUT);
  pinMode(LEDB, OUTPUT);
}

void loop(){
  // Write the values to the LED's
  
  int pot1Inverted = map(pot1.getValue(), 0, 1023, 1023, 0);
  analogWrite(LEDR, pot1Inverted/4);
  analogWrite(LEDG, pot2.getValue()/4);
  analogWrite(LEDB, pot3.getValue()/4);
  delay(1);
}
