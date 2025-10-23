// C++ code
//
// Total filas = 3; columnas = 3; altura = 3
// Leds por filas x columnas = 9
// Leds totales = 27
// Conexiones columnas = 9
// Conexiones filas = 3
/*
Nivel 1: Pin 11
Nivel 2: Pin 12
Nivel 3: Pin 13
*/
/*
Se dispuso de esa forma ya que así se 
pueden encender leds específicos
¿Por qué transistores? Para manejar la carga de los leds
Se usan resistencias de 10k para proteger al Arduino
*/

/*
¿Cómo se crean patrones?
Para crear patrones hay que tener en cuenta dos cosas:
1. El nivel
2. El led a encender
(NIVEL, LED)
En este orden de ideas, para hacer un patrón
bastaría con una secuencia (NIVEL, LED)..(NIVEL,LED)..

*/

void setup()
{
  // Configurar pines en modo salida
  for(int i=2; i < 14; i++){
    pinMode(i, OUTPUT);
  }
}
// Control de capas
void PATRON11();
void PATRON22();
void PATRON33();
void loop()
{
  PATRON11();
  delay(1000);
  PATRON22();
  delay(1000);
  PATRON33();
  delay(1000);
}
// Habilitar SÓLO la capa 1
void PATRON11(){
  digitalWrite(11, HIGH); // NIVEL 1 HABILITADO
  // Habilitar LED
  //digitalWrite(2, HIGH); // LED 1 NIVEL 1 HABILITADO 
  //digitalWrite(10, HIGH); // LED 9 NIVEL 1 HABILITADO
  // Habilitar TODO el NIVEL 1
  for(int i = 2; i <= 10; i++){
    digitalWrite(i, HIGH);
    delay(100);
  }
  delay(1000);
  // Deshabilitar TODO el NIVEL 1
  for(int i = 10; i >= 2; i--){
    digitalWrite(i, LOW);
    delay(100);
  }
}
// Habilitar SÓLO la capa 2
// Deshabilitar capas anteriores
void PATRON22(){
  digitalWrite(12, HIGH); // NIVEL 2 HABILITADO
  digitalWrite(11, LOW); // NIVEL 1 DESHABILITADO
  // Habilitar TODO el NIVEL 2
  for(int i = 2; i <= 10; i++){
    digitalWrite(i, HIGH);
    delay(100);
  }
  delay(1000);
  // Deshabilitar TODO el NIVEL 2
  for(int i = 10; i >= 2; i--){
    digitalWrite(i, LOW);
    delay(100);
  }
}
// Habilitar SÓLO la capa 3
// Deshabilitar capas anteriores
void PATRON33(){
  digitalWrite(13, HIGH); // NIVEL 3 HABILITADO
  digitalWrite(12, LOW); // NIVEL 2 DESHABILITADO
  digitalWrite(11, LOW); // NIVEL 1 DESHABILITADO
  // Habilitar TODO el NIVEL 3
  for(int i = 2; i <= 10; i++){
    digitalWrite(i, HIGH);
    delay(100);
  }
  delay(1000);
  // Deshabilitar TODO el NIVEL 3
  for(int i = 10; i >= 2; i--){
    digitalWrite(i, LOW);
    delay(100);
  }
}







