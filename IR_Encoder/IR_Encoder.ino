#define interruptPin 3

int step = 0;
int res = 20;
float maxRPM = 100;

long tmr;
int minDel = 0;

void setup() {
  Serial.begin(115200);
  pinMode(interruptPin, INPUT);
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, FALLING);

  tmr = millis();
  minDel = int( (1 / res*maxRPM) * 60 * 1000 * 0.75);
}

void loop() {
  Serial.println(step);
}

void count() {
  if(millis() - tmr > minDel){
    step++;
  }
  tmr = millis();
}
