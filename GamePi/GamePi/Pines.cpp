//
//  Pines.cpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 29/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#include "Pines.h"

/*
 1 = A          9 = Ignored   17 = +--+
 2 = B         10 = Ignored   18 =    +-- Signature
 3 = SELECT    11 = Ignored   19 =    |
 4 = START     12 = Ignored   20 = +--+
 5 = UP        13 = Ignored   21 = 0
 6 = DOWN      14 = Ignored   22 = 0
 7 = LEFT      15 = Ignored   23 = 0
 8 = RIGHT     16 = Ignored   24 = 0
 
 G. Signatures
 -------------
 A signature allows the programmer to detect if a device is connected
 to one of the four (4) ports or not, and if so, what type of device it
 is. Valid/known signatures are:
 
 %0000 = Disconnected
 %0001 = Joypad ($4016 only)
 %0010 = Joypad ($4017 only)
 */

#include <iostream>
//#include <wiringPi.h>
#include "Types.h"

/*Pines::Pines() {
    pinMode(A, INPUT);
    pinMode(B, INPUT);
    pinMode(LEFT, INPUT);
    pinMode(RIGHT, INPUT);
    pinMode(UP, INPUT);
    pinMode(DOWN, INPUT);
    pinMode(SELECT, INPUT);
    pinMode(START, INPUT);
}

u8 Pines::update(){
    u8 datos = digitalRead(RIGHT)+(digitalRead(LEFT)<<1)+(digitalRead(DOWN)<<2)+(digitalRead(UP)<<3)+(digitalRead(START)<<4)+(digitalRead(SELECT)<<5)+(digitalRead(B)<<6)+(digitalRead(A)<<7)+;
    return datos;
}*/
