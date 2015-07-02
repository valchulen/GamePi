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
            
        //-----BRK-----
        case 0x00:
            brk();
            break;
            
        //-----ClrF-----
        case 0x18:
            clrF(C_FLAG);
            break;
        case 0xD8:
            clrF(D_FLAG);
            break;
        case 0x58:
            clrF(I_FLAG);
            break;
        case 0xB8:
            clrF(O_FLAG);
            break;
            
        //----CMP-----
        case 0xC9:
            cmp(imm());
            break;
        case 0xC5:
            cmp(zp());
            break;
        case 0xD5:
            cmp(zpX());
            break;
        case 0xCD:
            cmp(abs());
            break;
        case 0xDD:
            cmp(absX());
            break;
        case 0xD9:
            cmp(absY());
            break;
        case 0xC1:
            cmp(indX());
            break;
        case 0xD1:
            cmp(indY());
            break;
            
        //-----CPX-----
        case 0xE0:
            cpX(imm());
            break;
        case 0xE4:
            cpX(zp());
            break;
        case 0xEC:
            cpX(abs());
            break;
            
        //-----CPY-----
        case 0xC0:
            cpY(imm());
            break;
        case 0xC4:
            cpY(zp());
            break;
        case 0xCC:
            cpY(abs());
            break;
            
        //-----DEX-----
        case 0xCA:
            deX(imp());
            break;
            
        //-----DEY-----
        case 0x88:
            deY(imp());
            break;
        
        //-----EOR-----
        case 0x49:
            eor(imm());
            break;
        case 0x45:
            eor(zp());
            break;
        case 0x55:
            eor(zpX());
            break;
        case 0x40:
            eor(abs());
            break;
        case 0x50:
            eor(absX());
            break;
        case 0x59:
            eor(absY());
            break;
        case 0x41:
            eor(indX());
            break;
        case 0x51:
            eor(indY());
            break;
            
        //-----INX-----
        case 0xE8:
            inX(imp());
            break;
            
        //-----INY-----
        case 0xC8:
            inY(imp());
            
        //-----LDA-----
        case 0xA9:
            ldA(imm());
            break;
        case 0xA5:
            ldA(zp());
            break;
        case 0xB5:
            ldA(zpX());
            break;
        case 0xAD:
            ldA(abs());
            break;
        case 0xBD:
            ldA(absX());
            break;
        case 0xB9:
            ldA(absY());
            break;
        case 0xA1:
            ldA(indX());
            break;
        case 0xB1:
            ldA(indY());
            break;
            
        //-----LDX-----
        case 0xA2:
            ldX(imm());
            break;
        case 0xA6:
            ldX(zp());
            break;
        case 0xB6:
            ldX(zpY());
            break;
        case 0xAE:
            ldX(abs());
            break;
        case 0xBE:
            ldX(absY());
            break;
            
        //-----LDX-----
        case 0xA0:
            ldY(imm());
            break;
        case 0xA4:
            ldY(zp());
            break;
        case 0xB4:
            ldY(zpX());
            break;
        case 0xAC:
            ldY(abs());
            break;
        case 0xBC:
            ldY(absX());
            break;
            
        //-----NOP-----
        case 0xEA:
            break;
            
        //-----ORA-----
        case 0x09:
            ora(imm());
            break;
        case 0x05:
            ora(zp());
            break;
        case 0x15:
            ora(zpX());
            break;
        case 0x0D:
            ora(abs());
            break;
        case 0x1D:
            ora(absX());
            break;
        case 0x19:
            ora(absY());
            break;
        case 0x01:
            ora(indX());
            break;
        case 0x11:
            ora(indY());
            break;
            
        //-----PHA-----
        case 0x48:
            phA(imp());
            break;
            
        //-----PHP-----
        case 0x08:
            phP(imp());
            break;
            
        //----PLA-----
        case 0x68:
            plA(imp());
            break;
            
        //-----PLP-----
        case 0x28:
            plP(imp());
            break;
            
        //-----RTI-----
        case 0x4D:
            rti(imp());
            break;
            
        //-----RTS-----
        case 0x60:
            rts(imp());
            break;
        //-----SBC-----
        case 0xE9:
            sbc(imm());
            break;
        case 0xE5:
            sbc(zp());
            break;
        case 0xF5:
            sbc(zpX());
            break;
        case 0xED:
            sbc(abs());
            break;
        case 0xFD:
            sbc(absX());
            break;
        case 0xF9:
            sbc(absY());
            break;
        case 0xE1:
            sbc(indX());
            break;
        case 0xF1:
            sbc(indY());
            break;
            
        //----SetF-----
        case 0x38:
            setF(C_FLAG);
            break;
        case 0xF8:
            setF(D_FLAG);
            break;
        case 0x78:
            setF(I_FLAG);
            break;
        
        //-----TAX-----
        case 0xAA:
            taX(imp());
            break;
            
        //-----TAY-----
        case 0xA8:
            taY(imp());
            break;
            
        //-----TSX-----
        case 0xBA:
            tsX(imp());
            break;
            
        //-----TXA-----
        case 0x8A:
            txA(imp());
            break;
            
        //-----TXS-----
        case 0x9A:
            txS(imp());
            break;
            
        //-----TYA-----
        case 0x98:
            tyA(imp());
            break;
        
            
        
        default:
            cout<<"Opcode 0x"<<hex(instru)<<" no implementado o inexistente"<<endl;
        break;
    }
}


//---Intrucciones---
void NES::adc(u8 val) {
    this->A=0x15;//borrar
    if (!dFlag()){
        const unsigned temp=val+ this->A +(u8)cFlag();
        this->A=temp & 0xFF;
    }
    else{
        const unsigned temp= BCDtou8(u8toBCD(val)+ u8toBCD(this->A)+(u8)cFlag());
        this->A=temp & 0xFF;
    }

}
void NES::And(u8 val) {
    this->A=0x09;//borrar
    this->A&=val;
}
void NES::asl(u8 val){
    
}
void NES::bit(u8 val){
    //this->A & val --> con esto prende el flag de 0 si es 0
    //val & 0x40;	//Copia al 6to bit al 6to de flags
    //val & 0x80;   //Copia el 7mo bit al 7mo de flags
}
void NES::clrF(u8 val){
    // setea en 0 el que te llega
}
void NES::cmp(u8 val){
    int temp= this->A -val;
    //setea N,Zy C
}
void NES::cpX(u8 val){
    int temp= this->X -val;
    //setea N,Zy C
}
void NES::cpY(u8 val){
    int temp= this->Y -val;
    //setea N,Zy C
}
void NES::deX(u8 val){
    int temp =this->X-1;
    this->X=temp&0xFF;
}
void NES::deY(u8 val){
    int temp =this->Y-1;
    this->Y=temp&0xFF;
}
void NES::eor(u8 val){
    this->A^=val;
}
void NES::inX(u8 val){
    int temp =this->X+1;
    this->X=temp&0xFF;
}
void NES::inY(u8 val){
    int temp =this->X+1;
    this->X=temp&0xFF;
}
void NES::ldA(u8 val){
    this->A=val;
}
void NES::ldX(u8 val){
    this->X=val;
}
void NES::ldY(u8 val){
    this->Y=val;
}
void NES::ora(u8 val){
    this->A|=val;
}
void NES::phA(u8 val){
    pushStack(this->A);
}
void NES::phP(u8 val){
    pushStack(flags);
}
void NES::plA(u8 val){
    this->A=popStack();
    //Cambiar flags de Z Y N
}
void NES::plP(u8 val){
    this->flags=popStack();
}
void NES::rti(u8 val){
    this->flags=popStack();
    this->PC.adrLow=popStack();
    this->PC.adrHigh=popStack();
}
void NES::rts(u8 val){
    this->PC.adrLow=popStack();
    this->PC.adrHigh=popStack();
    PC=intToMem((memToInt(PC)+1));
}
void NES::sbc(u8 val){
    if (!dFlag()){
        const unsigned temp=this->A-  val -(cFlag() ? 0 : 1);
        this->A=temp & 0xFF;
    }
    else{
        const unsigned temp= BCDtou8(u8toBCD(this->A)- u8toBCD(val)-(cFlag() ? 0 : 1));
        this->A=temp & 0xFF;
    }
}
void NES::setF(u8 val){
    //setea flag que llega en 1
}
void NES::taX(u8 val){
    this->X=this->A;
}
void NES::taY(u8 val){
    this->Y=this->A;
}
void NES::tsX(u8 val){
    this->X=this->SP;
}
void NES::txA(u8 val){
    this->A=this->X;
}
void NES::txS(u8 val){
    this->SP=this->X;
}
void NES::tyA(u8 val){
    this->A=this->Y;
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
u8 NES::imp(){
    return 0x00;
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
