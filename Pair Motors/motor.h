/**
 * @file motor.h
 * @brief Classe para controlar um motor DC com ponte H
 * @author Matheus Gabriel (@ohthias)
 * @version 2.0
 * @date 16/04/2025
 */

class Motor
{
private:
    byte motorPinIn1; // Pino para controle de direção horária
    byte motorPinIn2; // Pino para controle de direção anti-horária

public:
    /**
     * @brief Construtor da classe do motor
     * @param motorPinIn1: pino para controle de direção horária
     * @param motorPinIn2: pino para controle de direção anti-horária
     *
     * @example
     *   motor motorName(
     *     8,      // motorPinIn1
     *     9       // motorPinIn2
     *   );
     */
    Motor(byte motorPinIn1, byte motorPinIn2)
    {
        this->motorPinIn1 = motorPinIn1;
        this->motorPinIn2 = motorPinIn2;

        init();
    }

    /**
     * @brief Inicialização da classe
     */
    void init()
    {
        pinMode(motorPinIn1, OUTPUT);
        pinMode(motorPinIn2, OUTPUT);

        off();
    }

    /**
     * @brief Inicialização dos motores no sentido horário
     */
    void on()
    {
        digitalWrite(motorPinIn1, 1);
        digitalWrite(motorPinIn2, 0);
    }

    /**
     * @brief Paralização dos motores
     */
    void off()
    {
        digitalWrite(motorPinIn1, 0);
        digitalWrite(motorPinIn2, 0);
    }

    /**
     * @brief Método para girar os motores no sentido desejado
     * @param velocity: velocidade desejada
     *
     * @example:
     *    motorExample.run(80);
     *    motorExample.run(-80);
     *
     * Se a velocidade for negativa, o motor irá girar no sentido anti-horário,
     * caso contrário, sentido horário
     */
    void run(int velocity)
    {
        if (velocity < 0)
        {
            analogWrite(motorPinIn1, 0);
            analogWrite(motorPinIn2, abs(velocity)); // Garante que o valor seja positivo
        }
        else
        {
            analogWrite(motorPinIn1, velocity);
            analogWrite(motorPinIn2, 0);
        }
    }
};