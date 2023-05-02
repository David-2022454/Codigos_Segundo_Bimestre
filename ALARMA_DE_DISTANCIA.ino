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
#define BUZZER 2
#define ECHO 13
#define TRIG 14
long DURACION;
long DISTANCIA;
#define Led1 3
#define Led2 4
#define Led3 5
#define Led4 6
#define Led5 7
#define Led6 8
#define Led7 9
#define Led8 10
#define Led9 11
#define Led10 12

LiquidCrystal_I2C LCD_David(0x27, columnas, filas); 

void ConfigPinesInput(void);
void ConfigPinesOutput(void);
int medicion(void);
int alerta_de_acercamiento(void);

void setup()
{
  Serial.begin(9600);
  LCD_David.begin(16,2);
  LCD_David.init(); 
  LCD_David.backlight(); 
  ConfigPinesInput();
  ConfigPinesOutput();
}


void loop()
{
medicion(); 
alerta_de_acercamiento();
}

void ConfigPinesInput(){
pinMode(ECHO,INPUT);
}

void ConfigPinesOutput() {
pinMode(TRIG,OUTPUT);
pinMode(BUZZER,OUTPUT);
pinMode(Led1,OUTPUT);  
pinMode(Led2,OUTPUT); 
pinMode(Led3,OUTPUT); 
pinMode(Led4,OUTPUT); 
pinMode(Led5,OUTPUT); 
pinMode(Led6,OUTPUT);  
pinMode(Led7,OUTPUT); 
pinMode(Led8,OUTPUT); 
pinMode(Led9,OUTPUT); 
pinMode(Led10,OUTPUT); 
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

int alerta_de_acercamiento(){
  if (DISTANCIA >=45) {
  LCD_David.init(); 
  LCD_David.backlight(); 
    LCD_David.clear();
    LCD_David.setCursor(0,0);
    LCD_David.print("Fuera de alcance");
    DW1(Led10);
    DW1(Led9);
    DW0(Led8);
    DW0(Led7);
    DW0(Led6);
    DW0(Led5);
    DW0(Led4);
    DW0(Led3);
    DW0(Led2);
    DW0(Led1);
        
  }

    if (DISTANCIA >= 30 && DISTANCIA <= 45) { 
 LCD_David.clear();
    LCD_David.setCursor(0,0);
    LCD_David.print("Persona/objeto");
    LCD_David.setCursor(0,1);
    LCD_David.print("Acercandose");
    DW1(Led10);
    DW1(Led9);
    DW1(Led8);
    DW1(Led7);
    DW0(Led6);
    DW0(Led5);
    DW0(Led4);
    DW0(Led3);
    DW0(Led2);
    DW0(Led1);
       
  }
 
    if (DISTANCIA >= 15 && DISTANCIA <= 30) {
       LCD_David.clear();
    LCD_David.setCursor(0,0);
    LCD_David.print("Cuidado");
    LCD_David.setCursor(0,1);
    LCD_David.print("Espacio Privado");
    DW1(Led10);
    DW1(Led9);
    DW1(Led8);
    DW1(Led7);
    DW1(Led6);
    DW1(Led5);
    DW1(Led4);
    DW0(Led3);
    DW0(Led2);
    DW0(Led1);    
    tone(BUZZER,600);
     delay(5000);
noTone(BUZZER);

  }
  if (DISTANCIA >= 5 && DISTANCIA <= 15) {
     LCD_David.clear();
    LCD_David.setCursor(0,0);
    LCD_David.print("Invadiendo");
    LCD_David.setCursor(0,1);
    LCD_David.print("Espacio Privado");
    DW1(Led10);
    DW1(Led9);
    DW1(Led8);
    DW1(Led7);
    DW1(Led6);
    DW1(Led5);
    DW1(Led4);
    DW1(Led3);
    DW1(Led2);
    DW1(Led1);
  
    tone(BUZZER,1000);
    delay(10000);
noTone(BUZZER);
   
    }

}
