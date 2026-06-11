#include <Servo.h>
#include <SoftwareSerial.h>

SoftwareSerial HC_05(10, 11);

const int mq2 = A0;
const int coi = 7;
const int servoPin = 8;
const int quat = 9;

int giaTri = 600;
Servo servo;

void setup() {
  Serial.begin(9600);
  HC_05.begin(9600);
  pinMode(mq2, INPUT);
  pinMode(quat, OUTPUT);
  pinMode(coi, OUTPUT);
  servo.attach(servoPin);
  servo.write(85);
}

void loop() {
  delay(2000);
  int smoke = analogRead(mq2);
  Serial.println(smoke);
  HC_05.print(smoke);
  HC_05.print(",");
  if (smoke > giaTri) {
    digitalWrite(coi, HIGH);
    digitalWrite(quat, HIGH);
    HC_05.print("Nguy Hiem");
    servo.write(0);
  } else {
    digitalWrite(coi, LOW);
    digitalWrite(quat, LOW);
    HC_05.print("An Toan");
    servo.write(85);
  }
  HC_05.print(";");
}