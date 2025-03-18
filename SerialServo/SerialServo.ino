#define sPin 9

//#include <ESP32Servo.h>
#include <Servo.h>
Servo s;

int av = 180;
bool valIn = false;

int lower = 544, higher = 2400;

void setup() {
  Serial.begin(115200);
  s.attach(sPin, lower, higher);
}

void loop() {
  if (Serial.available() > 0) {
    String st = Serial.readStringUntil('\n');
    if(st.charAt(0) == 'l'){
      int l = st.substring(1).toInt();
      lower = l;
      s.detach();
      s.attach(sPin, lower, higher);
      Serial.print("Setting minimum pulse duration to ");
      Serial.print(l);   
      Serial.println(" micro seconds");
    }
    else if(st.charAt(0) == 'h'){
      int h = st.substring(1).toInt();
      higher = h;
      s.detach();
      s.attach(sPin, lower, higher);
      Serial.print("Setting maximum pulse duration to ");
      Serial.print(h);   
      Serial.println(" micro seconds");
    }
    else if (st.charAt(0) == 'v') {
      int v = st.substring(1).toInt();
      valIn = true;
      av = v;
      Serial.print("Setting pulse to ");
      Serial.print(v);   
      Serial.println(" micro seconds");
    }
    else {
      int a = st.toInt();
      valIn = false;
      av = a;
      Serial.print("Setting angle to ");
      Serial.print(a);   
      Serial.println(" degrees");
    }
  }

  if(valIn){
    s.writeMicroseconds(av);
  }else{
    s.write(av);
  }
  delay(15);
}
