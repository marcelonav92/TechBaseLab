#include <Arduino.h>
#include <ESP32Servo.h>

Servo servo;

#define SERVO_PIN 18

void setup()
{
    Serial.begin(115200);

    servo.attach(SERVO_PIN);

    Serial.println("Teste SG90 iniciado.");
}

void loop()
{
    Serial.println("0 graus");
    servo.write(0);
    delay(1000);

    Serial.println("90 graus");
    servo.write(90);
    delay(1000);

    Serial.println("180 graus");
    servo.write(180);
    delay(1000);
}