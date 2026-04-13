const int led_1 = 9;          // Atribui o pino 9 ao led 1
const int led_2 = 10;         // Atribui o pino 10 ao led 2
const int botao_1 = 2;        // Atribui o pino 2 ao botão 1
const int botao_2 = 3;        // Atribui o pino 3 ao botão 2
int potenciometro = A0;       // Atribui o pino A0 ao potenciômetro
int valor_potenciometro = 0;  // Faz com que o valor do potencoiômetro comece zerado
bool emergenciaAtiva = false; 
unsigned long anteriorMillis = 0;
const long intervaloPisca = 0; 
int estadoLed_2 = LOW;

void setup() {
  Serial.begin(115200);            // Altera a velocidade de leitura da serial para 115200
  pinMode(led_1, OUTPUT);          // Declara o led 1 como saída
  pinMode(led_2, OUTPUT);          // Declara o led 2 como saída
  pinMode(botao_1, INPUT_PULLUP);  // Declara o botão 1 como entrada com pullup interno
  pinMode(botao_2, INPUT_PULLUP);  // Declara o botão 2 como entrada com pullup interno
  pinMode(potenciometro, INPUT);   // Declara o potenciometro uma entrada
}

void loop() {
  int valor = analogRead(potenciometro);   // Atribui a leitura do estado analógico do potenciômetro à "valor"
  Serial.print("Valor potenciômetro = ");  // Imprime "Valor potenciômetro = " na serial
  Serial.println(valor);                   // Imprime o estado analógico do potenciômetro na serial ao lado da frase acima
  valor = map(valor, 0, 1023, 0, 255);     // Iguala a intensidade do brilho do led ao valor analógico do potenciômetro, atribuindo à "valor"
  analogWrite(led_1, valor);               // Altera o brilho do led de acordo com o valor analógico do potenciômetro
  unsigned long atualMillis = millis();
  if (digitalRead(botao_1) == LOW) {
    emergenciaAtiva = true;
  }

  
  if (!emergenciaAtiva) {
    int leitura = analogRead(potenciometro);
    int velocidade = map(leitura, 0, 1023, 0, 255); 
    
    analogWrite(led_1, velocidade);
    digitalWrite(led_2, LOW); 
  } 
  else {
    
    analogWrite(led_1, 0); 
    if (atualMillis - anteriorMillis >= intervaloPisca) {
      anteriorMillis = atualMillis;
      estadoLed_2 = !estadoLed_2;
      digitalWrite(led_2, estadoLed_2);
    }
  }
  if(botao_2 == LOW){
    botao_1 = !botao_1;
    digitalWrite(led2, LOW);
  }
  else{
    botao_1 = true;
  }
}
