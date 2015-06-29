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
using namespace std;

class NES {
#define C_FLAG 0x01
#define Z_FLAG 0x02
#define I_FLAG 0x04
#define D_FLAG 0x08
#define B_FLAG 0x10
#define O_FLAG 0x40
#define N_FLAG 0x80
#define FLAG_RESET Z_FLAG | I_FLAG | B_FLAG
    RAM* ram;
    u8 flags = FLAG_RESET;
    u8 A = 0x00, X = 0x00, Y = 0x00, SP=0xFF;
    memoryAdr PC;
    //futuro: PPU* ppu;
    
public:
    void exec (u8);
    void nmi();
    void irq();
    void brk();
    void reset();
    void init();
    u8 popStack();
    void pushStack(u8);
    string estado();
    string eflags(u8);
    void abs();
    void absX();
    void absY();
    void accu();
    void imm();
    void imp();
    void ind();
    void indX();
    void indY();
    void rel();
    void zp();
    void zpX();
    void zpY();
    NES(RAM*);
    ~NES();
    
private:
    void setFlags(u8);
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
