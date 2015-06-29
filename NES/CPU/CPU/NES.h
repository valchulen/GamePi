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
    //Tipos de direccionamiento
    memoryAdr abs();
    memoryAdr absX();
    memoryAdr absY();
    memoryAdr accu();
    memoryAdr imm();
    memoryAdr imp();
    memoryAdr ind();
    memoryAdr indX();
    memoryAdr indY();
    memoryAdr rel();
    memoryAdr zp();
    memoryAdr zpX();
    memoryAdr zpY();
    //Instrucciones
    void exec (u8);
    void adc(memoryAdr);
    void And(memoryAdr);
    void asl(memoryAdr);
    void bcc(memoryAdr);
    void bcs(memoryAdr);
    void beq(memoryAdr);
    void bit(memoryAdr);
    void bmi(memoryAdr);
    void bne(memoryAdr);
    void bpl(memoryAdr);
    void brk(memoryAdr);
    void bvc(memoryAdr);
    void bvs(memoryAdr);
    void clc(memoryAdr);
    void cld(memoryAdr);
    void cli(memoryAdr);
    void clv(memoryAdr);
    void cmp(memoryAdr);
    void cpx(memoryAdr);
    void cpy(memoryAdr);
    void dec(memoryAdr);
    void dex(memoryAdr);
    void dey(memoryAdr);
    void eor(memoryAdr);
    void inc(memoryAdr);
    void inx(memoryAdr);
    void iny(memoryAdr);
    void jmp(memoryAdr);
    void jsr(memoryAdr);
    void lda(memoryAdr);
    void ldx(memoryAdr);
    void ldy(memoryAdr);
    void lsr(memoryAdr);
    void nop(memoryAdr);
    void ora(memoryAdr);
    void pha(memoryAdr);
    void php(memoryAdr);
    void pla(memoryAdr);
    void plp(memoryAdr);
    void rol(memoryAdr);
    void ror(memoryAdr);
    void rti(memoryAdr);
    void rts(memoryAdr);
    void sbc(memoryAdr);
    void sec(memoryAdr);
    void sed(memoryAdr);
    void sei(memoryAdr);
    void sta(memoryAdr);
    void stx(memoryAdr);
    void sty(memoryAdr);
    void tax(memoryAdr);
    void tay(memoryAdr);
    void tsx(memoryAdr);
    void txa(memoryAdr);
    void txs(memoryAdr);
    void tya(memoryAdr);
    
    //Debug
    string estado();
    string eflags(u8);
    
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
