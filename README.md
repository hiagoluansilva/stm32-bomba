# STM32 Bomba — Temporizador em Display 7 Segmentos

🇧🇷 **Português** | 🇺🇸 [English](#english)

---

## Português

Temporizador de contagem regressiva em STM32F4xx exibido em dois dígitos de display 7 segmentos multiplexados via TIM9, com lógica de desarme.

### O que faz
- Exibe contagem regressiva em **2 dígitos de 7 segmentos**
- Função `conversor()` mapeia `tempo[0]` e `tempo[1]` para padrões de segmentos
- Função `multiplexa()` verifica TIM9 e alterna entre **PB7** (dígito 1) e **PB8** (dígito 2)
- Array `chave[]` com lógica de adjacência determina sequência de desarme
- LED de desarme acende quando sequência correta é completada

### Funções principais
```c
void conversor();    // tempo[] → padrão 7 segmentos
void multiplexa();   // TIM9 polling → PB7/PB8 digit select
```

### Mapa de pinos
| Pino | Função |
|---|---|
| PB7 | Seleção dígito 1 |
| PB8 | Seleção dígito 2 |
| PC0–PC6 | Segmentos A–G |

### Microcontrolador
STM32F4xx — Atollic TrueSTUDIO

---

## English

Countdown timer on STM32F4xx displayed on two multiplexed 7-segment digits via TIM9, with defuse logic.

### What it does
- Displays countdown on **2 × 7-segment digits**
- `conversor()` maps `tempo[0]` and `tempo[1]` to segment patterns
- `multiplexa()` polls TIM9 and alternates between **PB7** (digit 1) and **PB8** (digit 2)
- `chave[]` array with adjacency logic determines the defuse sequence
- Defuse LED lights up when correct sequence is completed

### Main functions
```c
void conversor();    // tempo[] → 7-segment pattern
void multiplexa();   // TIM9 polling → PB7/PB8 digit select
```

### Pin map
| Pin | Function |
|---|---|
| PB7 | Digit 1 select |
| PB8 | Digit 2 select |
| PC0–PC6 | Segments A–G |

### MCU
STM32F4xx — Atollic TrueSTUDIO
