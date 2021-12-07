// Arduino and KY-013 tutorial
void setup() {
  Serial.begin(9600);   // initialize serial interface with baud 9600bps
  pinMode(A1,INPUT);
}
void loop() {
  // Read value from module connected at pin A0
  int V_input = analogRead(A1);
  // calculate thermometer resistance by comparing it to the modules onboard 10K-ohm resistor
  float R_ohms = 10000 * (1023.0 / (float)V_input - 1.0);
  // calculate temperature in Celsius
  float temp_C = (1.0 / (0.001129148 + (0.000234125*log(R_ohms)) + 0.0000000876741*log(R_ohms)*log(R_ohms)*log(R_ohms)))-273.15;
  // output result to serial
  Serial.print("Temperature (degC): ");
  Serial.println(V_input);
}
