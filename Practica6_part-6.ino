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

//Librerias
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>   
#include <LiquidCrystal_I2C.h>  
#define DW1(pin) digitalWrite(pin,HIGH)
#define DW0(pin) digitalWrite(pin,LOW)
#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define LED_AZUL 3 
#define LED_AMAR 5
#define LED_ROJO 7
LiquidCrystal_I2C LCD_David(0x27, columnas, filas);
OneWire ourWire(2);               
DallasTemperature sensors(&ourWire); 

float celsius, farent;
float func_celsius();
float func_farent();
float segunda_fila(float);
void primera_fila(void);
void ConfigPinesOutput(void);
float valor_temp(float);


byte term[] = {
  0x1F,
  0x11,
  0x1F,
  0x0A,
  0x0A,
  0x0E,
  0x04,
  0x00
};

byte grados[] = {
  B00111,
  B00101,
  B00111,
  B00000,
  B00000,
  B00000,
  B00000,
  B00000
};

byte fuego[] = {
  B00010,
  B00100,
  B01010,
  B10001,
  B10101,
  B01110,
  B00100,
  B00000
};

byte frio[] = {
  B00000,
  B10101,
  B01110,
  B11111,
  B01110,
  B10101,
  B00000,
  B00000
};

byte templado[] = {
  B11011,
  B00000,
  B01010,
  B10101,
  B10001,
  B01010,
  B00100,
  B11011
};

void setup() {
delay(1000);
Serial.begin(9600); 
LCD_David.init(); 
  LCD_David.backlight(); 
  LCD_David.clear(); 
sensors.begin();
LCD_David.createChar(1,term);
LCD_David.createChar(2,grados);
LCD_David.createChar(3,fuego);
LCD_David.createChar(4,frio);
LCD_David.createChar(5,templado);
ConfigPinesOutput();  
primera_fila(); 

}
 
void loop() {

valor_temp();

}
void ConfigPinesOutput(){
  pinMode(LED_AZUL,OUTPUT);
  pinMode(LED_AMAR,OUTPUT);
  pinMode(LED_ROJO,OUTPUT);
}

void primera_fila(){
  LCD_David.init(); 
  LCD_David.backlight(); 
  LCD_David.clear();
  LCD_David.setCursor(0,0);
  LCD_David.print("TERMOMETRO");
  LCD_David.setCursor(11,0);
  LCD_David.write(byte(1));
}


void valor_temp(){


  // variables para °C y °F
  celsius = func_celsius();
  farent = func_farent();

  // muestra °C
  LCD_David.setCursor(0,1);
  LCD_David.print(celsius);
  LCD_David.setCursor(4,1);
  LCD_David.write(2);
  LCD_David.setCursor(5,1);
  LCD_David.print("C");

  // muestra °F
  LCD_David.setCursor(7,1);
  LCD_David.print(farent);
  LCD_David.setCursor(12,1);
  LCD_David.write(2);
  LCD_David.setCursor(13,1);
  LCD_David.print("F");


// condiciones de temperatura :p
if (celsius >30){
  digitalWrite(LED_ROJO,HIGH);
  digitalWrite(LED_AMAR,LOW);
  digitalWrite(LED_AZUL,LOW);
  LCD_David.setCursor(15,1);
  LCD_David.write(3);
}

if (celsius > 15 && celsius < 30){
  digitalWrite(LED_AMAR,HIGH);
  digitalWrite(LED_ROJO,LOW);
  digitalWrite(LED_AZUL,LOW);
  LCD_David.setCursor(15,1);
  LCD_David.write(5);
}
  
if (celsius < 15 ){
  digitalWrite(LED_AZUL,HIGH);
  digitalWrite(LED_AMAR,LOW);
  digitalWrite(LED_ROJO,LOW);
  LCD_David.setCursor(15,1);
  LCD_David.write(4);
}


}

float func_celsius(){
  sensors.requestTemperatures();   
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}
float func_farent(){
  sensors.requestTemperatures();   
  float temp1 = sensors.getTempFByIndex(0); //Se obtiene la temperatura en ºF
  return temp1;
}
