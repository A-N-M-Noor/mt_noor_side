## Servo Tester
> 18/03/2025

This code can be used to test a servo. 

Features:
- Directly setting the angle
  - The angle, meaning 0 to 180 degrees. The one you set using `servo.write()`
- Setting the PWM pulse width in microseconds
  - The pulse width in microseconds. The one you set using `servo.writeMicroseconds()`
- Changing the lower and upper pulse width limit to the servo library
  - By default, Arduino's servo library sets the pulse-width limit as from 544μs to 2400μs. So you can't set the pulse beyond this range. But most servos can actually use values beyond this range. And you can change the limit using the same old `attach()` function like this: `servo.attach(pin, lower_limit, upper_limit)`. But this code allows you to change it on the fly from the serial monitor.

### Circuit
Standard servo circuit.

---
---

### Usage
> Set Angle

Directly input a number using the Serial monitor to set the servo angle. Like this: `[angle value]`

For example:
```
90
```

.

> Set Pulse Width

To set the pulse width, format it like this: `v[pulse width]`.

For example:
```
v1500
```
.

> Set pulse range

To set the minimum range, format it like this: `l[lower range]`.
For example:
```
l450
```
To set the maximum range, format it like this: `h[higher range]`.
For example:
```
h3000
```

> [!NOTE]  
> You'll see confirmation message for each successful command.

---
---

### Code Explanation
Just read the code and try to understand. It's pretty easy. Good luck!
