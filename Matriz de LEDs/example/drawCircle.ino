#include "matrizLED.h"

int pinosArray[] = {2, 3, 4, 5, 6, 7, 8, 9, 10};
MatrizLED matrizLED = MatrizLED(pinosArray, 9);

void setup()
{
    Serial.begin(9600);
    Serial.println("Iniciando matriz LED...");
    matrizLED.init();
}

void loop()
{
    int desenho[] = {0, 1, 2, 3, 4, 6, 7, 8, 9};
    matrizLED.drawMatriz(desenho, 8);
}