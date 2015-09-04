//
//  RAM.cpp
//  RAM
//
//  Created by Valentin Paz Marcolla on 24/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include "RAM.h"
#include "Types.h"
#include <iostream>
using namespace std;

u8 RAM::read(memoryAdr adr){
    return *( this->toRealAdr(adr) );
}

bool RAM::write(memoryAdr adr, u8 val){
    if (adr.adrHigh < 0x80) //no dejo escribir las zonas de PRG
        *( this->toRealAdr(adr) ) = val;
    else return false;
    return true;
}

realMemory RAM::toRealAdr(const memoryAdr adr){
    const int adrInt = memToInt(adr);
    realMemory ret = NULL;
    if (adrInt <= RAM_D_END) { //verificar el limite superior
        ret = &this->RAM_D[adrInt & RAM_D_MASK];
    } else if (REGS_V_START <= adrInt && adrInt <= REGS_V_END) {
        const int fAdrInt = adrInt & REGS_V_MASK;
        switch (fAdrInt & 0xF) {
            case 0x0:
                ret = &R_2000;
                break;
            case 0x1:
                ret = &R_2001;
                break;
            case 0x2:
                ret = &R_2002;
                break;
            case 0x3:
                ret = &R_2003;
                break;
            case 0x4:
                ret = &R_2004;
                break;
            case 0x5:
                ret = &R_2005;
                break;
            case 0x6:
                ret = &R_2006;
                break;
            case 0x7:
                ret = &R_2007;
                break;
        }
    } else if (REGS_A_START <= adrInt && adrInt <= REGS_A_END) {
        switch (adrInt & REGS_A_MASK) {
            case 0x00:
                ret = &A_4000;
                break;
            case 0x01:
                ret = &A_4001;
                break;
            case 0x02:
                ret = &A_4002;
                break;
            case 0x03:
                ret = &A_4003;
                break;
            case 0x04:
                ret = &A_4004;
                break;
            case 0x05:
                ret = &A_4005;
                break;
            case 0x06:
                ret = &A_4006;
                break;
            case 0x07:
                ret = &A_4007;
                break;
            case 0x08:
                ret = &A_4008;
                break;
            case 0x09:
                ret = &A_4009;
                break;
            case 0x0A:
                ret = &A_400A;
                break;
            case 0x0B:
                ret = &A_400B;
                break;
            case 0x0C:
                ret = &A_400C;
                break;
            case 0x0D:
                ret = &A_400D;
                break;
            case 0x0E:
                ret = &A_400E;
                break;
            case 0x0F:
                ret = &A_400F;
                break;
            case 0x10:
                ret = &A_4010;
                break;
            case 0x11:
                ret = &A_4011;
                break;
            case 0x12:
                ret = &A_4012;
                break;
            case 0x13:
                ret = &A_4013;
                break;
            case 0x14:
                ret = &A_4014;
                break;
            case 0x15:
                ret = &A_4015;
                break;
            case 0x16:
                ret = &A_4016;
                break;
            case 0x17:
                ret = &A_4017;
                break;
        }
    } else if (UNK_START <= adrInt && adrInt <= UNK_END) {
        const int fAdrInt = adrInt - UNK_START;
        ret = &UNK[fAdrInt];
    } else if (PRG1_START <= adrInt && adrInt <= PRG1_END) {
        const int fAdrInt = adrInt - PRG1_START;
        ret = &PRG1[fAdrInt];
    } else {
        const int fAdrInt = adrInt - PRG2_START;
        if (PRG2_mirror)
            ret = &PRG1[fAdrInt];
        else
            ret = &PRG2[fAdrInt];
    }
    return ret;
}

RAM::RAM(Input* i) {
    setup();
    int init = 0x00;
    for (; init < i->prg_16_rom * 16384 && init < PRG1_SIZE; init++) {
        PRG1[init] = i->prg_rom[init];
    }
    for (; init < i->prg_16_rom * 16384 && init < PRG1_SIZE + PRG1_SIZE; init++) {
        this->PRG2_mirror = false;
        PRG2[init - PRG1_SIZE] = i->prg_rom[init];
    }
}

void RAM::setup() {
    
    //seteo RAM_D en 0x00 primero
    for (int i = 0; i < RAM_D_SIZE; i++) {
        RAM_D[i] = 0x00;
    }
    RAM_D[0x08] = 0xF7;
    RAM_D[0x09] = 0xEF;
    RAM_D[0x0A] = 0xDF;
    RAM_D[0x0F] = 0xBF;
    //seteo UNK en 0x00 primero
    for (int i = 0; i < UNK_SIZE; i++) {
        UNK[i] = 0x00;
    }
    //seteo PRG1 en 0x00 primero
    for (int i = 0; i < PRG1_SIZE; i++) {
        PRG1[i] = 0x00;
    }
    //seteo PRG2 en 0x00 primero
    for (int i = 0; i < PRG2_SIZE; i++) {
        PRG2[i] = 0x00;
    }

}

RAM::RAM (){
    setup();
}

