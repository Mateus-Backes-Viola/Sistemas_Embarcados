/* ************************************************************************

Colégio SATC
Curso Técnico em Mecatrônica
Disciplina: Sistemas Embarcados
Turma: 3191
Professor: Marcos Antonio Jeremias Coelho

Programa: Pull up interno

Autor: Mateus Backes Viola
Data: 23/03/2026
Versão: 1.0

************************************************************************ */

const int pin_botao = 2;   //
bool botao = false;   //

void setup() {
  pinMode(pin_botao, INPUT_PULLUP);   //
  Serial.begin(115200);   // Definição da velocidade de transmissão para 115200 bps
}
void loop() {
  botao = digitalRead(pin_botao);        //
  if (botao == LOW) {                    //
    Serial.println("Botao pressionado"); //
  }

}
