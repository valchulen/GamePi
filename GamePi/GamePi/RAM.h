//
//  RAM.h
//  RAM
//
//  Created by Valentin Paz Marcolla on 24/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#ifndef __RAM__RAM__
#define __RAM__RAM__
#include "Types.h"
#include <iostream>

class RAM {
#define RAM_D_SIZE 0x800
#define RAM_D_START 0x000
#define RAM_D_MASK 0x7FF
    u8 RAM_D[RAM_D_SIZE];
#define RAM_D_END 0x1FFF
    
#define REGS_V_START 0x2000
#define REGS_V_MASK 0x007
    u8 R_2000 = 0x00;
    u8 R_2001 = 0x00;
    u8 R_2002 = 0x00;
    u8 R_2003 = 0x00;
    u8 R_2004 = 0x00;
    u8 R_2005 = 0x00;
    u8 R_2006 = 0x00;
    u8 R_2007 = 0x00;
#define REGS_V_END 0x3FFF
    
#define REGS_A_START 0x4000
#define REGS_A_MASK 0x17
    u8 A_4000 = 0x00;
    u8 A_4001 = 0x00;
    u8 A_4002 = 0x00;
    u8 A_4003 = 0x00;
    u8 A_4004 = 0x00;
    u8 A_4005 = 0x00;
    u8 A_4006 = 0x00;
    u8 A_4007 = 0x00;
    u8 A_4008 = 0x00;
    u8 A_4009 = 0x00;
    u8 A_400A = 0x00;
    u8 A_400B = 0x00;
    u8 A_400C = 0x00;
    u8 A_400D = 0x00;
    u8 A_400E = 0x00;
    u8 A_400F = 0x00;
    u8 A_4010 = 0x00;
    u8 A_4011 = 0x00;
    u8 A_4012 = 0x00;
    u8 A_4013 = 0x00;
    u8 A_4014 = 0x00;
    u8 A_4015 = 0x00;
    u8 A_4016 = 0x00;
    u8 A_4017 = 0x00;
#define REGS_A_END 0x4017

#define UNK_SIZE 0x3FE9
#define UNK_START 0x4018
    u8 UNK[UNK_SIZE]; //NUCLEA EXPA Y SRAM
#define UNK_END 0x7FFF
    
#define PRG1_SIZE 0x4000
#define PRG1_START 0x8000
    u8 PRG1[PRG1_SIZE];
#define PRG1_END 0xBFFF
    
#define PRG2_SIZE 0x4000
#define PRG2_START 0xC000
#define PRG2_TO_PRG2_MASK 0x7FFF
    u8 PRG2[PRG2_SIZE];
#define PRG2_END 0xFFFF
    
public:
    bool PRG2_mirror = true;
    u8 read (memoryAdr adr);
    void write (memoryAdr adr, u8 val); // devuelve true si se pudo escribir
    realMemory toRealAdr (memoryAdr adr);
    RAM();
    
    bool canWriteToPRG = true;
    
private:
    void setup();
};

#endif /* defined(__RAM__RAM__) */
