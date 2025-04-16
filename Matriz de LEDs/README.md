# MatrizLED

Classe em C++ para controle de uma matriz de LEDs no Arduino. Ideal para projetos didáticos e interativos com LEDs, essa classe permite ligar e desligar todos os LEDs, bem como acender posições específicas com facilidade.

## Requisitos

- Placa Arduino compatível
- Biblioteca padrão do Arduino (Arduino.h)
- LEDs conectados em pinos digitais
- Resistor para cada LED (recomendado)

## Instalação

1. Copie o conteúdo da classe MatrizLED para um arquivo chamado matrizLED.h
2. No seu sketch principal (.ino), inclua o cabeçalho:

```
#include "matrizLED.h"
```

### Gerenciamento de Memória
A classe aloca dinamicamente um array com os pinos dos LEDs e libera essa memória no destrutor (~MatrizLED()), evitando vazamentos de memória.

## Como usar
1. Instanciar a classe
   
```
int pinos[] = {2, 3, 4, 5, 6}; // Pinos conectados aos LEDs
MatrizLED matriz(pinos, 5);
```

2. Ligar todos os LEDs

```
matriz.on();
```

3. Desligar todos os LEDs

```
matriz.off();
```

4. Acender posições específicas

```
int posicoes[] = {0, 2, 4};
matriz.drawMatriz(posicoes, 3);
```

### Observações

- A numeração dos LEDs começa em 0, ou seja, o primeiro LED corresponde à posição 0.
- A função init() acende todos os LEDs por 500ms ao iniciar a instância da matriz como teste de funcionamento.

## Autor

- **Matheus Gabriel** — [@ohthias](https://github.com/ohthias)

## Licença

Este projeto está licenciado sob a licença MIT — veja o arquivo [LICENSE](LICENSE) para detalhes.