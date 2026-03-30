/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Atividade 2

Autor: Mateus Backes Viola
Data: 30/03/2026
Versão: 1.0

************************************************************************ */

const int pin_botaoA = 2;
const int pin_botaoB = 3;
const int pin_ledA = 8;
const int pin_ledB = 9;
const int pin_ledC = 10;
const int pin_ledD = 11;
int estado_ledA = LOW;
int estado_ledB = LOW;
int estado_ledC = LOW;
int estado_ledD = LOW;
int estado_botaoA;
int estado_botaoB;
int ultimo_estado_botaoA = HIGH;
int ultimo_estado_botaoB = HIGH;
unsigned long tempo_debounceA = 0;
unsigned long tempo_debounceB = 0;
unsigned long tempo_debounceC = 0;
unsigned long tempo_debounceD = 0;
unsigned long atraso = 50;
unsigned long tempo_anterior = 0;
const long intervalo = 300;
bool estado = 0;

void setup() {
  pinMode(pin_botaoA, INPUT_PULLUP);
  pinMode(pin_botaoB, INPUT_PULLUP);
  pinMode(pin_ledA, OUTPUT);
  pinMode(pin_ledB, OUTPUT);
  pinMode(pin_ledC, OUTPUT);
  pinMode(pin_ledD, OUTPUT);
  digitalWrite(pin_ledA, estado_ledA);
  digitalWrite(pin_ledB, estado_ledB);
  digitalWrite(pin_ledC, estado_ledC);
  digitalWrite(pin_ledD, estado_ledD);
  Serial.begin(115200);
}

void loop() {
  int leituraA = digitalRead(pin_botaoA);
  if (leituraA != ultimo_estado_botaoA) {
    tempo_debounceA = millis();
  }
  if ((millis() - tempo_debounceA) > atraso)
  {
    if (leituraA != estado_botaoA){
      estado_botaoA = leituraA;
      if (estado_botaoA == LOW) {
        estado_ledA = 1;
        estado_ledC = 1;
      }
    }
  }
  digitalWrite(pin_ledA, estado_ledA);
  digitalWrite(pin_ledC, estado_ledC);
  ultimo_estado_botaoA = leituraA;

  unsigned long tempo_atual = millis();
  if(tempo_atual - tempo_anterior >= intervalo) {
    estado = !estado;
    digitalWrite(estado_ledA, estado);
    digitalWrite(estado_ledC, estado); 
    tempo_anterior = tempo_atual;
    estado = !estado;
    digitalWrite(estado_ledB, estado);
    digitalWrite(estado_ledD, estado); 
    tempo_anterior = tempo_atual;
  }

  int leituraB = digitalRead(pin_botaoB);
  if (leituraB != ultimo_estado_botaoB) {
    tempo_debounceB = millis();
  }
  if ((millis() - tempo_debounceB) > atraso)
  {
    if (leituraB != estado_botaoB){
      estado_botaoB = leituraB;
      if (estado_botaoB == LOW) {
       estado_ledA = 0;
       estado_ledB = 0;
       estado_ledC = 0;
       estado_ledD = 0;
      }
    }
  }
  digitalWrite(pin_ledB, estado_ledB);
  digitalWrite(pin_ledD, estado_ledD);
  ultimo_estado_botaoB = leituraB;
}