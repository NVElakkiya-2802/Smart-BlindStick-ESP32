#define TRIG 5
#define ECHO 18
#define LED 2
#define BUZZER 4

long duration;
int distance;

void setup() {
  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);
  pinMode(LED, OUTPUT);
  pinMode(BUZZER, OUTPUT);
  Serial.begin(115200);
}

void loop() {
  digitalWrite(TRIG, LOW);
  delayMicroseconds(2);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  duration = pulseIn(ECHO, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < 50) {   // obstacle detected
    digitalWrite(LED, HIGH);
    digitalWrite(BUZZER, HIGH);
  } else {
    digitalWrite(LED, LOW);
    digitalWrite(BUZZER, LOW);
  }

  delay(200);
}
