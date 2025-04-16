# DualMotor - Controle de Dois Motores DC com Ponte H

A classe **DualMotor** oferece uma forma simples e eficiente de controlar dois motores DC simultaneamente usando uma ponte H. Ela é ideal para projetos com robôs que necessitam de movimentos coordenados, como seguir linha, desviar de obstáculos ou realizar manobras precisas.

## Requisitos

- Placa Arduino compatível
- Ponte H (L298N, L293D ou similar)
- Motor DC
- Fonte de alimentação externa (dependendo do motor)

## Instalação

1. Copie o conteúdo da classe `DualMotor` para um arquivo chamado `dualMotor.h`
2. No seu sketch principal (`.ino`), inclua o cabeçalho:

## Instanciação

```cpp
DualMotor robo(pinEsq1, pinEsq2, pinDir1, pinDir2);
```

## Métodos

| Método | Descrição |
| --- | --- |
| `on()` | Liga ambos os motores. |
| `off()` | Desliga ambos os motores. |
| `run(int moveEsq, int moveDir)` | Controla os dois motores individualmente. |
| `frente(int velocidade)` | Executa ambos os motores com a mesma velocidade para frente. |
| `reverso(int velocidade)` | Executa ambos os motores com a mesma velocidade para trás. |
| `curva(int velocidade, char direcao)` | Realiza uma curva suave: `'D'` curva para a direita, `'E'` curva para a esquerda e para direções inválidas mostram mensagem no Serial Monitor. |
| `runForTime(int moveEsq, int moveDir, int tempo)` | Executa os motores com os valores especificados por um tempo determinado (em milissegundos). |

## Autor

- **Matheus Gabriel** — [@ohthias](https://github.com/ohthias)

## Licença

Este projeto está licenciado sob a licença MIT — veja o arquivo [LICENSE](https://www.notion.so/makerbox-math/LICENSE) para detalhes.