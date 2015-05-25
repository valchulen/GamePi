//
//  Types.cpp
//  RAM
//
//  Created by Valentin Paz Marcolla on 25/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include "Types.h"
#include <iostream>

using namespace std;

string hex (u8 val){
    string nibbles[2];
    for (int i = 1; i < 3; i++) {
        char v = '0';
        switch (val<<(i*4) & 0x00FF) { // revisar que esté bien la operación
            case 0x1:
                v = '1';
                break;
            case 0x2:
                v = '2';
                break;
            case 0x3:
                v = '3';
                break;
            case 0x4:
                v = '4';
                break;
            case 0x5:
                v = '5';
                break;
            case 0x6:
                v = '6';
                break;
            case 0x7:
                v = '7';
                break;
            case 0x8:
                v = '8';
                break;
            case 0x9:
                v = '9';
                break;
            case 0xA:
                v = 'A';
                break;
            case 0xB:
                v = 'B';
                break;
            case 0xC:
                v = 'C';
                break;
            case 0xD:
                v = 'D';
                break;
            case 0xE:
                v = 'E';
                break;
            case 0xF:
                v = 'F';
                break;
        }
        nibbles[i-1] = v;
    }
    return nibbles[0] + nibbles[1];
}