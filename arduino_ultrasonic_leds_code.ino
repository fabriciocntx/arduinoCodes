int trigger = 2;
int echo = 3;
int dist = 0;
int ledR = 13;
int ledY = 12;
int ledG = 11;

void setup() {
  pinMode(trigger, OUTPUT);
  pinMode(echo, INPUT);
  pinMode(ledR, OUTPUT);
  pinMode(ledY, OUTPUT);
  pinMode(ledG, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigger, LOW);
  delayMicroseconds(5);
  digitalWrite(trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigger, LOW);

  dist = pulseIn(echo, HIGH);
  dist = dist / 50;

  if(dist < 40){
    digitalWrite(ledR, HIGH);
    digitalWrite(ledY, LOW);
    digitalWrite(ledG, LOW);
    Serial.println(dist);
  }
  else if(dist < 100){
    digitalWrite(ledY, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledG, LOW);
    Serial.println(dist);
  }
  else{
    digitalWrite(ledG, HIGH);
    digitalWrite(ledR, LOW);
    digitalWrite(ledY, LOW);
    Serial.println(dist);
  }
}
