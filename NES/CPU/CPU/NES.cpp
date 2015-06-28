//
//  NES.cpp
//  CPU
//
//  Created by Valentin Paz Marcolla on 12/6/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include "NES.h"
#include "Types.h"
using namespace std;

void NES::exec(u8 intru) {
    
}

void NES::nmi(){
    
}

void NES::irq(){
    
}

void NES::reset(){
    this->PC = intToMem(0x8000-1);
    this->A=0x00;
    this->X=0x00;
    this->Y=0x00;
    this->X=0xFF;
    this->flags = FLAG_RESET;
}

string NES::estado(){
    return "A: 0x"+hex(this->A)+ " X: 0x"+hex(this->A)+ " Y: 0x"+hex(this->A)+ " Stack: 0x1"+hex(this->SP)+" PC: 0x"+hex(this->PC.adrHigh)+hex(this->PC.adrLow)+" Status: 0x"+ hex(this->flags);
}

inline memoryAdr NES::realSP() { //hay que reducirlo
    memoryAdr adr;
    adr.adrHigh = 0x01;
    adr.adrLow = this->SP & 0xFF;
    return adr;
}

inline void NES::setFlags(u8 flags, u8 flagsToSet){ //verificar que funcione
    this->flags = (flags & flagsToSet) | (flags & this->flags) | ( ~(flags | flagsToSet) & this->flags) ;
}

inline bool NES::cFlag() {
    return (this->flags & C_FLAG);
}

inline bool NES::zFlag() {
    return (this->flags & Z_FLAG);
}

inline bool NES::iFlag() {
    return (this->flags & I_FLAG);
}

inline bool NES::dFlag() {
    return (this->flags & D_FLAG);
}

inline bool NES::bFlag() {
    return (this->flags & B_FLAG);
}

inline bool NES::oFlag() {
    return (this->flags & O_FLAG);
}

inline bool NES::nFlag() {
    return (this->flags & N_FLAG);
}
NES::NES(RAM* ram){
    reset();
    this->ram = ram;
}
NES::~NES() {
}