# UCommand_WALL-E IR Controller
The control program of UCommand WALL-E with IR LED for Raspberry Pi3.

* Abstract
   * I got old used WALL-E from auction site but without no controller.
   * I found analied IR control codes from following site.
   * http://www.hifi-remote.com/forums/viewtopic.php?t=12137
   * I made IR LED board and C code from scratch.
   * Finally I got successfully controlled in 12 remote control commands.

![IMG_0120](https://user-images.githubusercontent.com/52347942/104117796-5ce23e80-5367-11eb-8b8f-f470dd248ce1.jpeg)

# Signal Spec
* http://www.hifi-remote.com/forums/viewtopic.php?t=12137

```
 Freq:    44 kHz
 1:       +1500 -500
 0:       +500  -1500
 Leadin:  +6000 -2000
 Leadout: +2000 -[enough long]
 Fixed data:    4 bits
 Variable data: 8 bits (repeated twice)
 ------------------------------------------------
 1: Joystick Forward
 +6000 -2000 1010 11111110 11111110 +2000 -46500
 
 2: Joystick Backward
 +6000 -2000 1010 11111101 11111101 +2000 -46500
 
 3: Ahead Button
 +6000 -2000 1010 10101110 10101110 +2000 -87000
 
 4: Turn Button (once only)
 +6000 -2000 1010 10101100 10101100 +2000 -?????
 
 5: Rotate Button
 +6000 -2000 1010 10101101 10101101 +2000 -64000
 
 6: Circle Button
 +6000 -2000 1010 10101011 10101011 +2000 -123500
 
 7: Light Button
 +6000 -2000 1010 10100100 10100100 +2000 -59000
 
 8: Music Button
 +6000 -2000 1010 10100110 10100110 +2000 -79500
 
 9: Dance Button
 +6000 -2000 1010 10100101 10100101 +2000 -86000
 
 10: Eyes Button
 +6000 -2000 1010 10100111 10100111 +2000 -68000
 
 11: Talk Button
 +6000 -2000 1010 10101010 10101010 +2000 -68000
 
 12: Mecha Button
 +6000 -2000 1010 10101001 10101001 +2000 -68000
```

# Original Pictures
## UCommand WALL-E & Original Remote Controller

![IMG_0086](https://user-images.githubusercontent.com/52347942/104117746-fceb9800-5366-11eb-8434-29a25016ac04.jpeg)

![IMG_0088](https://user-images.githubusercontent.com/52347942/104117760-18ef3980-5367-11eb-8930-d83f8c0ebe57.jpeg)

# Schematic

![SCHEMATIC](https://user-images.githubusercontent.com/52347942/120874582-3c4ea580-c5e2-11eb-97eb-cf968f15a39c.png)

| No.| index       | item                    | num |
| -- | ----------- | ----------------------- | --- |
| 1  | IR LED 1-3  | IR-LED (OSI5FU5111C-40) | 3   |
| 2  | R1-3        | Resistor (10 ohm)       | 3   |
| 3  | R1(sorry it should be R4) | Resistor (2.2K ohm)     | 1   |
| 4  | N           | Transistor (2SC1815)    | 1   |
| 5  | IR Reciever | (not used)              | 0   |

NOTE

* IR Reciever is not needed for this case.
  * This WALL-E uses 44kHz IR signal.
  * But popular IR Reciever is for 38kHz signal.
* Pin assignment of 2SC1815
  * E, C, B (from left)

# Setup
* Connect pins of IR LED board.
   * GPIO23 to IR LED out.
   * 5V and GND

# Build

```
> sudo apt install wiringpi
> gcc ./wall-e_control.c -o ./wall-e_control.out -lwiringPi
```

# Run
* run `wall-e_control.out` and type command number.

```
> wall-e_control.out
1: BUTTON_AHEAD
2: BUTTON_LIGHT
3: BUTTON_TURN
4: BUTTON_ROTATE
5: BUTTON_CIRCLE
6: BUTTON_DANCE
7: BUTTON_MUSIC
8: BUTTON_EYES
9: BUTTON_TALK
10: BUTTON_MECHA
11: JOYSTICK_FORWARD
12: JOYSTICK_BACKWARD
0: QUIT
INPUT COMMAND>
```

![IMG_0090](https://user-images.githubusercontent.com/52347942/104117774-3a502580-5367-11eb-8563-f92abc0c8a87.jpeg)

