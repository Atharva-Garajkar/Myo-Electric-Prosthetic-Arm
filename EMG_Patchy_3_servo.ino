#include <Servo.h>

// Define servos
Servo servo1;
Servo servo2;
Servo servo3;

// Define pins
const int emgPin = A1; // EMG signal input pin
const int servoPin1 = 9; 
const int servoPin2 = 10; 
const int servoPin3 = 11;

// Threshold for EMG activation
int emgThreshold = 500;  // Adjust based on your setup

void setup() {
  // Attach servos to pins
  servo1.attach(servoPin1);
  servo2.attach(servoPin2);
  servo3.attach(servoPin3);

  // Initialize serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  // Read the EMG signal
  int emgValue = analogRead(emgPin);
  
  // Debugging purpose: print EMG value
  Serial.println(emgValue);

  // Control servo 1 based on EMG signal
  if (emgValue > emgThreshold) {
    servo1.write(90);  // Move servo to a specific angle (e.g., 90 degrees)
    servo2.write(90);  // Move servo to a specific angle (e.g., 90 degrees)
    servo3.write(90);  // Move servo to a specific angle (e.g., 90 degrees)
  } else {
    servo1.write(0);   // Default position (e.g., 0 degrees)
    servo2.write(0);   // Default position (e.g., 0 degrees)
    servo3.write(0);   // Default position (e.g., 0 degrees)

  
  }
  
  // Add a small delay to stabilize readings
  delay(500);
}