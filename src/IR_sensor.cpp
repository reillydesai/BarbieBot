#include <Romi32U4.h>
#include "IR_sensor.h"

void IRsensor::Init(void)
{
  pinMode(pin_IR, INPUT);
}

float IRsensor::PrintData(void)
{
    Serial.println(ReadData());
}

float IRsensor::ReadData(void)
{
  //read out and calibrate your IR sensor, to convert readouts to distance in [cm]
  IR_Voltage = float(analogRead(pin_IR))/1024 * 5;
  distance = 16.68/(IR_Voltage - 0.4207);   //distance in cm
  return distance;
}