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
    //Registros
    u8 A = 0x00;
    u8 X = 0x00;
    u8 Y = 0x00;
    u8 SP = 0xFF;
    memoryAdr PC;
    u8 flags = FLAG_RESET;
    
    RAM* ram;
    
    int instr_longitud[256] = { //incluyendo opcode
        //0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
        2,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,// 0
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// 1
        3,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,// 2
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// 3
        2,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,// 4
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// 5
        1,2,1,2,2,2,2,2,1,2,1,2,3,3,3,3,// 6
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// 7
        2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,// 8
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// 9
        2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,// A
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// B
        2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,// C
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// D
        2,2,2,2,2,2,2,2,1,2,1,2,3,3,3,3,// E
        2,2,1,2,2,2,2,2,1,3,1,3,3,3,3,3,// F
    };
    int cycleCount[256] = { //ciclos de ins incluyendo opcode
        //0,1,2,3,4,5,6,7,8,9,A,B,C,D,E,F
        7,6,1,8,3,3,5,5,3,2,2,2,4,4,6,6,// 0
        2,5,1,8,4,4,6,6,2,4,2,7,4,4,7,7,// 1
        6,6,1,8,3,3,5,5,4,2,2,2,4,4,6,6,// 2
        2,5,1,8,4,4,6,6,2,4,2,7,4,4,7,7,// 3
        6,6,1,8,3,3,5,5,3,2,2,2,3,4,6,6,// 4
        2,5,1,8,4,4,6,6,2,4,2,7,4,4,7,7,// 5
        6,6,1,8,3,3,5,5,4,2,2,2,5,4,6,6,// 6
        2,5,1,8,4,4,6,6,2,4,2,7,4,4,7,7,// 7
        2,6,2,6,3,3,3,3,2,2,2,2,4,4,4,4,// 8
        2,6,1,6,4,4,4,4,2,5,2,3,3,5,3,5,// 9
        2,6,2,6,3,3,3,3,2,2,2,2,4,4,4,4,// A
        2,5,1,5,4,4,4,4,2,4,2,4,4,4,4,4,// B
        2,6,2,8,3,3,5,5,2,2,2,2,4,4,6,6,// C
        2,5,1,8,4,4,6,6,2,4,2,7,4,4,7,7,// D
        2,6,2,8,3,3,5,5,2,2,2,2,4,4,6,6,// E
        2,5,1,8,4,4,6,6,2,4,2,7,4,4,7,7,// F
    };
    
    //futuro: PPU* ppu;
    
public:
    NES(RAM*);
    ~NES();
    
    //Interrupts
    void nmi();
    void irq();
    void brk();
    void reset();
    void init();
    
    //Stack
    u8 popStack();
    void pushStack(u8);
    
    //Tipos de direccionamiento, si devuelve u8 es el valor a usar, si devuelve mem es para saltos
    u8 abs(); //implementado
    u8 absX(); //implementado
    u8 absY(); //implementado
    u8 accu(); //implementado
    u8 imm();
    u8 imp();
    memoryAdr ind();
    u8 indX();
    u8 indY();
    memoryAdr rel();
    u8 zp(); //implementado
    u8 zpX(); //implementado
    u8 zpY(); //implementado
    
    void exec (u8);
    
    //Debug
    string estado();
    string eflags(u8);
    

    
private:
    //Instrucciones
    void adc(u8);
    void And(u8);
    
    //Flags y SP
    void setFlags(u8, u8);
    inline memoryAdr realSP ();
    inline bool cFlag(); //prendido true
    inline bool zFlag();
    inline bool iFlag();
    inline bool dFlag();
    inline bool bFlag();
    inline bool oFlag();
    inline bool nFlag();
    
};

#endif /* defined(__CPU__NES__) */
