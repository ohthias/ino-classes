#include "motor.h"

Motor motor = Motor(8, 9);

void setup() {}

void loop()
{
    // Aceleração
    for (int vel = 0; vel <= 255; vel += 5)
    {
        motor.run(vel);
        delay(50);
    }

    // Desaceleração
    for (int vel = 255; vel >= 0; vel -= 5)
    {
        motor.run(vel);
        delay(50);
    }

    delay(500); // Pausa
}