
const int MOTION_SENSOR_PIN = 7;
const int LED_PIN = 13;
int motionStateCurrent = LOW;
int motionStatePrevious = LOW;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(MOTION_SENSOR_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  motionStatePrevious = motionStateCurrent;
  motionStateCurrent = digitalRead(MOTION_SENSOR_PIN);

  if(motionStatePrevious == LOW && motionStateCurrent == HIGH){
      Serial.println("Motion detected");
      digitalWrite(LED_PIN, HIGH);
      delay(5000);
      Serial.println("Hi");
      return 0;

      
  }
  else if(motionStatePrevious == HIGH && motionStateCurrent == LOW){
      Serial.println("Motion STOPPED");
      digitalWrite(LED_PIN, LOW);
    }

}
