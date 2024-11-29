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

    for(int i = 0; i < calibrationTime; i++){
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
         Serial.print(millis()/1000);
         Serial.println(" sec"); 
         delay(50);
    }
    motionStartTime = millis(); // update the motion start time
    digitalWrite(LED_PIN, HIGH); // turn on the LED
  } else {
    if (motionStartTime != 0 && millis() - motionStartTime > motionTimeout) {
      Serial.print("Motion ended at ");
      Serial.print(millis()/ 1000);
      Serial.println(" sec");
      motionStartTime = 0; // reset the motion start time
      digitalWrite(LED_PIN, LOW); // turn off the LED
      delay(50);
    }
  }
}
