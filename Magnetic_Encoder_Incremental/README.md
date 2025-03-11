## Magnetic encoder but the angle does not reset to zero
> 10/03/2025

Check out the basic code [here](./Magnetic_Encoder)

The problem with this is:
- It goes back to zero after reaching 360
- It does not preserve the direction the spinning magnet

This code:
- Increase the angle value on one direction, decreases in the other direction
- Can have negative values indicating spinning directions
- Can go beyond 360 degrees if the spinning part keeps spinning
