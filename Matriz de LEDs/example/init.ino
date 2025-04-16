#include "matrizLED.h"

int pinosArray[] = {2, 3, 4, 5, 6, 7};
MatrizLED matrizLED = MatrizLED(pinosArray, 6);

void setup()
{
    Serial.begin(9600);
    Serial.println("Iniciando matriz LED...");
    matrizLED.init();
}

void loop()
{
    matrizLED.on();
}
