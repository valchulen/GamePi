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
#define V_FLAG 0x40
#define N_FLAG 0x80
#define FLAG_RESET I_FLAG
    //Registros
    u8 A = 0x00;
    u8 Y = 0x00;
    u8 SP = 0xFF;
    memoryAdr PC;
    u8 flags = FLAG_RESET;
    
    u8 ciclos=0;
    u8 opcode;
    
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
    u8 X = 0x00;
    
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
    
    
    void setFlags(u8, u8);
    
    //Tipos de direccionamiento--> si devuelve u8 es el valor a usar, si devuelve mem es para saltos
    memoryAdr abs(); //implementado
    memoryAdr absX(); //implementado
    memoryAdr absY(); //implementado
    u8 accu(); //implementado
    u8 imm(); //implementado
    memoryAdr ind(); //implementado
    memoryAdr indX(); //implementado
    memoryAdr indY(); //implementado
    memoryAdr rel(); //implementado
    memoryAdr zp(); //implementado
    memoryAdr zpX(); //implementado
    memoryAdr zpY(); //implementado
    
    void exec ();
    
    //Debug
    string estado();
    string eflags(u8);
    
private:
    //Instrucciones
    void adc(u8);
    void And(u8);
    void asl(memoryAdr);
    void bcc(memoryAdr);
    void bcs(memoryAdr);
    void beq(memoryAdr);
    void bit(u8);
    void bmi(memoryAdr);
    void bne(memoryAdr);
    void bpl(memoryAdr);
    void bvc(memoryAdr);
    void bvs(memoryAdr);
    void clrF(u8);
    void cmp(u8);
    void cpX(u8);
    void cpY(u8);
    void dec(memoryAdr);
    void deX();
    void deY();
    void eor(u8);
    void INC(memoryAdr); //todo con mayuscula para diferenciar de inc en types.h
    void inX();
    void inY();
    void jmp(memoryAdr);
    void jsr(memoryAdr);
    void ldA(u8);
    void ldX(u8);
    void ldY(u8);
    void lsr(memoryAdr);
    void ora(u8);
    void phA();
    void phP();
    void plA();
    void plP();
    void rol(memoryAdr);
    void ror(memoryAdr);
    void rti();
    void rts();
    void sbc(u8);
    void setF(u8);
    void stA(memoryAdr);
    void stX(memoryAdr);
    void stY(memoryAdr);
    void taX();
    void taY();
    void tsX();
    void txA();
    void txS();
    void tyA();
        
    
    //Flags y SP
    inline memoryAdr realSP ();
    inline bool cFlag(); //prendido true
    inline bool zFlag();
    inline bool iFlag();
    inline bool dFlag();
    inline bool bFlag();
    inline bool oFlag();
    inline bool nFlag();
    
    inline u8 cFlag(int); //devuelve 0x00 o C_FLAG dependiendo de la entrada
    inline u8 zFlag(int);
    inline u8 nFlag(int);
};

#endif /* defined(__CPU__NES__) */
