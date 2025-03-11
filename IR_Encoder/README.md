Used the IR Encoder

> 10/03/2025

I used with an Arduino Uno.

Circuit:
- 5V (Module) > 5V (Arduino)
- GND (Module) > GND (Module)
- OUT (Module) > Any inturrupt pin (Arduino)

[Learn more about inturrupts in Arduino](https://www.arduino.cc/reference/cs/language/functions/external-interrupts/attachinterrupt/)

One issue with the IR Encoder is, sometimes it gets multiple pulses when the state changes. That's why, I calculated a minimum delay based on the probable max RPM of the motor. This way, after the state is changed, it won't count another change before that amount of time has passed.
