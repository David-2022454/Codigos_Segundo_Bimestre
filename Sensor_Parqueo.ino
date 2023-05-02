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

#include <Wire.h>   
#include <LiquidCrystal_I2C.h>  
#define DW1(pin) digitalWrite(pin,HIGH)
#define DW0(pin) digitalWrite(pin,LOW)
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define ECHO 13
#define TRIG 14
long DURACION;
long DISTANCIA;

LiquidCrystal_I2C LCD_David(0x27, columnas, filas);

void ConfigPinesInput(void);
void ConfigPinesOutput(void);
int medicion(void);
int sensor_carro(void);

byte bloque[] = {
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111,
  B11111
};


void setup() {
  Serial.begin(9600);
  LCD_David.begin(16,2);
  LCD_David.init(); 
  LCD_David.backlight(); 
  ConfigPinesInput();
  ConfigPinesOutput();
  LCD_David.createChar(1,bloque);
}

void loop() {

medicion(); 
sensor_carro();
}

void ConfigPinesInput(){
pinMode(ECHO,INPUT);
}

void ConfigPinesOutput() {
pinMode(TRIG,OUTPUT); 
}


int medicion(){
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);
  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58;
Serial.println(DISTANCIA);
delay(100);
}

int sensor_carro(){
  if (DISTANCIA == 50) {
  LCD_David.init(); 
  LCD_David.backlight(); 
  LCD_David.clear();
  LCD_David.setCursor(7,0);
  LCD_David.print("50");
    LCD_David.setCursor(4,0);
  LCD_David.write(1);
    LCD_David.setCursor(5,0);
  LCD_David.write(1);
    LCD_David.setCursor(6,0);
  LCD_David.write(1);
    LCD_David.setCursor(9,0);
  LCD_David.write(1);
    LCD_David.setCursor(10,0);
  LCD_David.write(1);
    LCD_David.setCursor(11,0);
  LCD_David.write(1);
    LCD_David.setCursor(5,1);
  LCD_David.print("Libre!");
}

if (DISTANCIA == 30){
  LCD_David.init(); 
  LCD_David.backlight(); 
  LCD_David.clear();
  LCD_David.setCursor(7,0);
  LCD_David.print("30");
  LCD_David.setCursor(2,0);
  LCD_David.write(1);
  LCD_David.setCursor(3,0);
  LCD_David.write(1);
   LCD_David.setCursor(4,0);
  LCD_David.write(1);
    LCD_David.setCursor(5,0);
  LCD_David.write(1);
    LCD_David.setCursor(6,0);
  LCD_David.write(1);
    LCD_David.setCursor(9,0);
  LCD_David.write(1);
    LCD_David.setCursor(10,0);
  LCD_David.write(1);
    LCD_David.setCursor(11,0);
  LCD_David.write(1);
  LCD_David.setCursor(12,0);
  LCD_David.write(1);
  LCD_David.setCursor(13,0);
  LCD_David.write(1);
    LCD_David.setCursor(4,1);
  LCD_David.print("Cuidado!");
}

if (DISTANCIA == 10){
  LCD_David.init(); 
  LCD_David.backlight(); 
  LCD_David.clear();
  LCD_David.setCursor(7,0);
  LCD_David.print("10");
    LCD_David.setCursor(0,0);
  LCD_David.write(1);
  LCD_David.setCursor(1,0);
  LCD_David.write(1);
  LCD_David.setCursor(2,0);
  LCD_David.write(1);
  LCD_David.setCursor(3,0);
  LCD_David.write(1);
   LCD_David.setCursor(4,0);
  LCD_David.write(1);
    LCD_David.setCursor(5,0);
  LCD_David.write(1);
    LCD_David.setCursor(6,0);
  LCD_David.write(1);
    LCD_David.setCursor(9,0);
  LCD_David.write(1);
    LCD_David.setCursor(10,0);
  LCD_David.write(1);
    LCD_David.setCursor(11,0);
  LCD_David.write(1);
  LCD_David.setCursor(12,0);
  LCD_David.write(1);
  LCD_David.setCursor(13,0);
  LCD_David.write(1);
    LCD_David.setCursor(14,0);
  LCD_David.write(1);
  LCD_David.setCursor(15,0);
  LCD_David.write(1);
    LCD_David.setCursor(6,1);
  LCD_David.print("Alto");
}

}
