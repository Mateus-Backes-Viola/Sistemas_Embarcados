#include <Ultrasonic.h>
int led1 = 9;
int led2 = 10;
int led3 = 11;
int semBarreira = 4;
Ultrasonic ultrasonic(13, 7);
int distancia;
const int botaoA = 2;

void setup() {
  Serial.begin(9600);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
  pinMode(botaoA, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(botaoA), desliga, CHANGE);
}

void loop() {

  distancia = ultrasonic.read();
  int pwmled2 = map(distancia, 0, 100, 0, 255);
  Serial.print("Distancia em CM: ");
  Serial.println(distancia);
  int leitura = digitalRead(semBarreira);

  if (distancia < 20 && leitura == 0) {
    digitalWrite(led1, 1);
  } else {
    digitalWrite(led1, 0);
  }

  analogWrite(led2, pwmled2);

  if (leitura == 0) {
    digitalWrite(led3, 1);
  }
}

void desliga() {
  digitalWrite(led3, 0);
}

 