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
        //zona de registros horrible
    } else if (REGS_A_START <= adrInt && adrInt <= REGS_A_END) {
        //zona de registros directo de APU
    } else if (UNK_START <= adrInt && adrInt <= UNK_END) {
        //zona de UNK
    } else if (PRG1_START <= adrInt && adrInt <= PRG2_END) {
        //zona de PRG1
    } else {
        if (PRG2_mirror)
            //zona de PRG2 con mascara
        else
            //zona de PRG2 sin mascara
    }
    return ret;
}

RAM::RAM (){
    //seteo RAM_D en 0x00 primero
    for (int i = 0; i < RAM_D_SIZE; i++) {
        RAM_D[i] = 0x00;
    }
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

