/*
  Activates a 3V Air Pump and Solenoid Valve using the Adafruit Motor Shield V2.
*/

#include <Wire.h>
#include <Adafruit_MotorShield.h>
#include "utility/Adafruit_MS_PWMServoDriver.h"

// Create the motor shield object with the default I2C address
Adafruit_MotorShield AFMS = Adafruit_MotorShield();

// Using ports M1 and M3 on the Motor Shield
Adafruit_DCMotor *airPump = AFMS.getMotor(1);
Adafruit_DCMotor *solenoidValve = AFMS.getMotor(3);

void setup() {
  pinMode(13, OUTPUT); // set up LED
  AFMS.begin();  // create with the default frequency 1.6KHz
}

void loop() {
  // Initialize Air Pump and Solenoid Valve
  airPump->run(FORWARD);
  solenoidValve->run(FORWARD);

  // Turn on Air Pump and LED for 3s
  airPump->setSpeed(200);
  digitalWrite(13, HIGH);
  delay(3000);

  // Turn off Air Pump and LED for 2s
  airPump->setSpeed(0);
  airPump->run(RELEASE);
  digitalWrite(13, LOW);
  delay(2000);

  // Turn on Solenoid Valve and LED for 3s
  solenoidValve->setSpeed(200);
  digitalWrite(13, HIGH);
  delay(3000);

  // Turn off Solenoid Valve and LED for 1s
  solenoidValve->setSpeed(0);
  digitalWrite(13, LOW);
  solenoidValve->run(RELEASE);
  delay(1000);
}
