#include <ESP32Servo.h>
Servo servo;
Servo servo2;

// 7segment =============================
int segA = 5;
int segB = 18;
int segC = 19;
int segD = 25;
int segE = 33;
int segF = 23;
int segG = 22;
int segP = 21;
//Leds =============================
int LedG = 26;
int LedR = 4;
//Sensor =============================
int pinTrig =13;
int pinEco = 12;


//Botoes =============================
const int botaoG = 27;
const int botaoR = 2;

bool stateBtnE, previuosState1 = HIGH;
bool stateBtnS, previuosState2 = HIGH;
//Servos =============================
int servoE = 14;
int servoD = 15;


void setup() {
  Serial.begin(115200);
  // 7Segment =============================
  pinMode(segA, OUTPUT);
  pinMode(segB, OUTPUT);
  pinMode(segC, OUTPUT);
  pinMode(segD, OUTPUT);
  pinMode(segE, OUTPUT);
  pinMode(segF, OUTPUT);
  pinMode(segG, OUTPUT);
  pinMode(segP, OUTPUT);
  //Leds =============================
  pinMode(LedG, OUTPUT);
  pinMode(LedR, OUTPUT);
  //Sensor =============================
  pinMode(pinTrig, OUTPUT);
  pinMode(pinEco, INPUT);
  //Botoes =============================
  pinMode(botaoR, INPUT_PULLUP);
  pinMode(botaoG, INPUT_PULLUP);
  //Servos =============================
  servo.attach(servoE);
  servo.write(90);
  servo2.attach(servoD);
  servo.write(90);
}


void loop() {
// botoes =======================================
  stateBtnE = digitalRead(botaoG);
  stateBtnS = digitalRead(botaoR);
// Exibir valor inicial no 7segment =============
  exibir_valor();
// Gatilho ======================================
  digitalWrite(pinTrig, LOW);
  delay(2);
  digitalWrite(pinTrig, HIGH);
  delay(10);
  digitalWrite(pinTrig, LOW);

int duration = pulseIn(pinEco, HIGH);
int distancia = duration / 58;

  // Funcoes entre Sensor e leds
if (distancia > 130) {
    digitalWrite(LedG, HIGH);
    digitalWrite(LedR, LOW);
  } else {
    digitalWrite(LedG, LOW);
    digitalWrite(LedR, HIGH);
  }

// Funcoes entre Botao, servo e 7segment ========
if (stateBtnE == LOW && previuosState1 == HIGH){
  incrementar();
  exibir_valor();
  abrirentrada();
  }
if (stateBtnS == LOW && previuosState2 == HIGH){
  decrementar();
  exibir_valor();
  abrirsaida();
  }
delay(10);
}

void abrirentrada() { // Abrir Entrada
  for(int i = 90 ; i <= 180 ; i++){
    servo.write(i);

    delay(50);
  }
  delay(1500);
  
  for(int i = 180 ; i >= 90 ; i--){
  servo.write(i);
  delay(50);
  }
}

void abrirsaida() { // Abrir Saida
  for(int i = 90 ; i <= 180 ; i++){
    servo2.write(i);
    delay(50);
  }
  delay(1500);

  for(int i = 180 ; i >= 90 ; i--){
  servo2.write(i);
  delay(50);
  }
}

int valor = 0; //Variavel valor para exibir no 7segment

void incrementar(){ // Incrementacao numero do 7segment
  apagar();
  valor++;
  if (valor > 9) {
    valor = 0;
  }
}

void decrementar(){ // Decrementar numero do 7segmente
  apagar();
  valor--;
  if (valor < 0) {
    valor = 9;
  }
}

void exibir_valor(){ // Valor para Exibir no 7segment
  switch(valor){
    case 0:
      zero();
      break;
    case 1:
      um();
      break;
    case 2:
      dois();
      break;
    case 3:
      tres();
      break;
    case 4:
      quatro();
      break;
    case 5:
      cinco();
      break;
    case 6:
      seis();
      break;
    case 7:
      sete();
      break;
    case 8:
      oito();
      break;
    case 9:
      nove();
      break;
  }
}


void apagar (){ // Apagar numero do 7segment
  digitalWrite(segA, LOW);
  digitalWrite(segB, LOW);
  digitalWrite(segC, LOW);
  digitalWrite(segD, LOW);
  digitalWrite(segE, LOW);
  digitalWrite(segF, LOW);
  digitalWrite(segG, LOW);
}

// Numeros de 0 a 9 usados no 7segment
void zero (){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
}
void um (){
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
}
void dois (){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segG, HIGH);
}
void tres (){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segG, HIGH);
}
void quatro (){
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}
void cinco(){
  digitalWrite(segA, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}
void seis(){
  digitalWrite(segA, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}
void sete(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
}
void oito(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segD, HIGH);
  digitalWrite(segE, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}
void nove(){
  digitalWrite(segA, HIGH);
  digitalWrite(segB, HIGH);
  digitalWrite(segC, HIGH);
  digitalWrite(segF, HIGH);
  digitalWrite(segG, HIGH);
}

