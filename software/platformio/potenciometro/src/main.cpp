#include <Arduino.h>

#define POT_PIN 34

int valorPot = 0;

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println();
    Serial.println("=== TESTE POTENCIOMETRO ESP32 ===");

    analogReadResolution(12); // 0 - 4095
}

void loop()
{
    long soma = 0;

    // Média para estabilizar leitura
    for (int i = 0; i < 10; i++)
    {
        soma += analogRead(POT_PIN);
        delay(2);
    }

    valorPot = soma / 10;

    // Conversão para tensão
    float tensao = (valorPot / 4095.0) * 3.3;

    Serial.print("ADC: ");
    Serial.print(valorPot);

    Serial.print(" | Tensao: ");
    Serial.print(tensao, 2);

    Serial.println(" V");

    delay(200);
}