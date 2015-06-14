//
//  NES.h
//  CPU
//
//  Created by Valentin Paz Marcolla on 12/6/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#ifndef __CPU__NES__
#define __CPU__NES__

#include <stdio.h>
#include "RAM.h"
#include "Types.h"

class NES {
#define C_FLAG 0x01
#define Z_FLAG 0x02
#define I_FLAG 0x04
#define D_FLAG 0x08
#define B_FLAG 0x10
#define O_FLAG 0x40
#define N_FLAG 0x80
    RAM* ram;
    u8 flags = 0x00;
    u8 A = 0x00, X = 0x00, Y = 0x00, SP;
    memoryAdr PC;
    //futuro: PPU* ppu;
    
public:
    void exec (u8);
    NES(RAM*);
    ~NES();
    
private:
    void setFlags(u8, u8, bool);
    inline memoryAdr realSP ();
    inline bool cFlag();
    inline bool zFlag();
    inline bool iFlag();
    inline bool dFlag();
    inline bool bFlag();
    inline bool oFlag();
    inline bool nFlag();
    
};

#endif /* defined(__CPU__NES__) */
