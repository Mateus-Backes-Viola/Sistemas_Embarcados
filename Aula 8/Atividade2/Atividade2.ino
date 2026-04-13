const int led1 = 9;             // Atribui o pino 9 ao led1
const int led4 = 12;            // Atribui o pino 12 ao led4
const int potenciometro1 = A0;  // Atribui o pino A0 ao potenciômetro 1
const int potenciometro2 = A1;  // Atribui o pino A1 ao potenciômetro 2
const int botao1 = 2;           // Atribui o pino 2 ao botão 1

void setup() {
  pinMode(led1, OUTPUT);          // Declara o led1 como saída
  pinMode(led4, OUTPUT);          // Declara o led4 como saída
  pinMode(botao1, INPUT_PULLUP);  // Declara o botão um como entrada e com pullup interno
}

void loop() {
}
