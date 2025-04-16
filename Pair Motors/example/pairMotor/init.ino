#include "dualMotor.h"

DualMotor motors(9, 10, 11, 12); // pinos dos motores esquerdo e direito
int velocidade = 100;

void setup() {}

void loop()
{
    // Teste de movimento para frente
    motors.frente(velocidade); // Move para frente com velocidade máxima
    delay(2000);               // Aguarda 2 segundos

    // Teste de movimento para trás
    motors.reverso(velocidade); // Move para trás com velocidade máxima
    delay(2000);                // Aguarda 2 segundos

    motors.curva(velocidade, 'D'); // Curva para a direita
    delay(2000);                   // Aguarda 2 segundos

    motors.curva(velocidade, 'E'); // Curva para a esquerda
    delay(2000);                   // Aguarda 2 segundos

    motors.off(); // Desliga os motores após o teste
}