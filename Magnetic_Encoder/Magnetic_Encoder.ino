#define enc A0

void setup() {
  Serial.begin(115200);
}

void loop() {
  int aV = analogRead(enc);

  float a = (aV * 360.0) / 1023.0;

  Serial.print("Max:");
  Serial.print(360);
  Serial.print(",Angle:");
  Serial.print(int(a));
  Serial.print(",Min:");
  Serial.print(0);
  Serial.println();
}
