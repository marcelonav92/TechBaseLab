#include <Arduino.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_SDA 22
#define OLED_SCK 21

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void setup()
{
    Serial.begin(115200);
    delay(1000);

    Wire.begin(OLED_SDA, OLED_SCK);

    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C))
    {
        Serial.println("Falha ao inicializar OLED.");
        while (true);
    }

    display.clearDisplay();

    display.setTextSize(2);
    display.setTextColor(SSD1306_WHITE);
    display.setCursor(20, 25);
    // display.println("Oi Mãe!");
    display.print("Oi M");
    display.write(0x83); // pode variar, geralmente não funciona bem no Adafruit padrão
    display.print("e!");

    display.display();

    Serial.println("Mensagem exibida no OLED.");
}

void loop()
{
}