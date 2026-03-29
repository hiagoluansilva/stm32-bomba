# stm32-bomba

Versão simplificada do jogo de "bomba" com displays de 7 segmentos multiplexados e chaves no STM32F4xx.

## Descrição

Projeto lúdico onde o jogador deve acionar as chaves corretas para desarmar uma bomba antes que o contador chegue a zero. Versão inicial com lógica de embaralhamento das chaves e contador regressivo em displays 7 segmentos.

## Hardware

- Microcontrolador: STM32F4xx
- 2× Display 7 segmentos (multiplexados)
- 8× Chaves (PC0–PC7)
- Buzzer: PC8
- LED verde: PC9
- LED amarelo: PC10

## Timers utilizados

| Timer | Função |
|-------|--------|
| TIM3 | Loop principal / contagem |
| TIM9 | Contagem regressiva |
| TIM10 | Multiplexação display dígito 1 |
| TIM11 | Multiplexação display dígito 2 |

## Lógica principal

```
1. Embaralha combinação secreta (suffle)
2. Exibe contagem: 59 → 00
3. Usuário ativa chaves
4. Verifica sequência → desarme ou explosão
```

## IDE

Atollic TrueSTUDIO 9.3

## Escola

Centro Tecnológico Liberato — Novo Hamburgo/RS
