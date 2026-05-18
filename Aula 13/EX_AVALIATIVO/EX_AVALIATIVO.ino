const int led_amarelo = 9;
const int led_vermelho = 11;
const int botaoA = 2;
int distancia;
const int led_entrada = 10;
const int led_saida = 12;
const int led_temperatura = 6;
const int potenciometro = A0;

void setup() {
 pinMode(led_amarelo, OUTPUT);
 pinMode(led_vermelho, OUTPUT);
 pinMode(led_entrada, OUTPUT);
 pinMode(led_saida, OUTPUT);
 pinMode(botaoA, INPUT_PULLUP);
 pinMode(potenciometro, INPUT);
 Serial.begin(9600);
}

void loop() {
  int leitura = analogRead(potenciometro);
  float temperatura = map(leitura, 0, 1023, 0, 50);

  if(25 < temperatura < 27){
    digitalWrite(led_saida, 1);
  }
  else{
    digitalWrite(led_temperatura,1);
    digitalWrite(led_saida, 0);
  }
}

