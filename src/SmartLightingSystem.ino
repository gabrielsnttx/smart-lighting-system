#include <LiquidCrystal.h>

LiquidCrystal lcd(12, 11, 5, 4, 3, 2);

const int trigA = 6, echoA = 7;
const int trigB = 8, echoB = 9;
const int pinoLED = 13;

int contagem = 0;
const int limiar = 50;
long ultimaDistA = 336, ultimaDistB = 336;
unsigned long tempoA = 0, tempoB = 0;
const unsigned long delayMinimo = 3000;

long lerDistancia(int trig, int echo) {
  digitalWrite(trig, LOW); delayMicroseconds(2);
  digitalWrite(trig, HIGH); delayMicroseconds(10);
  digitalWrite(trig, LOW);
  return pulseIn(echo, HIGH) / 58;
}

void atualizaLCD() {
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Pessoas na sala:");
  lcd.setCursor(0, 1);
  if (contagem == 0) {
    lcd.print("Sala vazia!");
  } else {
    lcd.print(contagem);
    lcd.print(" pessoa(s)");
  }
}

void setup() {
  pinMode(trigA, OUTPUT); pinMode(echoA, INPUT);
  pinMode(trigB, OUTPUT); pinMode(echoB, INPUT);
  pinMode(pinoLED, OUTPUT);
  lcd.begin(16, 2);
  Serial.begin(9600);
  Serial.println("Sistema pronto!");
  atualizaLCD();
}

void loop() {
  long distA = lerDistancia(trigA, echoA);
  long distB = lerDistancia(trigB, echoB);

  if (distA < limiar && ultimaDistA >= limiar) {
    if (millis() - tempoB > delayMinimo) {
      contagem++;
      tempoA = millis();
      Serial.println("Entrou! Total: " + String(contagem));
      atualizaLCD();
    } else {
      Serial.println("A ignorado (veio do B)");
    }
  }

  if (distB < limiar && ultimaDistB >= limiar) {
    if (millis() - tempoA > delayMinimo) {
      if (contagem > 0) contagem--;
      tempoB = millis();
      Serial.println("Saiu! Total: " + String(contagem));
      atualizaLCD();
    } else {
      Serial.println("B ignorado (veio do A)");
    }
  }

  ultimaDistA = distA;
  ultimaDistB = distB;

  digitalWrite(pinoLED, contagem > 0 ? HIGH : LOW);
  delay(50);
}
