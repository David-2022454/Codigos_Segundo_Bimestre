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
#include <OneWire.h>                
#include <DallasTemperature.h>
#include <Wire.h>   
#include <LiquidCrystal_I2C.h>  
#include <Adafruit_NeoPixel.h>
#include <Servo.h>

int estado_boton_1 = 0;
int estado_boton_2 = 0;
int estado_boton_3 = 0;

#define direccion_lcd 0x27
#define filas 2
#define columnas 16
#define DW1(pin) digitalWrite(pin,HIGH)
#define DW0(pin) digitalWrite(pin,LOW)
#define BUZZER 3
#define RADAR 5
#define NEO_PIXEL 6
#define Cantidad_Leds 7
#define RELE_1 7
#define RELE_2 8
#define SERVO_MOTOR 9
#define LED_R 12
#define LED_G 11
#define LED_B 10
#define BOTT_1 13
#define BOTT_2 14
#define BOTT_3 15
float celsius;

enum colores
{
   amarillo,
   azul,
   rojo, 
   negro
};

byte temp1[] = {
  B00000,
  B00100,
  B01110,
  B11111,
  B01110,
  B00100,
  B00000,
  B11111
};
byte temp2[] = {
  B00000,
  B01010,
  B11111,
  B11111,
  B01110,
  B00100,
  B00000,
  B11111
};
byte temp3[] = {
  B00010,
  B00100,
  B01010,
  B10001,
  B10101,
  B01110,
  B00000,
  B11111
};
byte radar[] = {
  B00000,
  B00000,
  B01110,
  B10011,
  B10101,
  B11001,
  B01110,
  B00000
};
byte foco_OFF[] = {
  B00000,
  B01110,
  B10001,
  B10001,
  B10001,
  B01110,
  B01110,
  B00000
};
byte foco_ON[] = {
  B00000,
  B01110,
  B11111,
  B11111,
  B11111,
  B01110,
  B01110,
  B00000
};


LiquidCrystal_I2C LCD_David(0x27, columnas, filas);
Adafruit_NeoPixel anillo(Cantidad_Leds,NEO_PIXEL, NEO_GRB + NEO_KHZ800);
OneWire ourWire(2);               
DallasTemperature sensors(&ourWire); 

Servo Motor_David;

void ConfigPinesOutput(void);
void ConfigPinesInput(void);
void deteccion_radar(void);
void setColor(int color);
void puerta_motor(void);
void luminarias(void);
void temperatura(void);
void datos_lcd(void);
float func_celsius();



void setup() {

  LCD_David.init(); 
  LCD_David.backlight(); 
  sensors.begin();
  anillo.begin();
  Motor_David.attach(SERVO_MOTOR);
  ConfigPinesOutput();  
  ConfigPinesInput();  
  LCD_David.createChar(1,temp1);
  LCD_David.createChar(2,temp2);
  LCD_David.createChar(3,temp3);
  LCD_David.createChar(4,radar);
  LCD_David.createChar(5,foco_OFF);
  LCD_David.createChar(6,foco_ON);
}

void loop() {
  datos_lcd();
  puerta_motor();
  luminarias();
  temperatura();
  deteccion_radar();
  datos_lcd();
  puerta_motor();
  luminarias();
  temperatura();
  deteccion_radar();
  datos_lcd();
  puerta_motor();
  luminarias();
  temperatura();
  deteccion_radar();
  datos_lcd();
  puerta_motor();
  luminarias();
  temperatura();
  deteccion_radar();
  datos_lcd();
  puerta_motor();
  luminarias();
  temperatura();
  deteccion_radar();datos_lcd();
  puerta_motor();
  luminarias();
  temperatura();
  deteccion_radar();
}

void ConfigPinesOutput(){
  pinMode(BUZZER,OUTPUT);
  pinMode(RELE_1,OUTPUT);
  pinMode(RELE_2,OUTPUT);
  pinMode(LED_R,OUTPUT);
  pinMode(LED_G,OUTPUT);
  pinMode(LED_B,OUTPUT);
}
void ConfigPinesInput(){
  pinMode(RADAR,INPUT);
  pinMode(BOTT_1,INPUT);
  pinMode(BOTT_2,INPUT);
  pinMode(BOTT_3,INPUT);
}

void deteccion_radar(){
  
 int valor= digitalRead(RADAR);
 
  if (valor == HIGH){
  tone(BUZZER,1000);
  LCD_David.setCursor(13,0);
  LCD_David.write(byte(4));
  setColor(amarillo);
  delay(500);
  setColor(azul);
  delay(500);
  setColor(rojo);
  delay(500);
  setColor(amarillo);
  delay(500);
  setColor(azul);
  delay(500);
  setColor(rojo);
  delay(500);
  noTone(BUZZER);
  }
if (valor == LOW){
  setColor(negro);
  }
}


void setColor(int color)
{
  switch(color) {
    case(amarillo):{
        for(int i =0; i<8; i++){
          anillo.setPixelColor(i,anillo.Color(255,255,0));
          anillo.show();  //muestro el color en el led
        } 
      break;
    }
    case(azul):{
        for(int i =0; i<8; i++){
          anillo.setPixelColor(i,anillo.Color(0,0,255));
          anillo.show();  //muestro el color en el led
        }
      break;
    }
    case(rojo):{
        for(int i =0; i<8; i++){
          anillo.setPixelColor(i,anillo.Color(255,0,0));
          anillo.show();  //muestro el color en el led
        } 
      break;
    }
      case(negro):{
        for(int i =0; i<8; i++){
          anillo.setPixelColor(i,anillo.Color(0,0,0));
          anillo.show();  //muestro el color en el led
        } 
      break;
    }
  }
}

void puerta_motor(){
  int presionar = digitalRead(BOTT_3);

  if (presionar == HIGH)
  {
    estado_boton_3 = !estado_boton_3; 

  }
  if (estado_boton_3 == HIGH){
    LCD_David.setCursor(10,1);
    LCD_David.print("Close");
    Motor_David.write(45);
    delay(150);
  }
  else{
    LCD_David.setCursor(10,1);
    LCD_David.print("Open");
     Motor_David.write(180);
     delay(150);
  }
}

void luminarias(){
  int lectura_1 = digitalRead(BOTT_1);
  int lectura_2 = digitalRead(BOTT_2);

  if (lectura_1 == HIGH){
    estado_boton_1 = !estado_boton_1;
  
  }
  if (lectura_2 == HIGH){
    estado_boton_2 = !estado_boton_2;
  
  }
  
  if (estado_boton_1 == HIGH){
    LCD_David.setCursor(2,1);
    LCD_David.write(byte(6));
    DW0(RELE_1);
  }
  else {
    DW1(RELE_1);
  }
  
  if (estado_boton_2 == HIGH){
    LCD_David.setCursor(6,1);
    LCD_David.write(byte(6));
    DW0(RELE_2);
  }
 else{
    DW1(RELE_2);
  }
}

void temperatura(){
  celsius = func_celsius();
  
  if (celsius < 15){
    DW0(LED_R);
    DW0(LED_G);
    DW0(LED_B);
  }
  if (celsius >15 && celsius <21){
    LCD_David.setCursor(5,0);
    LCD_David.write(byte(1));
    delay(50);
    DW1(LED_R);
    DW0(LED_G);
    DW1(LED_B);
  }
  if (celsius >21 && celsius  <25){
    LCD_David.setCursor(5,0);
    LCD_David.write(byte(2));
    delay(50);
    DW0(LED_R);
    DW1(LED_G);
    DW0(LED_B);
  }
  if (celsius >25 && celsius <45){
    LCD_David.setCursor(5,0);
    LCD_David.write(byte(3));
    delay(50);
    DW1(LED_R);
    DW0(LED_G);
    DW0(LED_B);
  }
  if (celsius >45){
    DW0(LED_R);
    DW0(LED_G);
    DW0(LED_B);

}
}

float func_celsius(){
  sensors.requestTemperatures();   
  float temp= sensors.getTempCByIndex(0); //Se obtiene la temperatura en ºC
  return temp;
}

void datos_lcd(){
    LCD_David.init(); 
    LCD_David.backlight(); 
    LCD_David.setCursor(0,0);
    LCD_David.print("TEMP:");
    
    LCD_David.setCursor(7,0);
    LCD_David.print("Alarm:o");

    LCD_David.setCursor(0,1);
    LCD_David.print("L1");
    LCD_David.setCursor(4,1);
    LCD_David.print("L2");

    LCD_David.setCursor(6,1);
    LCD_David.write(byte(5));

    LCD_David.setCursor(2,1);
    LCD_David.write(byte(5));
    
    LCD_David.setCursor(8,1);
    LCD_David.print("D=");
}
