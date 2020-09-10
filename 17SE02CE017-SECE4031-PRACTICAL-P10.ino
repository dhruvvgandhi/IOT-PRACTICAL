#include <Stepper.h>
Const int spr = 200;
Stepper myStepper(stepsPerRevolution, 8, 9, 10, 11);

Void setup() {
	mySteper.setSpeed(60);
	Serial.begin(9600);
}

Void loop() {
	Serial.println(“Clockwise”);
myStepper.step(spr);
delay(1000);
Serial.println(“counterclockwise”);
myStepper.step(-spr);
delay(1000);
}
