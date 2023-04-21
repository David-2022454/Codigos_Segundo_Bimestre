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

#define ECO  2
#define TRIG 3
#define RELE 8
#define DW1(pin) digitalWrite(pin,HIGH)
#define DW0(pin) digitalWrite(pin,LOW)
int DURACION;
int DISTANCIA;
int i = 0;
void numero_0 (void);
void medicion(void);
void ConfigPinesInput(void);
void ConfigPinesOutput(void);
void Config_display_7_segmentos(int A, int B, int C, int D, int E, int F, int G, bool tipo_de_display);

void setup()
{
  ConfigPinesInput();
  ConfigPinesOutput();
  Config_display_7_segmentos(10, 11, 12, 13, 14, 15, 16, HIGH);
  numero_0 ();

}

void loop()
{
  contador();
  medicion();

}


void ConfigPinesInput(void) {
  pinMode(ECO, INPUT);
}
void ConfigPinesOutput(void) {
  pinMode(TRIG, OUTPUT);
  pinMode(RELE, OUTPUT);
}

void Config_display_7_segmentos(int A, int B, int C, int D, int E, int F, int G, bool tipo_de_display) {

  pinMode(A, OUTPUT);
  pinMode(B, OUTPUT);
  pinMode(C, OUTPUT);
  pinMode(D, OUTPUT);
  pinMode(E, OUTPUT);
  pinMode(F, OUTPUT);
  pinMode(G, OUTPUT);

}

void numero_0() {
  DW1(10);
  DW1(11);
  DW1(12);
  DW1(13);
  DW1(14);
  DW1(15);
  DW0(16);
  DW1(RELE);
}

void medicion() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);

  DURACION = pulseIn(ECO, HIGH);
  DISTANCIA = DURACION / 58;

}

void contador(){
  if (DISTANCIA >= 6 && DISTANCIA <= 9) {
    i = i + 1;
    delay(500);
  }
switch (i) {
    case 1:
      DW0(10);
      DW1(11);
      DW1(12);
      DW0(13);
      DW0(14);
      DW0(15);
      DW0(16);
      DW1(RELE);
      break;
      
    case 2: 
      DW1(10);
      DW1(11);
      DW0(12);
      DW1(13);
      DW1(14);
      DW0(15);
      DW1(16);
      DW1(RELE);
      break;
    
    case 3: 
      DW1(10);
      DW1(11);
      DW1(12);
      DW1(13);
      DW0(14);
      DW0(15);
      DW1(16);
      DW1(RELE);
      break;
    case 4: 
      DW0(10);
      DW1(11);
      DW1(12);
      DW0(13);
      DW0(14);
      DW1(15);
      DW1(16);
      DW1(RELE);
    break;
    case 5:
      DW1(10);
      DW0(11);
      DW1(12);
      DW1(13);
      DW0(14);
      DW1(15);
      DW1(16);
      DW1(RELE);
          break;
   case 6: 
      DW1(10);
      DW0(11);
      DW1(12);
      DW1(13);
      DW1(14);
      DW1(15);
      DW1(16);
      DW1(RELE);
          break;
      case 7: 
      DW1(10);
      DW1(11);
      DW1(12);
      DW0(13);
      DW0(14);
      DW0(15);
      DW0(16);
      DW1(RELE);
      break;
    case 8:
      DW1(10);
      DW1(11);
      DW1(12);
      DW1(13);
      DW1(14);
      DW1(15);
      DW1(16);
      DW1(RELE);
      break;
    case 9:
      DW1(10);
      DW1(11);
      DW1(12);
      DW0(13);
      DW0(14);
      DW1(15);
      DW1(16);
      DW0(RELE);
      break;
    }

}
