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

#define BUZZER 9
#define TRIG 3
#define ECHO 2
const int n_do = 261;
const int n_re = 294;
const int n_mi = 329;
const int n_fa = 349;
const int n_sol = 392;
const int n_la = 440;
long DURACION;
long DISTANCIA;
void ConfigPinesInput();
void ConfigPinesOutput();
int medicion();
void ConfigBuzzer();
 void Trig_low();
 
void setup()    
{   
 Serial.begin(9600); 
 ConfigPinesInput();
 ConfigPinesOutput();
 Trig_low();
 
}    
     
void loop()   
{  
 medicion();
 ConfigBuzzer(DISTANCIA);  

}

void ConfigPinesInput(void) {
  pinMode(ECHO, INPUT);
}
void ConfigPinesOutput(void) {
  pinMode(TRIG, OUTPUT);
  pinMode(BUZZER, OUTPUT);

}

void Trig_low(void){
digitalWrite(TRIG, LOW);
  
}

int medicion() {
  digitalWrite(TRIG, HIGH);
  delay(1);
  digitalWrite(TRIG, LOW);

  DURACION = pulseIn(ECHO, HIGH);
  DISTANCIA = DURACION / 58;
Serial.println(DISTANCIA);
delay(100);
return DISTANCIA;
}

void ConfigBuzzer(int valor_distancia){
switch(valor_distancia){
    case (4):
   tone(BUZZER, n_do);
    delay(600);
    valor_distancia = 0;
     break;
    case (8):
   tone(BUZZER, n_re);
    delay(600);
        valor_distancia = 0;
     break;
    case (12):
   tone(BUZZER, n_mi);
    delay(600);
        valor_distancia = 0;
     break;
    case (16):
   tone(BUZZER, n_fa);
    delay(600);   
        valor_distancia = 0;
     break;
     case (20):
   tone(BUZZER, n_sol);
    delay(600);
        valor_distancia = 0;
     break;
    case (24):
   tone(BUZZER, n_la);
    delay(600);
        valor_distancia = 0;
     break;
     
    default:
      noTone(BUZZER);
        valor_distancia = 0;
        break;

}
     }
