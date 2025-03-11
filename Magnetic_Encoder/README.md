## Used an AS5600 (Magnetic Encoder) with an Arduino Uno
> 10/03/2025

### Circuit:
- VCC (Module) > 5V (Arduino)
- GND (Module) > GND (Arduino)
- OUT (Module) > Analog pin (Arduino)
- GPO (Module) > 5V (Arduino)

### AS5600
AS5600 can be used using I2C as well. But personally reading the value using an analog pin felt more convenient to me. It has a 12bit ADC. But arduino can measure in 10 bits so it can't be used at its full potential with an Arduino. But 10 bit (0 - 1023) is good enough.
When the magnet is placed on the chip at 0 degrees, it'll output 0 volts, giving 0 reading to the analog pin. Changing the angle to 360 degrees would output the reference voltage connected to the `GPO` pin (5V), outputting 1023 reading to the analog pin.

### Code Explanation:
```cpp
  ...
  int aV = analogRead(enc);
  float a = (aV * 360.0) / 1023.0;
  ...
```
Reading the analog value from the specified pin, and mapping that value from _0 - 1023_ to _0 - 360_

.

```cpp
  ...
  Serial.print("Max:");
  Serial.print(360);
  Serial.print(",Angle:");
  Serial.print(int(a));
  Serial.print(",Min:");
  Serial.print(0);
  Serial.println();
```
This portion shows the angle value to the Serial Plotter.

---

Sometimes the angle can jump between 0 and 360 if you hold the magnet at 0 degree angle. This is not much of a big deal.
