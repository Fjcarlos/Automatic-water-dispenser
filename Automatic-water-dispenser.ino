float distance1;
float distance2;

unsigned long previousBuzzerTime = 0;
bool buzzerState = false;

void setup() {
  Serial.begin(9600);

  pinMode(2, OUTPUT); // pump
  pinMode(3, OUTPUT); // buzzer
  pinMode(5, OUTPUT); // trigger2
  pinMode(10, OUTPUT); // trigger1
}

void loop() {

  ultrasonic1();
  Serial.println(distance1);

  // Check if cup is present
  if (distance1 < 5) {

    ultrasonic2();
    Serial.println(distance2);

    // Check liquid level
    if (distance2 < 4) {

      digitalWrite(2, LOW); // stop pump

      // Non-blocking buzzer toggle
      if (millis() - previousBuzzerTime >= 1000) {
        previousBuzzerTime = millis();
        buzzerState = !buzzerState;
        digitalWrite(3, buzzerState);
      }

    } 
    else {

      digitalWrite(3, LOW); // buzzer off
      digitalWrite(2, HIGH); // pump on

    }

  } 
  else {

    digitalWrite(3, LOW);
    digitalWrite(2, LOW);

  }

}

void ultrasonic1() {

  digitalWrite(10, LOW);
  delayMicroseconds(5);
  digitalWrite(10, HIGH);
  delayMicroseconds(10);
  digitalWrite(10, LOW);

  distance1 = pulseIn(11, HIGH);
  distance1 = distance1 * 0.0176;

}

void ultrasonic2() {

  digitalWrite(5, LOW);
  delayMicroseconds(5);
  digitalWrite(5, HIGH);
  delayMicroseconds(10);
  digitalWrite(5, LOW);

  distance2 = pulseIn(6, HIGH);
  distance2 = distance2 * 0.0176;

}
