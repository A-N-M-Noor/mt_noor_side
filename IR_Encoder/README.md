## Used the IR Encoder with an Arduino Uno

> 10/03/2025

### Circuit:
- 5V (Module) > 5V (Arduino)
- GND (Module) > GND (Module)
- OUT (Module) > Any inturrupt pin (Arduino)


### Code explanation:


```cpp
#define interruptPin 3
```
Arduino Uno has two inturrupt pins. Difital pin 2 and 3. Here, 3 is used.

.

```cpp
int res = 20;
float maxRPM = 100;
```
`res`: Slots in the encoder wheel<br>
`maxRPM`: probable max rotation speed of the motor

.

```cpp
void setup() {
  ...
  attachInterrupt(digitalPinToInterrupt(interruptPin), count, FALLING);
  ...
```
Attach a callback (`count`) to the inturrupt pin. Set the mode to `FALLING`. Meaning the callback will trigger once at the moment the signal gows from HIGH to LOW.

.

```cpp
void setup() {
  ...
  tmr = millis();
  minDel = int( (1 / res*maxRPM) * 60 * 1000 * 0.75);
}
```
One issue with the IR Encoder is, sometimes it gets multiple pulses when the state changes. That's why, I calculated a minimum delay based on the probable max RPM of the motor. This way, after the state is changed, it won't count another change before that amount of time has passed. Multiplied by 0.75 to make in work even if the motor runs at the theoretical max speed.

.

```cpp
void count() {
  if(millis() - tmr > minDel){
    step++;
  }
  tmr = millis();
}
```
Only increase the step count if a certain amount of time has passed after the last pulse.

---

[Learn more about inturrupts in Arduino](https://www.arduino.cc/reference/cs/language/functions/external-interrupts/attachinterrupt/)
