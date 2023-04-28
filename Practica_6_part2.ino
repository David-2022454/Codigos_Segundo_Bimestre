/*
  Fundación Kinal
  Centro Educativo Técnico Labral Kinal
  Electrónica
  Grado: Quinto
  Sección: A
  Curso: Taller de Electrónica Digital y Reparación de Computadoras I
  Nombre: Juan David Tejada Peñuela
  Carné: 2022454
*/

#include <LiquidCrystal.h>

#define RS  2
#define Enable 3
#define D4 4
#define D5 5
#define D6 6
#define D7 7
#define BUZZER 9
#define ECHO  11
#define TRIG 10
long DURACION;
long DISTANCIA;
int i = 0;

LiquidCrystal LCD_David(RS, Enable, D4, D5, D6, D7);

void ConfigPinesInput(void);
void ConfigPinesOutput(void);
void medicion(void);
int contador(void);
int maximo(void);
int conteo_personas(void);

byte Animacion_1[] = {
  B01110,
  B01010,
  B01110,
  B10100,
  B01110,
  B00101,
  B01010,
  B01010
};
byte Animacion_2[] = {
  B01110,
  B01010,
  B01110,
  B00101,
  B01110,
  B10100,
  B01010,
  B10001
};


void setup() {
  Serial.begin(9600);
  LCD_David.begin(16,2);
  ConfigPinesInput();
  ConfigPinesOutput();
  LCD_David.createChar(1,Animacion_1);
  LCD_David.createChar(2,Animacion_2);

}

void loop() {
medicion();
contador();
conteo_personas();
maximo();

}
void ConfigPinesInput() {
pinMode(ECHO,INPUT);
}
void ConfigPinesOutput() {
pinMode(TRIG,OUTPUT);
pinMode(BUZZER,OUTPUT);

}

void medicion() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58;
Serial.println(DISTANCIA);
delay(100);
}

int contador(){
  if (DISTANCIA >= 6 && DISTANCIA <= 10) {
    if(i < 16){
    i = i + 1;
    }
    delay(250);
    Serial.println(i);
  }
  return i;  
}
int maximo(){
  if (i >= 16) {
  LCD_David.setCursor(6,1);
  LCD_David.print("MAX");
  LCD_David.setCursor(9,1);  
  LCD_David.write(1);
  delay(500);
  LCD_David.setCursor(9,1);
  LCD_David.write(2);  
  delay(500);
  tone(BUZZER, 600);
  delay(350);
  noTone(BUZZER);
  LCD_David.setCursor(6,1);
  LCD_David.print("MAX");
  }
}

int conteo_personas(){
LCD_David.clear();
LCD_David.setCursor(0,0);
LCD_David.print("PERSONAS:");
LCD_David.setCursor(10,0);
LCD_David.print(i);
}
