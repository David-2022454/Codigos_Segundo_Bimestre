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

LiquidCrystal LCD_David(RS, Enable, D4, D5, D6, D7);
void setup() {
LCD_David.begin(16,2);

}

void loop() {
LCD_David.setCursor(0,0); 
LCD_David.write("Juan David");
LCD_David.setCursor(0,1); 
LCD_David.write("2022454");

}
