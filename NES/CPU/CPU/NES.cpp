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
    pushStack(PC.adrHigh);
    pushStack(PC.adrLow);
    pushStack(flags);
    //disble interrupt flag ?
    
    u8 v1=0x33;
    u8 v2=0x44;
    ram->write(intToMem(0x2001),v1);
    ram->write(intToMem(0x2000), v2);
    this->PC = intToMem((ram->read(intToMem(0x2001)) << 8) | ram->read(intToMem(0x2000)));//para debug
    
    //this->PC = intToMem((ram->read(intToMem(0xFFFB)) << 8) | ram->read(intToMem(0xFFFA)));
}

void NES::irq(){
    pushStack(PC.adrHigh);
    pushStack(PC.adrLow);
    //b flag en 0
    //disble interrupt flag ?
    pushStack(flags);
    this->PC = intToMem((ram->read(intToMem(0xFFFF)) << 8) | ram->read(intToMem(0xFFFE)));
}
void NES::brk(){
    //b flag en 1
    //disble interrupt flag ?
    irq();
}
void NES::reset(){
    //PC.adrLow=ram->read(intToMem(0xFFFC));
    //PC.adrHigh=ram->read(intToMem(0xFFFD));
    this->PC = intToMem((ram->read(intToMem(0xFFFD)) << 8) | ram->read(intToMem(0xFFFC)));
}
void NES::init(){
    /*//Borar memoria
    this->A=0x00;
    this->X=0x00;
    this->Y=0x00;
    this->SP=0xFF;
    this->flags = FLAG_RESET;
    this->PC = intToMem((ram->read(intToMem(0xFFFD)) << 8) | ram->read(intToMem(0xFFFC)));*/
}
u8 NES::popStack(){
    ++SP;
    SP &= 0xff;
    return ram->read(intToMem(0x100 + SP));
}
void NES::pushStack(u8 val){
    ram->write(intToMem((0x100 + (SP & 0xff))), val);
    SP--;
    SP &= 0xff;
}
string NES::estado(){
    return "A: "+hex(this->A)+ " X: "+hex(this->X)+ " Y: "+hex(this->Y)+ " Stack: 1"+hex(this->SP)+" PC: "+hex(this->PC.adrHigh)+hex(this->PC.adrLow)+" Flags: "+ eflags(flags);
}
string NES::eflags(u8 flag){
    return "\n Negative flag: "+hex(flag>>7&0x01)+" \n Overflow Flag: "+ hex(flag>>6&0x01) +" \n Break Flag: "+ hex(flag>>4&0x01) +" \n Decimal Flag: "+ hex(flag>>3&0x01) +" \n Interrupt Flag: "+ hex(flag>>2&0x01) +" \n Zero Flag: "+ hex(flag>>1&0x01) +"\n Carry Flag: "+ hex(flag&0x01) +"\n";
}
inline memoryAdr NES::realSP() { //hay que reducirlo
    memoryAdr adr;
    adr.adrHigh = 0x01;
    adr.adrLow = this->SP & 0xFF;
    return adr;
}

inline void NES::setFlags(u8 flags){
    this->flags |= flags;
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
    this->ram = ram;
}
NES::~NES() {
}