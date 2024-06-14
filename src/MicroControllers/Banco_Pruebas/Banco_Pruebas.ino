#include "HX711.h"
 
// Pin de datos y de reloj
byte pinData = 4;
byte pinClk = 5;

// Instanciamos una bascula nueva
HX711 bascula;
 
// Parámetro para calibrar el peso y el sensor
//float factor_calibracion = 22350.0;  // Banco de 100 Kg
float factor_calibracion = 3300.0;
 
void setup() {
  Serial.begin(9600); 
  // Iniciar sensor
  bascula.begin(pinData, pinClk);
 
  // Aplicar la calibración
  bascula.set_scale();
  // Iniciar la tara
  // No tiene que haber nada sobre el peso
  bascula.tare();
 
  // Obtener una lectura de referencia
  long zero_factor = bascula.read_average();
}

void loop() {
 
  // Aplicar calibración
  bascula.set_scale(factor_calibracion);
 
  // Mostrar la información para ajustar el factor de calibración

  float empuje = bascula.get_units();

  if(empuje<0){
    empuje*=-1;
  }

  Serial.print(empuje, 8);
  Serial.println();
}
