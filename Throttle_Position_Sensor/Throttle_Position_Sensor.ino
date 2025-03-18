#define enc A0

void setup() {
  Serial.begin(9600);
}

void loop() {
  int v = analogRead(enc);

  Serial.print("Min:0,");
  Serial.print("Value:"+String(v)+",");
  Serial.println("Max:1023");
}
