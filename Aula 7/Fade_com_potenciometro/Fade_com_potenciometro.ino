int ledPin = 11;  
int pin_sensor = A0;
int valor_sensor = 0;

void setup() {
  pinMode(ledPin, OUTPUT);
  pinMode(pin_sensor, INPUT);
  Serial.begin(115200);
}

void loop() {
  int valor = analogRead(pin_sensor);
  Serial.print("Valor potenciômetro = ");
  Serial.println(valor);
  valor = map(valor, 0, 1023, 0, 255);
  analogWrite(ledPin, valor);
}
