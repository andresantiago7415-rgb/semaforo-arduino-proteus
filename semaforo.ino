// Semáforo Vehicular 1 (Vía 1)
const int v1R = 2;
const int v1Y = 3;
const int v1G = 4;

// Semáforo Vehicular 2 (Vía 2)
const int v2R = 5;
const int v2Y = 6;
const int v2G = 7;

// Semáforo Peatonal
const int pedR = 8; // Rojo peatón (Alto)
const int pedG = 9; // Verde peatón (Cruce libre)

void setup() {
  // Configuramos todos los pines como salidas
  pinMode(v1R, OUTPUT); pinMode(v1Y, OUTPUT); pinMode(v1G, OUTPUT);
  pinMode(v2R, OUTPUT); pinMode(v2Y, OUTPUT); pinMode(v2G, OUTPUT);
  pinMode(pedR, OUTPUT); pinMode(pedG, OUTPUT);
}

void loop() {
  // --- FASE 1: Vía 1 en Verde, Vía 2 en Rojo. Peatones cruzan seguros ---
  digitalWrite(v1R, LOW);  digitalWrite(v1Y, LOW);  digitalWrite(v1G, HIGH);
  digitalWrite(v2R, HIGH); digitalWrite(v2Y, LOW);  digitalWrite(v2G, LOW);
  digitalWrite(pedR, LOW); digitalWrite(pedG, HIGH); // Verde peatón
  delay(5000); // 5 segundos de paso

  // --- FASE 2: Transición Vía 1 a Amarillo y Peatón a Rojo ---
  digitalWrite(v1G, LOW);  digitalWrite(v1Y, HIGH);
  digitalWrite(pedG, LOW); digitalWrite(pedR, HIGH); // Rojo peatón
  delay(2000); // 2 segundos de precaución
  
  digitalWrite(v1Y, LOW);  digitalWrite(v1R, HIGH); // Vía 1 pasa a Rojo

  // --- FASE 3: Vía 2 en Verde (Vía 1 se queda en Rojo) ---
  digitalWrite(v2R, LOW);  digitalWrite(v2Y, LOW);  digitalWrite(v2G, HIGH);
  delay(5000); // 5 segundos de paso para la Vía 2

  // --- FASE 4: Transición Vía 2 a Amarillo ---
  digitalWrite(v2G, LOW);  digitalWrite(v2Y, HIGH);
  delay(2000); // 2 segundos de precaución
  
  digitalWrite(v2Y, LOW);  digitalWrite(v2R, HIGH); // Vía 2 pasa a Rojo
}