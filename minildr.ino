
#define relay 10
int LED = 9;
int LDR = A0;

//Motion Sensor
int MS = 3;

int motionStateCurrent = LOW;
int motionStatePrevious = LOW;

void setup() 
{
Serial.begin(9600);
pinMode(LED, OUTPUT);
pinMode(relay, OUTPUT);
pinMode(LDR, INPUT);
//Motion Sensor
pinMode(MS, INPUT);
}

void loop() {
int LDRValue = analogRead(LDR);
Serial.print("sensor = ");
Serial.print(LDRValue);

//Motion Sensor
motionStatePrevious = motionStateCurrent;
motionStateCurrent = digitalRead(MS);

 

if (LDRValue <=600) 
 {
  digitalWrite(LED, LOW);
//  digitalWrite(relay, LOW);
  Serial.println("It's Bright Outside; Lights status: OFF");

   if(motionStatePrevious == LOW && motionStateCurrent == HIGH){
      Serial.println("Motion detected");
      digitalWrite(LED, HIGH);
      digitalWrite(relay, HIGH);
      delay(2000);
      Serial.println("Hi");
 }

  else if(motionStatePrevious == HIGH && motionStateCurrent == LOW){
      Serial.println("Motion STOPPED");
      digitalWrite(LED, LOW);
      digitalWrite(relay, LOW);
    }
  
 }

 else {
digitalWrite(LED, LOW);
digitalWrite(relay, HIGH);
Serial.println("It's Dark Outside; Lights status: SOFF");
}

}
