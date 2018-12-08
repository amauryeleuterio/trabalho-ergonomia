#include <SoftwareSerial.h>

SoftwareSerial comando( A0 , -1 ); //cria nova porta uart no pino A0
void setup() {
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  comando.begin (9600); //recebe informacoes da rasp
  Serial.begin(9600); //recebe e envia informacoes dos pinos 0 e 1 (onde esta conectado o bluetooth)
}

void loop() {
    if(comando.available()>0){
    char c =  comando.read(); // c recebe informacoes da rasp
    if (c == 'h'){  //se receber h envia help para o android via bluetooth
      Serial.write("help");
      c == " ";
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
    }
    if (c == 'o'){  //se receber o envia desativa o alarme
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
  }

 }
 if(Serial.available()>0){
    char d =  Serial.read(); // d recebe informacoes do android
    if (d == 'h'){  //se receber h liga o alarme via bluetooth
      digitalWrite(13, HIGH);
      digitalWrite(12, HIGH);
    }
    if (d == 'o'){  //se receber o envia desativa o alarme via bluetooth
      digitalWrite(13, LOW);
      digitalWrite(12, LOW);
  }

 }
}
