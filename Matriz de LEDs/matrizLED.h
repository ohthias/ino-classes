/**
 * @file matrizLED.h
 * @brief Classe para controlar uma matriz de LEDs
 * @author Matheus Gabriel (@ohthias)
 * @version 1.1
 * @date 16/04/2025
 */

class MatrizLED
{
private:
  int *arrayLED;
  int tamanho;

public:
  MatrizLED(int arrayPinos[], int tamanhoArray)
  {
    tamanho = tamanhoArray;
    arrayLED = new int[tamanho];

    for (int i = 0; i < tamanho; i++)
    {
      arrayLED[i] = arrayPinos[i];
      pinMode(arrayPinos[i], OUTPUT);
    }

    init();
  }

  void init()
  {
    on();
    delay(500);
    off();
  }

  // Função para acender LEDs
  void on()
  {
    for (int i = 0; i < tamanho; i++)
    {
      digitalWrite(arrayLED[i], HIGH);
    }
  }

  void off()
  {
    for (int i = 0; i < tamanho; i++)
    {
      digitalWrite(arrayLED[i], LOW);
    }
  }

  /** @brief drawMatriz - Função para acender LEDs em posições específicas
   *  @param posicoes - Array com as posições dos LEDs a serem acesos
   *  @param tamanhoPosicoes - Tamanho do array de posições
   * 
   *  @example
   *  int posicoes[] = {0, 1, 2};
   *  matrizLED.drawMatriz(posicoes, 3);
   **/
  void drawMatriz(int posicoes[], int tamanhoPosicoes)
  {
    for (int i = 0; i < tamanhoPosicoes; i++)
    {
      digitalWrite(arrayLED[posicoes[i]], HIGH);
    }
  }

  // Destrutor para liberar memória
  ~MatrizLED()
  {
    delete[] arrayLED;
  }
};