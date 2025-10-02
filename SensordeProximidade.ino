// ===== INCLUSÃO DE BIBLIOTECAS NECESSÁRIAS =====
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// ===== DEFINIÇÃO DOS PINOS =====

// Sensor HC-SR04
const int pinoTrig = 6; // Pino para enviar o pulso (Trigger)
const int pinoEcho = 7; // Pino para receber o pulso (Echo)

// LEDs
const int ledVerde = 8;  	// Distância Segura
const int ledAmarelo = 9; 	// Distância de Atenção
const int ledVermelho = 10; // Distância de Perigo

// Buzzer
const int pinoBuzzer = 11; // Para o alarme sonoro

LiquidCrystal_I2C lcd(32, 16, 2); 

// ===== CONGIFURAÇÃO =====

void setup() {
  // Pinos do Sensor
  pinMode(pinoTrig, OUTPUT);
  pinMode(pinoEcho, INPUT);

  // Pinos dos LEDs e Buzzer como Saída
  pinMode(ledVerde, OUTPUT);
  pinMode(ledAmarelo, OUTPUT);
  pinMode(ledVermelho, OUTPUT);
  pinMode(pinoBuzzer, OUTPUT);
  
  // Configuração de Inicialização do LCD
  lcd.init();
  lcd.backlight();
  
  // Mensagem de Inicialização
  lcd.setCursor(0,0);
  lcd.print("SENSOR DE");
  lcd.setCursor(0,1);
  lcd.print("PROXIMIDADE");
  delay(2000);
  lcd.clear();
  
  lcd.setCursor(0,0);
  lcd.print("STATUS: PRONTO");
  delay(1500);
  lcd.clear(); // Limpa a tela após a mensagem inicial
}

// ===== FUNÇÃO PRINCIPAL =====

void loop() {
  // 1. Calcula a distância
  long duracao, distanciaCm;
  
  // Limpa o pino Trig (garante que está LOW por um breve momento)
  digitalWrite(pinoTrig, LOW);
  delayMicroseconds(2);

  // Envia um pulso de 10us para o pino Trig
  digitalWrite(pinoTrig, HIGH);
  delayMicroseconds(10);
  digitalWrite(pinoTrig, LOW);

  // Mede a duração do pulso no pino Echo
  duracao = pulseIn(pinoEcho, HIGH);

  // Calcula a distância em cm
  distanciaCm = duracao / 58;

  // ATUALIZAÇÃO DO DISPLAY DO LCD
  // A distância é exibida ANTES de qualquer delay de piscar.
  lcd.setCursor(0, 0);
  lcd.print("Dist: ");
  lcd.print(distanciaCm);
  lcd.print(" cm  "); // Espaços para limpar dígitos anteriores

  // 2. Controla LEDs, Buzzer e LCD (Linha 1) com base na Distância
  
  // Variável para a mensagem de status
  String statusMsg = "";
  
  // Condição 1: PERIGO (Distância < 20 cm)
  if (distanciaCm < 20) {
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, HIGH); 
    
    // Buzzer Rápido
    tone(pinoBuzzer, 1500); 
    delay(100);
    noTone(pinoBuzzer);
    delay(100);
    
    // Mensagem LCD
    statusMsg = "CUIDADO!";
    
  // Condição 2: ATENÇÃO (20 cm <= Distância < 40 cm)
  } else if (distanciaCm < 40) { 
    digitalWrite(ledVerde, LOW);
    digitalWrite(ledVermelho, LOW);
    
    // LED Amarelo Pisca
    digitalWrite(ledAmarelo, HIGH);
    delay(300);
    digitalWrite(ledAmarelo, LOW);
    delay(300); // Esse delay afeta na leitura da distância 
    noTone(pinoBuzzer);
    
    // Mensagem LCD
    statusMsg = "ATENCAO";

  // Condição 3: SEGURO (Distância >= 40 cm)
  } else { 
    digitalWrite(ledVerde, HIGH);
    digitalWrite(ledAmarelo, LOW);
    digitalWrite(ledVermelho, LOW);
    
    noTone(pinoBuzzer);
    
    // Mensagem LCD
    statusMsg = "SEGURO";
  }

  // ATUALIZAÇÃO FINAL DO LCD
  // Exibe o status após definir a mensagem dentro do bloco if/else
  lcd.setCursor(0, 1);
  lcd.print("Status: ");
  lcd.print(statusMsg);
  lcd.print("     "); // Espaços para limpar o restante da linha

}