#include <Servo.h>

// Define the servo motors and sensor pin
Servo servoMotor1;
Servo servoMotor2;
int moistureSensorPin = A0;
int moistureThreshold = 700; // Adjust this threshold as needed

void setup() {
  servoMotor1.attach(9);  // Servo motor 1 pin
  servoMotor2.attach(10); // Servo motor 2 pin
  // Additional setup code for sensor pin and other configurations...
  servoMotor1.write(90);  // Initially, set servo 1 to the highest position.
  servoMotor2.write(90);  // Initially, set servo 2 to the highest position.
  Serial.begin(9600); // Initialize serial communication for debugging
}

void loop() {
  int moistureLevel = analogRead(moistureSensorPin);

  // Check moisture level against the threshold
  if (moistureLevel > moistureThreshold) {
    lowerBridge(); // Call the function to lower the bridge
  } else {
    returnToNormal();
  }
  delay(1000); // Delay before the next reading
}

void lowerBridge() {
  // Lower the bridge heights using the servo motors
  servoMotor1.write(0); // You might need to calibrate this angle for servo 1
  servoMotor2.write(0); // You might need to calibrate this angle for servo 2
  delay(1000); // Delay for the servo movement (adjust as needed)
}

void returnToNormal() {
  // Return both servos to the highest position
  servoMotor1.write(90);
  servoMotor2.write(90);
  delay(1000); // Delay before the next operation
}
