#include <Arduino.h>

#define TRIG_PIN 5
#define ECHO_PIN 18

void setup()
{
    Serial.begin(115200);

    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);

    Serial.println();
    Serial.println("=== Teste HC-SR04 ===");
}

void loop()
{
    long duracao;
    float distanciaCm;

    // Garantir pulso limpo
    digitalWrite(TRIG_PIN, LOW);
    delayMicroseconds(2);

    // Pulso de trigger
    digitalWrite(TRIG_PIN, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_PIN, LOW);

    // Leitura do echo
    duracao = pulseIn(ECHO_PIN, HIGH);

    // Conversão para centímetros
    distanciaCm = duracao * 0.0343 / 2.0;

    Serial.print("Distancia: ");
    Serial.print(distanciaCm);
    Serial.println(" cm");

    delay(500);
}