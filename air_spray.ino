//radar
#define echoPin 2 // attach pin D2 Arduino to pin Echo of HC-SR04
#define trigPin 3 //attach pin D3 Arduino to pin Trig of HC-SR04
long duration; // variable for the duration of sound wave travel
int distance; // variable for the distance measurement

//movement
int motionPin = 4;
int motionStat = 0;

int outPin = 5;

int triggerDist = 50;

void setup() {
  pinMode(trigPin, OUTPUT); // Sets the trigPin as an OUTPUT
  pinMode(echoPin, INPUT); // Sets the echoPin as an INPUT
  pinMode(motionPin, INPUT);
  pinMode(outPin, OUTPUT);
  digitalWrite(outPin, HIGH);
  delay(2000);
}
void loop() {
  // Clears the trigPin condition
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  // Sets the trigPin HIGH (ACTIVE) for 10 microseconds
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  // Reads the echoPin, returns the sound wave travel time in microseconds
  duration = pulseIn(echoPin, HIGH);
  // Calculating the distance
  distance = duration * 0.034 / 2; // Speed of sound wave divided by 2 (go and back)

  motionStat = digitalRead(motionPin);

  if(motionStat == HIGH && distance <= triggerDist){
    digitalWrite(outPin, LOW);
    delay(500);
    digitalWrite(outPin, HIGH);
    delay(5000);
  }
}
