int pin_sensor = A0;
int valor_sensor = 0;
const int led_9 = 9;
const int led_10 = 10;
const int led_11 = 11;

void setup() {
  pinMode(pin_sensor, INPUT);
  Serial.begin(115200);
  pinMode(led_9, OUTPUT);
  pinMode(led_10, OUTPUT);
  pinMode(led_11, OUTPUT);
}

void loop() {
  valor_sensor = analogRead(pin_sensor);
  float valor_tensao = (valor_sensor * 5.0)/1023;
  Serial.print("Valor tensão = ");
  Serial.println(valor_tensao);
  if(valor_tensao < 1){
    digitalWrite(led_9, LOW);
    digitalWrite(led_10, LOW);
    digitalWrite(led_11, LOW);
  }
  else if(valor_tensao <= 2){
    digitalWrite(led_9, HIGH);
    digitalWrite(led_10, LOW);
    digitalWrite(led_11, LOW);
  }
  else if(valor_tensao <= 3){
    digitalWrite(led_9, LOW);
    digitalWrite(led_10, HIGH);
    digitalWrite(led_11, LOW);
  }
  else if(valor_tensao <= 4){
    digitalWrite(led_9, LOW);
    digitalWrite(led_10, LOW);
    digitalWrite(led_11, HIGH);
  }
  else{
    digitalWrite(led_9, HIGH);
    digitalWrite(led_10, HIGH);
    digitalWrite(led_11, HIGH);
  }
}