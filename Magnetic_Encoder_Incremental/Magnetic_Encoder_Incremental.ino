#define enc A0

float Angle = 0;
float prevA = 0;


void setup() {
  Serial.begin(115200);

}

void loop() {
  int aV = analogRead(enc);

  float a = (aV * 360.0) / 1023.0;

  float dA = a - prevA;

  if(dA > 180){
    dA -= 360;
  }
  else if(dA < -180){
    dA += 360;
  }

  Angle += dA;

  prevA = a;

  Serial.println(Angle);
}
