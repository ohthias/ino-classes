# Motor

Classe em C++ para controle de motores DC utilizando uma ponte H (como a L298N ou L293D). Essa classe facilita o controle de direção e velocidade dos motores de forma simples e intuitiva.

## Requisitos

- Placa Arduino compatível
- Ponte H (L298N, L293D ou similar)
- Motor DC
- Fonte de alimentação externa (dependendo do motor)

## Instalação

1. Copie o conteúdo da classe `Motor` para um arquivo chamado `motor.h`
2. No seu sketch principal (`.ino`), inclua o cabeçalho:

```cpp
#include "motor.h"
```

## Como usar

1. Instanciar a classe

```cpp
Motor motor1(8, 9); // Pinos conectados ao IN1 e IN2 da ponte H
```

2. Ligar o motor no sentido horário

```cpp
motor1.on();
```

3. Desligar o motor

```cpp
motor1.off();
```

4. Controlar a direção e velocidade

```cpp
motor1.run(100);   // Horário com velocidade 100 (0-255)
motor1.run(-80);   // Anti-horário com velocidade 80
motor1.run(0);     // Para o motor
```

## Métodos

| Método | Descrição |
|--------|-----------|
| `on()` | Liga o motor no sentido horário |
| `off()` | Desliga o motor |
| `run(int velocity)` | Controla a velocidade e sentido do motor |

## Observações

- O valor de `velocity` deve estar entre `-255` e `255`
- Velocidade negativa gira o motor no sentido anti-horário
- Velocidade positiva gira no sentido horário
- O uso de `analogWrite` permite controle de velocidade via PWM

## Autor

- **Matheus Gabriel** — [@ohthias](https://github.com/ohthias)

## Licença

Este projeto está licenciado sob a licença MIT — veja o arquivo [LICENSE](LICENSE) para detalhes.

