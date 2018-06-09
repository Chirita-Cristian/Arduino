#define trigPin 3 //Sensor Echo pin connected to Arduino pin 13
#define echoPin 5 //Sensor Trip pin connected to Arduino pin 12
const byte redPin=8;
const byte greenPin=7;
//Simple program just for testing the HC-SR04 Ultrasonic Sensor with LCD dispaly 
//URL:

void setup() 
{ 
  Serial.begin(9600); 
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(redPin,OUTPUT);
  pinMode(greenPin,OUTPUT);
 
}

void loop() {
  long duration, distance;
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  duration = pulseIn(echoPin, HIGH);
  distance = (duration/2) / 29.1;
if(distance<10)
{
  digitalWrite(greenPin,LOW);
  digitalWrite(redPin,HIGH);
  
}
else{
  digitalWrite(redPin,LOW);
  digitalWrite(greenPin,HIGH);
}
  Serial.print(distance);
  Serial.println(" cm");
  delay(300);
}

