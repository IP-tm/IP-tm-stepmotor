#include <SuperStepper.h>

SuperStepper motor(21, 22);

void setup() {

  motor.setStepsPerCM(95); // calibration

  motor.run(5, CM, CW, 400);

}

void loop() {}
