

void setup() {
  Serial.begin(9600);
  delay(2000);
  Serial.println("=== ESP32 Emisor PRT-7 Iniciado ===");
}

void loop() {
  // Secuencia simulada de tramas
  Serial.println("L,H");
  delay(500);
  Serial.println("L,O");
  delay(500);
  Serial.println("L,L");
  delay(500);
  Serial.println("M,2");
  delay(500);
  Serial.println("L,A");
  delay(500);
  Serial.println("L,Space");
  delay(500);
  Serial.println("L,W");
  delay(500);
  Serial.println("M,-2");
  delay(500);
  Serial.println("L,O");
  delay(500);
  Serial.println("L,R");
  delay(500);
  Serial.println("L,L");
  delay(500);
  Serial.println("L,D");
  delay(2000);
}