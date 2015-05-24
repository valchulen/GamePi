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
    u8 RAM_D[0x800];
    //Zona de REGS-V
    u8 R_2000 = 0x00;
    u8 R_2001 = 0x00;
    u8 R_2002 = 0x00;
    u8 R_2003 = 0x00;
    u8 R_2004 = 0x00;
    u8 R_2005 = 0x00;
    u8 R_2006 = 0x00;
    u8 R_2007 = 0x00;
    //Fin de zona de REGS-V
    //Zona de REGS-A
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
    //Fin de zona de REGS-A
    u8 UNK[0x3FE9];
    u8 PRG1[0x4000];
    u8 PRG2[0x4000];
    
public:
    u8 read (memoryAdr adr);
    void write (memoryAdr adr, u8 val);
    //RAM(); //Hay que agregar Format como argumento cuando exista
};

#endif /* defined(__RAM__RAM__) */
