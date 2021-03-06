//
//  Types.h
//  RAM
//
//  Created by Valentin Paz Marcolla on 24/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#ifndef RAM_Types_h
#define RAM_Types_h

#import <iostream>

typedef unsigned char u8;
typedef struct {
    u8 adrHigh = 0, adrLow = 0;
} memoryAdr;
typedef u8 * realMemory;


char h (u8);
std::string hex (u8);
u8 toU8(const char *);
u8 toU8(const char, const char);
int memToInt(memoryAdr);
memoryAdr intToMem (int);
void _inc (memoryAdr*); // seria un ++ con memoryAdr
memoryAdr inc (memoryAdr*); // idem el de arriba pero devuelve el valor
u8 u8toBCD(u8);
u8 BCDtou8(u8);

#endif
