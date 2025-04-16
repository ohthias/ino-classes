#include "motor.h"

Motor motor = Motor(8, 9);

void setup() {}

void loop()
{
    // Teste de movimento para frente
    motor.run(255); // Move para frente com velocidade máxima
    delay(2000);    // Aguarda 2 segundos

    // Teste de movimento para trás
    motor.run(-255); // Move para trás com velocidade máxima
    delay(2000);     // Aguarda 2 segundos

    motor.off(); // Desliga o motor após o teste
}