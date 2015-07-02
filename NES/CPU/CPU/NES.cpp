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

NES::NES(RAM* ram){
    this->ram = ram;
}

NES::~NES() {
    
}

void NES::exec(u8 instru) {
    
    switch (instru) {
            
        //-----ADC------
        case 0x61:
            adc(indX());
            break;
        case 0x65:
            adc(zp());
            break;
        case 0x69:
            adc(imm());
            break;
        case 0x6D:
            adc(abs());
            break;
        case 0x71:
            adc(indY());
            break;
        case 0x75:
            adc(zpX());
            break;
        case 0x79:
            adc(absY());
            break;
        case 0x7D:
            adc(absX());
            break;
            
        //-----AND-----
        case 0x21:
            And(indX());
            break;
        case 0x25:
            And(zp());
            break;
        case 0x29:
            And(imm());
            break;
        case 0x2D:
            And(abs());
            break;
        case 0x31:
            And(indY());
            break;
        case 0x35:
            And(zpX());
            break;
        case 0x3D:
            And(absX());
            break;
        case 0x39:
            And(absY());
            break;
            
        //----ASL-----
        case 0x0A:
            asl(accu());
            break;
        case 0x06:
            asl(zp());
            break;
        case 0x16:
            asl(zpX());
            break;
        case 0x0E:
            asl(abs());
            break;
        case 0x1E:
            asl(absX());
            break;
            
        //-----BIT-----
        case 0x24:
            bit(zp());
            break;
        case 0x2C:
            bit(abs());
            break;
            
        //----Break----
        case 0x00:
            brk();
            break;
            
        default:
            cout<<"Opcode 0x"<<hex(instru)<<" no implementado o inexistente"<<endl;
        break;
    }
}


//---Intrucciones---
void NES::adc(u8 val) {
    const u8 n = val;
    this->A=0x15;//borrar
    if (!dFlag()){
        const unsigned temp=n+ this->A +(u8)cFlag();
        this->A=temp & 0xFF;
    }
    else{
        const unsigned temp= BCDtou8(u8toBCD(n)+ u8toBCD(this->A)+(u8)cFlag());
        this->A=temp & 0xFF;
    }

}
void NES::And(u8 val) {
    this->A=0x09;//borrar
    val=0xFF;
 
    this->A&=val;
}
void NES::bit(u8 val){
    //this->A & val --> con esto prende el flag de 0 si es 0
    //val & 0x40;	//Copia al 6to bit al 6to de flags
    //val & 0x80;   //Copia el 7mo bit al 7mo de flags
}


//---Tipos de direccionamiento---
u8 NES::abs(){ //testeada
    //u8 low = ram->read( this->PC ); //es en little endian
    //u8 high = ram->read( inc(&this->PC) );
    const memoryAdr mem = intToMem(ram->read(this->PC) | (ram->read( inc(&this->PC) )<<8) ); //concateno en este orden para que el low se haga primero por el little endian
    _inc(&this->PC);
    
    return ram->read( mem );
}

u8 NES::absX(){ //testeada
    const memoryAdr mem = intToMem((ram->read(this->PC) | (ram->read( inc(&this->PC) )<<8))  + this->X); //la misma logica que con abs + x, no hago wraping porque intToMem interpreta 16 bits max
    _inc(&this->PC);
    return ram->read(mem);
}

u8 NES::absY(){ //testeada, misma logica que  absX
    const memoryAdr mem = intToMem((ram->read(this->PC) | (ram->read( inc(&this->PC) ) <<8) )  + this->Y);
    _inc(&this->PC);
    return ram->read(mem);

}

u8 NES::accu(){
    return this->A;
}

u8 NES::imm(){ //testeada
    const u8 val = ram->read(this->PC);
    _inc(&this->PC);
    return val;
}

memoryAdr NES::ind(){
    return intToMem(0x00);
}

u8 NES::indX(){
    return 0x00;
}

u8 NES::indY(){
    return 0x00;
}

memoryAdr NES::rel(){
    return intToMem(0x00);
}

u8 NES::zp(){ //Esta testeado
    const u8 val = ram->read( intToMem(this->PC.adrLow) ); //me quedo nada mas con adrLow, es como hacer un and
    _inc(&this->PC);
    return val;
}

u8 NES::zpX(){ //esta testeado
    const u8 val = ram->read( intToMem( (this->PC.adrLow + X)  & 0xFF) ); //hago lo mismo que con zp, sumando x y wrapeando porque no puedo estar seguro de que la suma da lindo
    _inc(&this->PC);
    return val;
}

u8 NES::zpY(){ //esta testeado
    const u8 val = ram->read( intToMem( (this->PC.adrLow + Y)  & 0xFF) ); //hago lo mismo que con zp, sumando y y wrapeando porque no puedo estar seguro de que la suma da lindo
    _inc(&this->PC);
    return val;
}

//---Interrupciones---

void NES::nmi(){
    setFlags(I_FLAG, I_FLAG);
    pushStack(PC.adrHigh); // i en 1
    pushStack(PC.adrLow);
    pushStack(flags);
    
    u8 v1=0x33;
    u8 v2=0x44;
    ram->write(intToMem(0x2001),v1);
    ram->write(intToMem(0x2000), v2);
    this->PC = intToMem((ram->read(intToMem(0x2001)) << 8) | ram->read(intToMem(0x2000)));//para debug
    
    //this->PC = intToMem((ram->read(intToMem(0xFFFB)) << 8) | ram->read(intToMem(0xFFFA)));
}

void NES::irq(){
    setFlags(0x00 | I_FLAG, I_FLAG | B_FLAG); // b en 0, i en 1
    pushStack(PC.adrHigh);
    pushStack(PC.adrLow);

    pushStack(flags);
    this->PC = intToMem((ram->read(intToMem(0xFFFF)) << 8) | ram->read(intToMem(0xFFFE)));
}
void NES::brk(){
    PC=intToMem((memToInt(PC)+2)); //Sumo 2 a PC asi pushea la siguiente instruccion.
    pushStack(PC.adrHigh); //cuidado aca
    pushStack(PC.adrLow); //idem arriba
    setFlags(I_FLAG | B_FLAG, I_FLAG | B_FLAG);// be en 1, i en 1
    pushStack(flags);
    this->PC = intToMem((ram->read(intToMem(0xFFFF)) << 8) | ram->read(intToMem(0xFFFE)));
}

void NES::reset(){
    this->PC = intToMem((ram->read(intToMem(0xFFFD)) << 8) | ram->read(intToMem(0xFFFC)));
}

void NES::init(){
    //Borrar memoria
    this->A=0x00;
    this->X=0x00;
    this->Y=0x00;
    this->SP=0xFF;
    this->flags = FLAG_RESET;
    this->PC = intToMem((ram->read(intToMem(0xFFFD)) << 8) | ram->read(intToMem(0xFFFC)));
}

//---Stack---

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

//---Debug---

string NES::estado(){
    return "A: 0x"+hex(this->A)+ " X: 0x"+hex(this->X)+ " Y: 0x"+hex(this->Y)+ " Stack: 0x1"+hex(this->SP)+" PC: 0x"+hex(this->PC.adrHigh)+hex(this->PC.adrLow)+" Status: 0x"+ eflags(flags);
}

string NES::eflags(u8 flag){
    return "\n Negative flag: "+hex(flag>>7&0x01)+" \n Overflow Flag: "+ hex(flag>>6&0x01) +" \n Break Flag: "+ hex(flag>>4&0x01) +" \n Decimal Flag: "+ hex(flag>>3&0x01) +" \n Interrupt Flag: "+ hex(flag>>2&0x01) +" \n Zero Flag: "+ hex(flag>>1&0x01) +"\n Carry Flag: "+ hex(flag&0x01) +"\n";
}

void NES::setFlags(u8 flags, u8 flagsToSet){
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

inline memoryAdr NES::realSP() {
    return intToMem((0x01<<8) | (this->SP & 0xFF)); //quedaria concatenado el adrLow con el SP wrapeado en adrLow
}
