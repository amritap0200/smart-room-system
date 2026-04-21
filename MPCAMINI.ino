#include <DHT.h>

// ----- DHT -----
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);

// ----- Ultrasonic -----
#define TRIG 3
#define ECHO 4

// ----- MQ2 -----
#define MQ2 A0

// ----- Solar -----
#define SOLAR A1

// ----- Buzzer -----
#define BUZZER 8

void setup() {
  Serial.begin(9600);

  dht.begin();

  pinMode(TRIG, OUTPUT);
  pinMode(ECHO, INPUT);

  pinMode(BUZZER, OUTPUT);
  digitalWrite(BUZZER, LOW); // OFF
}

void loop() {

  // ---------- ULTRASONIC ----------
  digitalWrite(TRIG, LOW);
  delayMicroseconds(5);
  digitalWrite(TRIG, HIGH);
  delayMicroseconds(10);
  digitalWrite(TRIG, LOW);

  long duration = pulseIn(ECHO, HIGH, 30000);
  float distance = (duration == 0) ? -1 : duration * 0.0343 / 2;

  // ---------- DHT ----------
  float temp = dht.readTemperature();

  // ---------- MQ2 ----------
  int gasValue = analogRead(MQ2);

  // ---------- SOLAR ----------
  int solarValue = analogRead(SOLAR);
  float solarVoltage = solarValue * (5.0 / 1023.0) * 2;

  // ---------- PRINT VALUES ----------
  Serial.print("Dist: ");
  Serial.print(distance);
  Serial.print(" cm | Temp: ");
  Serial.print(temp);
  Serial.print(" | Gas: ");
  Serial.print(gasValue);
  Serial.print(" | Solar: ");
  Serial.println(solarVoltage);

  // ---------- CONDITIONS ----------
  bool tooClose = (distance != -1 && distance < 20);
  bool smoke = (gasValue > 450);
  bool highTemp = (temp > 30);
  bool brightSun = (solarVoltage > 4.0);

  // ---------- PRIORITY LOGIC ----------

  // 1. DISTANCE ALERT (highest priority)
  if (tooClose) {
    Serial.println("Too close");

    digitalWrite(BUZZER, HIGH);
    delay(300);
    digitalWrite(BUZZER, LOW);
    delay(300);
  }

  //  2. SMOKE ALERT
  else if (smoke) {
    Serial.println("Smoke detected");

    for (int i = 0; i < 8; i++) {
      digitalWrite(BUZZER, HIGH);
      delay(200);
      digitalWrite(BUZZER, LOW);
      delay(200);
    }
  }

  //  3. TEMPERATURE ALERT
  else if (highTemp) {
    Serial.println(" Please turn on the AC");

    digitalWrite(BUZZER, HIGH);
    delay(800);
    digitalWrite(BUZZER, LOW);
  }

  //  4. SUNLIGHT ALERT
  else if (brightSun) {
    Serial.println("Close the curtains, too much sunlight!");
    digitalWrite(BUZZER, LOW);
  }

  // NORMAL
  else {
    Serial.println("All conditions normal");
    digitalWrite(BUZZER, LOW);
  }

  delay(2000);
}
