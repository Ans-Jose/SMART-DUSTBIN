#include <Servo.h>

Servo sampleServo;  

const int pHSensorPin = A0;   
const int servoPin    = 9;   

float pHValue;  
int thresholdLow = 6;   
int thresholdHigh = 8;  

void setup() {
  Serial.begin(9600);         
  sampleServo.attach(servoPin);
  sampleServo.write(0);     
}

void loop() {
  int sensorValue = analogRead(pHSensorPin);
  pHValue = map(sensorValue, 0, 1023, 0, 140) / 10.0; 

  
  Serial.print("pH Value: ");
  Serial.println(pHValue);

 
  if (pHValue < thresholdLow || pHValue > thresholdHigh) {
    Serial.println(" Abnormal pH detected! Collecting sample...");
    sampleServo.write(90); 
    delay(2000);           
    sampleServo.write(0);  
  }
  else {
    Serial.println("pH level is safe.");
  }

  delay(3000); 
}
