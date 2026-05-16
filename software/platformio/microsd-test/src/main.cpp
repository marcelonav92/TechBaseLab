#include <Arduino.h>
#include <SPI.h>
#include <SD.h>

// Sua pinagem atual
#define SD_MISO 5
#define SD_CLK  18
#define SD_MOSI 19
#define SD_CS   23

SPIClass spiSD(VSPI);

void escreverArquivo()
{
    Serial.println("Criando arquivo...");

    File file = SD.open("/teste.txt", FILE_WRITE);

    if (!file)
    {
        Serial.println("Erro ao abrir arquivo para escrita.");
        return;
    }

    file.println("HardwareLab");
    file.println("Teste de gravacao no MicroSD.");
    file.println("ESP32 funcionando.");

    file.close();

    Serial.println("Arquivo gravado com sucesso.");
}

void lerArquivo()
{
    Serial.println();
    Serial.println("Lendo arquivo...");

    File file = SD.open("/teste.txt");

    if (!file)
    {
        Serial.println("Erro ao abrir arquivo.");
        return;
    }

    while (file.available())
    {
        Serial.write(file.read());
    }

    file.close();

    Serial.println();
    Serial.println("Leitura finalizada.");
}

void setup()
{
    Serial.begin(115200);

    delay(2000);

    Serial.println();
    Serial.println("=== HardwareLab - MicroSD Test ===");

    spiSD.begin(SD_CLK, SD_MISO, SD_MOSI, SD_CS);

    if (!SD.begin(SD_CS, spiSD))
    {
        Serial.println("Falha ao inicializar MicroSD.");
        return;
    }

    Serial.println("MicroSD inicializado com sucesso.");

    escreverArquivo();

    delay(1000);

    lerArquivo();
}

void loop()
{
}