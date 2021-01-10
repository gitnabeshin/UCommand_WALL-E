# UCommand_WALL-E
UCommand WALL-E control program with IR Code

* You can control UCommand WALL-E with IR LED using Raspberry Pi3.
   * I got used one without original controller. But I found following site.
   * http://www.hifi-remote.com/forums/viewtopic.php?t=12137
   * Then I made this code and controlled successfully with IR LED.

![IMG_0120](https://user-images.githubusercontent.com/52347942/104117796-5ce23e80-5367-11eb-8b8f-f470dd248ce1.jpeg)

# Signal Spec

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

![IMG_0086](https://user-images.githubusercontent.com/52347942/104117746-fceb9800-5366-11eb-8434-29a25016ac04.jpeg)

![IMG_0088](https://user-images.githubusercontent.com/52347942/104117760-18ef3980-5367-11eb-8930-d83f8c0ebe57.jpeg)

![IMG_0090](https://user-images.githubusercontent.com/52347942/104117774-3a502580-5367-11eb-8563-f92abc0c8a87.jpeg)

