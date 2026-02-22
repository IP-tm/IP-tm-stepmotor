#pragma once
#include <Arduino.h>

enum Unit { STEPS, CM };
enum Dir { CW, CCW };

class SuperStepper {

public:

  SuperStepper(uint8_t stepPin, uint8_t dirPin);

  void run(long distance, Dir direction); // Easy

  void run(long distance, Unit unit, Dir direction, int pulseUs); // Pro

  void run(long distance, Unit unit, Dir direction,
           int pulseUs, bool enable, bool sleep); // Expert

  // Calibration
  void setStepsPerCM(float value);
  void setZero();
  void setMaxPosition(long pos);

private:

  uint8_t _stepPin;
  uint8_t _dirPin;

  float _stepsPerCM = 100;
  long _position = 0;
  long _maxPos = 100000;

  void stepPulse(int delayUs);
};
