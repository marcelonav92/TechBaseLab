#include <Arduino.h>

void setup()
{
    Serial.begin(115200);

    delay(1000);

    Serial.println();
    Serial.println("==================================");
    Serial.println(" HardwareLab - ESP32 TESTE BASE ");
    Serial.println("==================================");

    Serial.println("ESP32 inicializado com sucesso.");
    Serial.println("Teste basico de boot.");
    Serial.println("Reset automatico em 10 segundos...");
}

void loop()
{
    static unsigned long inicio = millis();

    Serial.print("Uptime: ");
    Serial.print((millis() - inicio) / 1000);
    Serial.println(" segundos");

    delay(1000);

    if ((millis() - inicio) >= 10000)
    {
        Serial.println();
        Serial.println("Reiniciando ESP32...");
        delay(1000);

        ESP.restart();
    }
}