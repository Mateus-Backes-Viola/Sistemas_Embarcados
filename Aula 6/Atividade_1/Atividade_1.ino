/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Atividade 1

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
unsigned long atraso = 50;

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
}

void loop() {
  
}
