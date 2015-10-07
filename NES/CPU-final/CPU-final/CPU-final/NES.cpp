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

#define NULL_MEM 0xFFFF //memoria reservada que no se usa en las instrucciones, para meter un null.

NES::NES(RAM* ram){
    this->ram = ram;
    init();
}

NES::~NES() {
    
}

void NES::exec() {
    bool existe = true;
    this->opcode = ram->read(PC);
    if (opcode == 0x20)
        cout<<"brk"<<endl;
    _inc(&PC); //pc++
    switch (this->opcode) {
            
        //-----ADC------
        case 0x61:
            adc( ram->read( indX() ) );
            break;
        case 0x65:
            adc( ram->read( zp() ) );
            break;
        case 0x69:
            adc(imm());
            break;
        case 0x6D:
            adc( ram->read( abs() ) );
            break;
        case 0x71:
            adc( ram->read( indY() ) );
            break;
        case 0x75:
            adc( ram->read( zpX() ) );
            break;
        case 0x79:
            adc( ram->read( absY() ) );
            break;
        case 0x7D:
            adc( ram->read( absX() ) );
            break;
            
        //-----AND-----
        case 0x21:
            And( ram->read( indX() ) );
            break;
        case 0x25:
            And( ram->read( zp() ) );
            break;
        case 0x29:
            And(imm());
            break;
        case 0x2D:
            And( ram->read( abs() ) );
            break;
        case 0x31:
            And( ram->read( indY() ) );
            break;
        case 0x35:
            And( ram->read( zpX() ) );
            break;
        case 0x3D:
            And( ram->read( absX() ) );
            break;
        case 0x39:
            And( ram->read( absY() ) );
            break;
            
        //----ASL-----
        case 0x0A:
            asl(intToMem(NULL_MEM));
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
            
        //-----BCC-----
        case 0x90:
            bcc(rel());
            break;
        
        //-----BCS-----
        case 0xB0:
            bcs(rel());
            break;
            
        //-----BEQ-----
        case 0xF0:
            beq(rel());
            break;
            
        //-----BIT-----
        case 0x24:
            bit( ram->read( zp() ) );
            break;
        case 0x2C:
            bit( ram->read( abs() ) );
            break;
            
        //-----BMI-----
        case 0x30:
            bmi(rel());
            break;
            
        //-----BNE-----
        case 0xD0:
            bne(rel());
            break;
            
        //-----BPL-----
        case 0x10:
            bpl(rel());
            break;
            
        //-----BRK-----
        case 0x00:
            brk();
            break;
        
        //-----BVC-----
        case 0x50:
            bvc(rel());
            break;
        
        //-----BVS-----
        case 0x70:
            bvs(rel());
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
            cmp( ram->read( zp() ) );
            break;
        case 0xD5:
            cmp( ram->read( zpX() ) );
            break;
        case 0xCD:
            cmp( ram->read( abs() ) );
            break;
        case 0xDD:
            cmp( ram->read( absX() ) );
            break;
        case 0xD9:
            cmp( ram->read( absY() ) );
            break;
        case 0xC1:
            cmp( ram->read( indX() ) );
            break;
        case 0xD1:
            cmp( ram->read( indY() ) );
            break;
            
        //-----CPX-----
        case 0xE0:
            cpX(imm());
            break;
        case 0xE4:
            cpX( ram->read( zp() ) );
            break;
        case 0xEC:
            cpX( ram->read( abs() ) );
            break;
            
        //-----CPY-----
        case 0xC0:
            cpY(imm());
            break;
        case 0xC4:
            cpY( ram->read(zp()));
            break;
        case 0xCC:
            cpY( ram->read( abs() ) );
            break;
            
        //-----DEC-----
        case 0xC6:
            dec(zp());
            break;
        case 0xD6:
            dec(zpX());
            break;
        case 0xCE:
            dec(abs());
            break;
        case 0xDE:
            dec(absX());
            break;
            
        //-----DEX-----
        case 0xCA:
            deX();
            break;
            
        //-----DEY-----
        case 0x88:
            deY();
            break;
        
        //-----EOR-----
        case 0x49:
            eor(imm());
            break;
        case 0x45:
            eor( ram->read( zp() ) );
            break;
        case 0x55:
            eor( ram->read( zpX() ) );
            break;
        case 0x4D:
            eor( ram->read( abs() ) );
            break;
        case 0x5D:
            eor( ram->read( absX() ) );
            break;
        case 0x59:
            eor( ram->read( absY() ) );
            break;
        case 0x41:
            eor( ram->read( indX() ) );
            break;
        case 0x51:
            eor( ram->read( indY() ) );
            break;
        
        //-----INC-----
        case 0xE6:
            INC(zp());
            break;
        case 0xF6:
            INC(zpX());
            break;
        case 0xEE:
            INC(abs());
            break;
        case 0xFE:
            INC(absX());
            break;
            
        //-----INX-----
        case 0xE8:
            inX();
            break;
            
        //-----INY-----
        case 0xC8:
            inY();
            break;
            
        //-----JMP-----
        case 0x4C:
            jmp(abs());
            break;
        case 0x6C:
            jmp(ind());
            break;
            
        //-----JSR-----
        case 0x20:
            jsr(abs());
            break;
            
        //-----LDA-----
        case 0xA9:
            ldA(imm());
            break;
        case 0xA5:
            ldA( ram->read( zp() ) );
            break;
        case 0xB5:
            ldA( ram->read( zpX() ) );
            break;
        case 0xAD:
            ldA( ram->read( abs() ) );
            break;
        case 0xBD:
            ldA( ram->read( absX() ) );
            break;
        case 0xB9:
            ldA( ram->read( absY() ) );
            break;
        case 0xA1:
            ldA( ram->read( indX() ) );
            break;
        case 0xB1:
            ldA( ram->read( indY() ) );
            break;
            
        //-----LDX-----
        case 0xA2:
            ldX(imm());
            break;
        case 0xA6:
            ldX( ram->read( zp() ) );
            break;
        case 0xB6:
            ldX( ram->read( zpY() ) );
            break;
        case 0xAE:
            ldX( ram->read( abs() ) );
            break;
        case 0xBE:
            ldX( ram->read( absY() ) );
            break;
            
        //-----LDY-----
        case 0xA0:
            ldY(imm());
            break;
        case 0xA4:
            ldY( ram->read( zp() ) );
            break;
        case 0xB4:
            ldY( ram->read( zpX() ) );
            break;
        case 0xAC:
            ldY( ram->read( abs() ) );
            break;
        case 0xBC:
            ldY( ram->read( absX() ) );
            break;
            
        //-----LSR-----
        case 0x4A:
            lsr(intToMem(NULL_MEM));
            break;
        case 0x46:
            lsr(zp());
            break;
        case 0x56:
            lsr(zpX());
            break;
        case 0x4E:
            lsr(abs());
            break;
        case 0x5E:
            lsr(absX());
            break;
            
        //-----NOP-----
        case 0xEA:
            break;
            
        //-----ORA-----
        case 0x09:
            ora(imm());
            break;
        case 0x05:
            ora( ram->read( zp() ) );
            break;
        case 0x15:
            ora( ram->read( zpX() ) );
            break;
        case 0x0D:
            ora( ram->read( abs() ) );
            break;
        case 0x1D:
            ora( ram->read( absX() ) );
            break;
        case 0x19:
            ora( ram->read( absY() ) );
            break;
        case 0x01:
            ora( ram->read( indX() ) );
            break;
        case 0x11:
            ora( ram->read( indY() ) );
            break;
            
        //-----PHA-----
        case 0x48:
            phA();
            break;
            
        //-----PHP-----
        case 0x08:
            phP();
            break;
            
        //----PLA-----
        case 0x68:
            plA();
            break;
            
        //-----PLP-----
        case 0x28:
            plP();
            break;
            
        //-----ROL-----
        case 0x2A:
            rol(intToMem(NULL_MEM));
            break;
        case 0x26:
            rol(zp());
            break;
        case 0x36:
            rol(zpX());
            break;
        case 0x2E:
            rol(abs());
            break;
        case 0x3E:
            rol(absX());
            break;
            
            //-----ROR-----
        case 0x6A:
            ror(intToMem(NULL_MEM));
            break;
        case 0x66:
            ror(zp());
            break;
        case 0x76:
            ror(zpX());
            break;
        case 0x6E:
            ror(abs());
            break;
        case 0x7E:
            ror(absX());
            break;

        //-----RTI-----
        case 0x40:
            rti();
            break;
            
        //-----RTS-----
        case 0x60:
            rts();
            break;
        //-----SBC-----
        case 0xE9:
            sbc(imm());
            break;
        case 0xE5:
            sbc( ram->read( zp() ) );
            break;
        case 0xF5:
            sbc( ram->read( zpX() ) );
            break;
        case 0xED:
            sbc( ram->read( abs() ) );
            break;
        case 0xFD:
            sbc( ram->read( absX() ) );
            break;
        case 0xF9:
            sbc( ram->read( absY() ) );
            break;
        case 0xE1:
            sbc( ram->read( indX() ) );
            break;
        case 0xF1:
            sbc( ram->read( indY() ) );
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
            
        //-----STA-----
        case 0x85:
            stA(zp());
            break;
        case 0x95:
            stA(zpX());
            break;
        case 0x8D:
            stA(abs());
            break;
        case 0x9D:
            stA(absX());
            break;
        case 0x99:
            stA(absY());
            break;
        case 0x81:
            stA(indX());
            break;
        case 0x91:
            stA(indY());
            break;
        
        //-----STX-----
        case 0x86:
            stX(zp());
            break;
        case 0x96:
            stX(zpY());
            break;
        case 0x8E:
            stX(abs());
            break;
            
        //-----STY-----
        case 0x84:
            stY(zp());
            break;
        case 0x94:
            stY(zpX());
            break;
        case 0x8C:
            stY(abs());
            break;
        
        //-----TAX-----
        case 0xAA:
            taX();
            break;
            
        //-----TAY-----
        case 0xA8:
            taY();
            break;
            
        //-----TSX-----
        case 0xBA:
            tsX();
            break;
            
        //-----TXA-----
        case 0x8A:
            txA();
            break;
            
        //-----TXS-----
        case 0x9A:
            txS();
            break;
            
        //-----TYA-----
        case 0x98:
            tyA();
            break;
        
        default:
            cout<<"Opcode 0x"<<hex(this->opcode)<<" no implementado o inexistente"<<endl;
            existe=false;
        break;
    }
    if (existe)
        ciclos+=cycleCount[(u8)opcode];
}


//---Intrucciones---
void NES::adc(u8 val) {
    //this->A = 0xd0;//borrar
    //val = 0xd0;
    
    //overflow
    const u8 m = (this->A & 0x80) == 0x80 ? 0xFF : 0x00, n = (val & 0x80) == 0x80 ? 0xFF : 0x00;
    const u8 c = (this->A & val & 0x40) == 0x40 ? 0xFF : 0x00;
    const u8 v  = ( ~(m | n) & c) | (m & n & ~c);
    //fin overflow
    
    unsigned temp;
    //if (!dFlag()) {
        temp = val + this->A + (cFlag() ? 0x01 : 0x00);
    /*} else {
        temp = BCDtou8(u8toBCD(val) + u8toBCD(this->A) + (cFlag() ? 0x01 : 0x00));
        setFlags( ((temp > 0x99) ? C_FLAG : 0x00), C_FLAG);
    }*/
    
    this->A = temp & 0xFF;
    
    setFlags( ((temp > 0xFF) ? C_FLAG : 0x00) | zFlag(this->A) | nFlag(this->A) | (V_FLAG & v), C_FLAG | Z_FLAG | N_FLAG | V_FLAG);
}

void NES::And(u8 val) {
    this->A = 0xFF;//borrar
    val = 0x10;
    this->A &= val;
    setFlags(zFlag(this->A) | nFlag(this->A), Z_FLAG | N_FLAG);
}

void NES::asl(memoryAdr mem){
    u8 val;
    if (memToInt(mem) == NULL_MEM){
        val = this->A;
    } else val = ram->read(mem);
    //val=0x01;
    int temp = val<<1;
    if (memToInt(mem) == NULL_MEM){
        this->A = temp & 0xFF;
    } else
        ram->write(mem, temp & 0xFF);
    
    setFlags(cFlag(temp) | zFlag(temp & 0xFF) | nFlag(temp & 0xFF), C_FLAG | Z_FLAG | N_FLAG);
}

void NES::bcc(memoryAdr mem){
    if (!cFlag())
        this->PC = mem;
}
void NES::bcs(memoryAdr mem){
    if(cFlag())
        this->PC = mem;
}
void NES::beq(memoryAdr mem){
    if(zFlag())
        this->PC = mem;
}

void NES::bit(u8 val){
    //this->A & val --> con esto prende el flag de 0 si es 0
    //val & 0x40;	//Copia al 6to bit al 6to de flags
    //val & 0x80;   //Copia el 7mo bit al 7mo de flags
    setFlags((val & V_FLAG) | (val & N_FLAG) | zFlag(this->A & val), V_FLAG | N_FLAG | Z_FLAG);
}

void NES::bmi(memoryAdr mem){
    if(nFlag())
        this->PC=mem;
}

void NES::bne(memoryAdr mem){
    if(!zFlag())
        this->PC=mem;
}

void NES::bpl(memoryAdr mem){
    if (!nFlag())
        this->PC=mem;
}

void NES::bvc(memoryAdr mem){
    if (!cFlag())
        this->PC=mem;
}

void NES::bvs(memoryAdr mem){
    if (cFlag())
        this->PC=mem;
}

void NES::clrF(u8 val){
    setFlags(0x00, val);
}

void NES::cmp(u8 val){
    const int temp = this->A - val;
    setFlags( ((temp & 0x80) == 0x80 ? 0 : C_FLAG) | zFlag(temp & 0xFF) | nFlag(temp & 0xFF), C_FLAG | Z_FLAG | N_FLAG);
}

void NES::cpX(u8 val){
    const int temp = this->X - val;
    setFlags( ((temp & 0x80) == 0x80 ? 0 : C_FLAG) | zFlag(temp & 0xFF) | nFlag(temp & 0xFF), C_FLAG | Z_FLAG | N_FLAG);
}

void NES::cpY(u8 val){
    const int temp = this->Y - val;
    setFlags( ((temp & 0x80) == 0x80 ? 0 : C_FLAG) | zFlag(temp & 0xFF) | nFlag(temp & 0xFF), C_FLAG | Z_FLAG | N_FLAG);
}

void NES::dec(memoryAdr mem){
    u8 val = ram->read(mem);
    val--;
    setFlags(zFlag(val) | nFlag(val), Z_FLAG | N_FLAG);
    ram->write(mem, val);
}

void NES::deX(){
    const int temp = this->X - 1;
    this->X = temp & 0xFF;
    
    setFlags(zFlag(this->X)| nFlag(this->X), Z_FLAG | N_FLAG);
}

void NES::deY(){
    const int temp = this->Y - 1;
    this->Y = temp & 0xFF;
    
    setFlags(zFlag(this->Y)| nFlag(this->X), Z_FLAG | N_FLAG);
}

void NES::eor(u8 val){
    this->A ^= val;
    
    setFlags(zFlag(this->A) | nFlag(this->A), Z_FLAG | N_FLAG);
}

void NES::INC(memoryAdr mem){
    u8 val= ram->read(mem);
    val++;
    setFlags(zFlag(val) | nFlag(val), Z_FLAG | N_FLAG);
    ram->write(mem,val);
}

void NES::inX(){
    const int temp = this->X + 1;
    this->X = temp & 0xFF;
    
    setFlags(zFlag(this->X)| nFlag(this->X), Z_FLAG | N_FLAG);
}

void NES::inY(){
    const int temp = this->Y + 1;
    this->Y = temp & 0xFF;
    
    setFlags(zFlag(this->Y)| nFlag(this->Y), Z_FLAG | N_FLAG);
}

void NES::jmp(memoryAdr mem){
    this->PC = mem;
}

void NES::jsr(memoryAdr mem){
    pushStack(PC.adrHigh);
    pushStack(PC.adrLow - 1);
    this->PC = mem;
    
}

void NES::ldA(u8 val){
    this->A = val;
    
    setFlags(zFlag(val) | nFlag(val), Z_FLAG | N_FLAG);
}

void NES::ldX(u8 val){
    this->X = val;
    
    setFlags(zFlag(val) | nFlag(val), Z_FLAG | N_FLAG);
}

void NES::ldY(u8 val){
    this->Y = val;
    
    setFlags(zFlag(val) | nFlag(val), Z_FLAG | N_FLAG);
}

void NES::lsr(memoryAdr mem){
    u8 val;
    if (memToInt(mem) == NULL_MEM){
        val = this->A;
    } else val = ram->read(mem);
    //val=0xF4;
    int temp = val>>1;
    if (memToInt(mem) == NULL_MEM){
        this->A = temp & 0xFF;
    }
    else
        ram->write(mem, temp & 0xFF);
    
    setFlags( (((val & 0x01) == 0x01) ? C_FLAG : 0x00) | zFlag(temp & 0xFF), C_FLAG | Z_FLAG); //uso el ternario porque el bit 0 indica C
}

void NES::ora(u8 val){
    this->A |= val;
    
    setFlags(zFlag(this->A) | nFlag(this->A), Z_FLAG | N_FLAG);
}

void NES::phA(){
    pushStack(this->A);
}

void NES::phP(){
    pushStack(flags);
}

void NES::plA(){
    this->A = popStack();
    setFlags(zFlag(this->A) | nFlag(this->A), Z_FLAG | N_FLAG);
}

void NES::plP(){
    this->flags = popStack();
}

void NES::rol(memoryAdr mem){ //arreglado
    u8 val;
    if (memToInt(mem) == NULL_MEM){
        val = this->A;
    } else val = ram->read(mem);
    //val=0xF1;
    int temp = val<<1;
    temp += cFlag() ? 1 : 0; //correxion, si el carry esta prendido
    if (memToInt(mem) == NULL_MEM){
        this->A = temp & 0xFF;
    }
    else
        ram->write(mem, temp & 0xFF);
    
    setFlags(cFlag(temp) | zFlag(temp & 0xFF) | nFlag(temp & 0xFF), C_FLAG | Z_FLAG | N_FLAG);
}

void NES::ror(memoryAdr mem){ //Arreglado
    u8 val;
    if (memToInt(mem) == NULL_MEM){
        val = this->A;
    } else val = ram->read(mem);
    val=0xF2;
    int temp = val>>1;
    temp |= cFlag() ? 0x80 : 0x00;
    if (memToInt(mem) == NULL_MEM){
        this->A = temp & 0xFF;
    }
    else
        ram->write(mem, temp & 0xFF);
    
    setFlags( ((val & 0x01) == 0x01 ? C_FLAG : 0x00) | zFlag(temp & 0xFF)| nFlag(temp & 0xFF), C_FLAG | Z_FLAG | N_FLAG); //lo mismo que lsr
}

void NES::rti(){
    this->flags = popStack();
    this->PC.adrLow = popStack();
    this->PC.adrHigh = popStack();
}

void NES::rts(){
    this->PC.adrLow = popStack();
    this->PC.adrHigh = popStack();
    PC = intToMem(memToInt(PC) + 1);
}

void NES::sbc(u8 val){
    //int temp;
    //if (!dFlag()){
    this->A=0x50;
    val = 0x70;
    
    const int temp = this->A - val - (1-(cFlag() ? 1 : 0));
    
    
    //overflow
    const u8 vflag  = ((((this->A ^ temp) & 0x80) !=0 && ((this->A ^ val) & 0x80) !=0 ) ? V_FLAG : 0);
    //fin overflow
    
    /*} else {
        temp = BCDtou8(u8toBCD(this->A) - u8toBCD(val) - (cFlag() ? 0 : 1));
    }*/
    this->A = temp & 0xFF;
    
    setFlags( (temp < 0 ?  0x00: C_FLAG) | zFlag(this->A) | nFlag(this->A) | (vflag), C_FLAG | Z_FLAG | N_FLAG | V_FLAG);
}

void NES::setF(u8 val){
    setFlags(val, val);
}

void NES::stA(memoryAdr val){
    ram->write(val, this->A);
}

void NES::stX(memoryAdr val){
    ram->write(val, this->X);
}

void NES::stY(memoryAdr val){
    ram->write(val, this->Y);
}

void NES::taX(){
    this->X = this->A;
    setFlags(zFlag(this->A) | nFlag(this->A), Z_FLAG | N_FLAG);
}

void NES::taY(){
    this->Y = this->A;
    setFlags(zFlag(this->A) | nFlag(this->A), Z_FLAG | N_FLAG);
}

void NES::tsX(){
    this->X = this->SP;
    setFlags(zFlag(this->SP) | nFlag(this->SP), Z_FLAG | N_FLAG);
}

void NES::txA(){
    this->A = this->X;
    setFlags(zFlag(this->X) | nFlag(this->X), Z_FLAG | N_FLAG);
}

void NES::txS(){
    this->SP = this->X;
    setFlags(zFlag(this->X) | nFlag(this->X), Z_FLAG | N_FLAG);
}

void NES::tyA(){
    this->A = this->Y;
    setFlags(zFlag(this->Y) | nFlag(this->Y), Z_FLAG | N_FLAG);
}

//---Tipos de direccionamiento---
memoryAdr NES::abs(){
    const u8 low = ram->read(PC); // en este orden por little endian
    _inc(&PC);
    const u8 high = ram->read(PC); //hay un problema aca, deberia devolver 0x20 y no 0x00
    _inc(&PC);
    memoryAdr m;
    m.adrLow = low;
    m.adrHigh = high;
    //cout<<"Low:"<<hex(low)<<" High:"<<hex(high)<<endl;
    return m;
}

memoryAdr NES::absX(){ //testeada
    const memoryAdr mem = intToMem((ram->read(this->PC) | (ram->read( inc(&this->PC) )<<8))  + this->X); //la misma logica que con abs + x, no hago wraping porque intToMem interpreta 16 bits max
    _inc(&this->PC);
    return mem;
}

memoryAdr NES::absY(){ //testeada, misma logica que  absX
    const memoryAdr mem = intToMem((ram->read(this->PC) | (ram->read( inc(&this->PC) ) <<8) )  + this->Y);
    _inc(&this->PC);
    return mem;
}

u8 NES::accu(){
    return this->A;
}

u8 NES::imm(){ //testeada
    const u8 val = ram->read(this->PC);
    _inc(&this->PC);
    return val;
}

memoryAdr NES::ind(){ //ARREGLAR DESPUES DE ENTREGAR
    //saco el LSB que seria pc
    const u8 LSB = ram->read( this->PC ); //SOLO SUMA AL LSB DE PC!!!!!!!
    //saco el MSB que seria pc++
    const u8 MSB = ram->read( inc(&this->PC) ); //SOLO SUMA AL LSB DE PC!!!!!!!
    _inc(&this->PC);
    return intToMem( (MSB << 8) | LSB );
}

memoryAdr NES::indX(){ //anda y testeado
    const u8 adr = ram->read( this->PC );
    _inc(&this->PC);
    memoryAdr fetch = intToMem( (adr + this->X) & 0xFF ); // a esta direccion en zp busco el little endian
    const u8 LSB = ram->read( fetch );
    const u8 MSB = ram->read( inc(&fetch) ); //seria fetch++ en el primero
    return intToMem( (MSB<<8) | LSB);
}

memoryAdr NES::indY(){ //anda y testeado
    //busco en zp adr
    const u8 adr = ram->read(this->PC);
    _inc(&this->PC);
    //busco val en adr en little endian
    const u8 LSB = (ram->read( intToMem(adr) ) + this->Y) & 0xFF; //hago wrapping en el LSB de lo que devuelvo
    const u8 MSB = ram->read( intToMem( (adr + 1) & 0xFF)); //hago wrapping por el nibble
    return intToMem( (MSB<<8) | LSB);
}

memoryAdr NES::rel(){ //re testeado DALE INGRID DALE
    const char offset = ram->read(this->PC);
   memoryAdr val;
//    if ( (offset & 0x80) == 0x80 )
//        val = intToMem(((this->PC.adrHigh << 8) | this->PC.adrLow) - ((u8)(~offset - 1))); //complemento en 2 a u8 y despues resta
//    else
        val = intToMem(((this->PC.adrHigh << 8) | this->PC.adrLow) + offset + 1);
    _inc(&this->PC);
    return val;
}

memoryAdr NES::zp(){ //Esta arreglado
    const u8 val = ram->read( this->PC );
    _inc(&this->PC);
    return intToMem(val); //devuelvo nada mas lo de LSB
}

memoryAdr NES::zpX(){ //esta arreglado
    const u8 val = ram->read( this->PC );
    _inc(&this->PC);
    return intToMem( (val + this->X) & 0xFF);//hago lo mismo que con zp, sumando x y wrapeando porque no puedo estar seguro de que la suma da lindo
}

memoryAdr NES::zpY(){ //esta arreglado
    const u8 val = ram->read( this->PC );
    _inc(&this->PC);
    return intToMem( (val + this->Y) & 0xFF);//hago lo mismo que con zp, sumando x y wrapeando porque no puedo estar seguro de que la suma da lindo
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
    this->A = 0x00;
    this->X = 0x00;
    this->Y = 0x00;
    this->SP = 0xFF;
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
    return "Instruccion:"+hex(this->opcode)+" A: 0x"+hex(this->A)+ " X: 0x"+hex(this->X)+ " Y: 0x"+hex(this->Y)+ " Stack: 0x1"+hex(this->SP)+" PC: 0x"+hex(this->PC.adrHigh)+hex(this->PC.adrLow)+" Ciclos: "+hex(this->ciclos)+" Status:"+ eflags(flags);
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

inline u8 NES::cFlag(int res) {
    return (res & 0x100) == 0x100 ? C_FLAG : 0x00;
}

inline u8 NES::nFlag(int res) {
    return (res & 0x80) == 0x80 ? N_FLAG : 0x00;
}

inline u8 NES::zFlag(int res) {
    return (res == 0x00) ? Z_FLAG : 0x00;
}
