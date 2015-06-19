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
    return "A: "+hex(this->A)+ " X: "+hex(this->A)+ " Y: "+hex(this->A)+ " Stack: 1"+hex(this->SP)+" PC: "+hex(this->PC.adrHigh)+hex(this->PC.adrLow);
}

inline memoryAdr NES::realSP() { //hay que reducirlo
    memoryAdr adr;
    adr.adrHigh = 0x01;
    adr.adrLow = this->SP & 0xFF;
    return adr;
}

void NES::setFlags(u8 flagsToSet, u8 res, bool carry){
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