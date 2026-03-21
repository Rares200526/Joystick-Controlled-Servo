#include <Servo.h>

const int pinX = A1; 
const int pinY = A0; 

Servo myservo;  

void setup() {
  myservo.attach(7);
  
  // Start the serial monitor at 9600 baud rate
  Serial.begin(9600); 
}

void loop() {
  int valX = analogRead(pinX);
  int valY = analogRead(pinY);
  
  // Combine the values by calculating their average
  int combinedValue = (valX + valY) / 2;
  
  // Map the combined value to an angle between 0 and 180 degrees
  int angle = map(combinedValue, 0, 1023, 0, 180);
  
  // Move the servo to the calculated angle
  myservo.write(angle);
  
  // --- Console printing section ---
  Serial.print("Axis X: ");
  Serial.print(valX);
  Serial.print(" | Axis Y: ");
  Serial.print(valY);
  Serial.print(" | Servo angle: ");
  Serial.println(angle); // println automatically adds a new line at the end
  
  // Increased the delay slightly to 50ms so you can read the text in the console
  // (if we left it at 15ms, the text would scroll too fast)
  delay(50);
}