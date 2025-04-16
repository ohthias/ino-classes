/**
 * @file pairMotors.h
 * @brief Classe para controlar dois motores DC com ponte H
 * @author Matheus Gabriel (@ohthias)
 * @version 1.1
 * @date 16/04/2025
 */

#include "motor.h"

class DualMotor
{
private:
  Motor motorEsquerdo;
  Motor motorDireito;

public:
  /**
   * @brief Construtor da classe DualMotor
   * @param motorEsqPin1: pino 1 do motor esquerdo
   * @param motorEsqPin2: pino 2 do motor esquerdo
   * @param motorDirPin1: pino 1 do motor direito
   * @param motorDirPin2: pino 2 do motor direito
   */
  DualMotor(byte motorEsqPin1, byte motorEsqPin2, byte motorDirPin1, byte motorDirPin2)
      : motorEsquerdo(motorEsqPin1, motorEsqPin2), motorDireito(motorDirPin1, motorDirPin2) {}

  void on()
  {
    motorEsquerdo.on();
    motorDireito.on();
  }

  void off()
  {
    motorEsquerdo.off();
    motorDireito.off();
  }

  /**
   * @brief Executa os motores com os valores especificados
   * @param moveEsq: valor para o motor esquerdo
   * @param moveDir: valor para o motor direito
   *
   * Esta função permite controlar os dois motores simultaneamente.
   * Os valores podem ser positivos (para frente) ou negativos (para trás).
   * Valores iguais para ambos os motores resultam em movimento reto.
   * Valores diferentes resultam em curvas.
   */
  void run(int moveEsq, int moveDir)
  {
    motorEsquerdo.run(moveEsq);
    motorDireito.run(moveDir);
  }

  /**
   * @brief Executa os motores com a mesma velocidade
   * @param velocidade: valor de velocidade para ambos os motores
   *
   * Esta função é uma sobrecarga da função run() e permite controlar os dois motores
   * com a mesma velocidade, facilitando o movimento reto.
   */
  void frente(int velocidade)
  {
    motorEsquerdo.run(velocidade);
    motorDireito.run(velocidade);
  }

  /**
   * @brief Executa os motores com a mesma velocidade, mas em sentido reverso
   * @param velocidade: valor de velocidade para ambos os motores
   *
   * Esta função é uma sobrecarga da função run() e permite controlar os dois motores
   * com a mesma velocidade, facilitando o movimento reto em sentido reverso.
   */
  void reverso(int velocidade)
  {
    motorEsquerdo.run(-velocidade);
    motorDireito.run(-velocidade);
  }

  /**
   * @brief Executa curva com base na direção especificada
   * @param velocidade: valor de velocidade para os motores
   * @param direcao: direção da curva ('D' para direita, 'E' para esquerda)
   * 
   * Esta função permite realizar curvas suaves ajustando a velocidade de cada motor.
   * A velocidade do motor interno (motor que está mais próximo do centro da curva)
   * é reduzida para criar uma curva suave.
   */
  void curva(int velocidade, char direcao)
  {
    switch (direcao)
    {
    case 'D':
      motorEsquerdo.run(velocidade / 2); // Reduzindo a velocidade para curva suave
      motorDireito.run(velocidade);

      break;

    case 'E':
      motorEsquerdo.run(velocidade);
      motorDireito.run(velocidade / 2); // Reduzindo a velocidade para curva suave
      break;

    default:
      Serial.println("Direção inválida. Use 'D' para direita ou 'E' para esquerda.");
      break;
    }
  }

  /**
   * @brief Executa os motores por um tempo específico
   * @param moveEsq: valor para o motor esquerdo
   * @param moveDir: valor para o motor direito
   * @param tempo: tempo em milissegundos para executar os motores
   *
   * Esta função permite controlar os dois motores por um tempo específico.
   * Após o tempo especificado, os motores são desligados.
   */
  void runForTime(int moveEsq, int moveDir, int tempo)
  {
    motorEsquerdo.run(moveEsq);
    motorDireito.run(moveDir);
    delay(tempo);
  }
};