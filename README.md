# 🚦 Detector de Proximidade e Alarme Ultrassônico

Este projeto simula um sistema de alerta de proximidade utilizando um sensor ultrassônico **HC-SR04** para medir a distância. O feedback é dado por um sistema de zonas de alerta (LEDs), um alarme sonoro (Buzzer) e um display **LCD I2C** que informa a distância em tempo real e o status da zona.

É ideal para simular um sensor de estacionamento reverso.

---

## ✨ Funcionalidades

- **Medição de Distância:** Calcula a distância em centímetros usando o HC-SR04.
- **Sistema de Alerta por Zonas:** Aciona LEDs e um alarme sonoro dependendo da proximidade.
- **Visualização LCD:** Exibe a distância exata e a mensagem de status (`SEGURO`, `ATENCAO`, `CUIDADO!`).
- **Lógica Otimizada:** As zonas de alerta foram corrigidas para evitar lacunas na detecção.

---

## 📋 Zonas de Alerta

O sistema opera com três zonas de distância bem definidas:

| Zona | Distância | LED | Alarme | LCD Status |
| :--- | :--- | :--- | :--- | :--- |
| **SEGURA** | $\ge 40\text{ cm}$ | Verde 🟢 | Desligado | `SEGURO` |
| **ATENÇÃO** | $\ge 20\text{ cm}$ e $< 40\text{ cm}$ | Amarelo 🟡 (Piscando) | Desligado | `ATENCAO` |
| **PERIGO** | $< 20\text{ cm}$ | Vermelho 🔴 (Fixo) | Buzzer Rápido | `CUIDADO!` |

---

## 🛠️ Tecnologias e Componentes

| Categoria | Item | Detalhe |
| :--- | :--- | :--- |
| **Plataforma** | Arduino Uno | Microcontrolador principal |
| **Sensor** | HC-SR04 | Medição de distância ultrassônica |
| **Display** | LCD 16x2 I2C | Saída de dados |
| **Alerta** | LEDs (3x) | Indicador visual |
| **Alerta** | Buzzer | Alarme sonoro |
| **Componentes** | Resistores $220\Omega$ (3x) | Para limitação de corrente dos LEDs |
| **Linguagem** | C/C++ | Código de programação |

---
## 📚 Como Usar
1. Instale a biblioteca LiquidCrystal I2C no Gerenciador de Bibliotecas.
2. Confirme se o endereço do LCD no código está correto para o seu módulo.
3. Gire o potenciômetro no módulo LCD I2C até o texto aparecer.
4. Conecte o Arduino e carregue o código no IDE.
5. Mova objetos na frente do sensor para observar as mudanças nos LEDs e a atualização da distância no LCD.

> Para simulação online: https://www.tinkercad.com/things/anZ6BU8i3uq-sensor-de-proximidade-com-alarme-e-lcd

---

## 🔌 Circuito
<img width="1025" height="503" alt="Sensor de Alarme" src="https://github.com/user-attachments/assets/ef24b3d0-74bd-49d2-985c-f31e40b77888" />

---

## 💻Código
Verificar o arquivo: [SensordeProximidade.ino](SensordeProximidade.ino)

---

## 🤝Contribuições

Contribuições são bem-vindas!  

---

## 📜Licença

MIT License © João Krupa
