/*
 * HC-SR04 example sketch
 *
 * https://create.arduino.cc/projecthub/Isaac100/getting-started-with-the-hc-sr04-ultrasonic-sensor-036380
 *
 * by Isaac100
 */
const byte ledPin=11;
const int trigPin = 2;
const int echoPin = 10;
volatile byte state=LOW;
volatile long distance,duration;

void setup() {
  pinMode(ledPin, OUTPUT);
  attachInterrupt(digitalPinToInterrupt(trigPin),triggerisr,CHANGE);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  Serial.begin(9600);
}
void triggerisr(){
 duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
  
  if (distance < 15) { state=HIGH;}
  else state=LOW;
}
void loop() {
  digitalWrite(trigPin, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10); // Added this line
  digitalWrite(trigPin, LOW);
   digitalWrite(ledPin,state);
    Serial.print(distance);
    Serial.println(" cm");
  delay(500);
}
