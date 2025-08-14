#include "MentorBitSGP30.h"

MentorBit_SGP30 miSGP;

void setup() {

  Serial.begin(9600);
  if(miSGP.begin()) Serial.println("Iniciado");
  else Serial.println("Error");
  delay(1000);

  /*Serial.print("Número de Serie: ");
  Serial.println(miSGP.obtenerNumeroSerie());
  Serial.println();*/

}

void loop() {

  miSGP.tomarMedidas();
  Serial.print("TVOC: ");
  Serial.println(miSGP.obtenerTVOC());
  Serial.print("eCO2: ");
  Serial.println(miSGP.obtenerECO2());
  Serial.print("H2 crudo: ");
  Serial.println(miSGP.obtenerH2Crudo());
  Serial.print("Etanol crudo: ");
  Serial.println(miSGP.obtenerEthanolCrudo());
  Serial.println();
  delay(1000);

}
