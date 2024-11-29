
 Automated Light System Using PIR Motion Sensor  

Description  
This project demonstrates an automated light system that uses a Passive Infrared (PIR) motion sensor to detect movement and control an LED. When motion is detected, the LED turns on, and it turns off after a timeout period if no further motion is detected. This simple yet efficient system is ideal for smart home automation.  


Features  
- Detects motion using a PIR sensor.  
- Controls an LED to simulate an automated light system.  
- Includes a timeout feature to turn off the LED after 5 seconds of no motion.  
- Calibration phase ensures the PIR sensor is ready to detect movement.  


Code Overview  


#define PIR_PIN 27      // the digital pin connected to the PIR sensor's output
#define LED_PIN 26      // the digital pin connected to the LED output

unsigned long motionStartTime = 0;
const unsigned long motionTimeout = 5000; // 5 seconds timeout
int calibrationTime = 20;

void setup() {
  Serial.begin(115200);
  pinMode(PIR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
  digitalWrite(LED_PIN, LOW); // turn off LED initially

  for (int i = 0; i < calibrationTime; i++) {
    Serial.print(".");
    delay(1000);
  }
  Serial.println(" Calibration done");
  Serial.println("SENSOR ACTIVE");
  delay(50);
}

void loop() {
  if (digitalRead(PIR_PIN) == HIGH) {
    if (motionStartTime == 0) {
      Serial.print("Motion detected at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      delay(50);
    }
    motionStartTime = millis(); // update the motion start time
    digitalWrite(LED_PIN, HIGH); // turn on the LED
  } else {
    if (motionStartTime != 0 && millis() - motionStartTime > motionTimeout) {
      Serial.print("Motion ended at ");
      Serial.print(millis() / 1000);
      Serial.println(" sec");
      motionStartTime = 0; // reset the motion start time
      digitalWrite(LED_PIN, LOW); // turn off the LED
      delay(50);
    }
  }
}



Installation  

Hardware Requirements  
- Microcontroller: ESP32.  
- Sensors/Actuators:  
  - Passive Infrared (PIR) motion sensor.  
  - LED.  
- Miscellaneous: Resistors, breadboard, jumper wires.  

Software Requirements  
- IDE: Arduino IDE with ESP32 board manager installed.  

Wiring Diagram  
1. PIR Sensor:  
   - Signal pin to GPIO 27.  
   - VCC to 3.3V.  
   - GND to GND.  
2. LED:  
   - Positive leg to GPIO 26 (via resistor).  
   - Negative leg to GND.  



Usage Instructions  
1. Clone this repository or copy the code.  
2. Open the code in the Arduino IDE.  
3. Select the appropriate ESP32 board and port from the -Tools- menu.  
4. Upload the code to the ESP32.  
5. Connect the PIR sensor and LED as per the wiring diagram.  
6. Monitor the serial output for motion detection logs.  



Technologies Used  
- Microcontroller: ESP32.  
- Sensors: PIR motion sensor.  
- Programming Language: C/C++.  
- Development Tools: Arduino IDE.  




