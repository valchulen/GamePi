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
        //---ADC---
        case 0x61:
            //adc(indX());
            break;
        case 0x65:
            //adc(zp());
            break;
        case 0x69:
            //adc(imm());
            break;
        case 0x6D:
            //adc(abs());
            break;
        case 0x71:
            //adc(indY());
            break;
        case 0x75:
            //adc(zpX());
            break;
        case 0x79:
            //adc(absY());
            break;
        case 0x7D:
            //adc(absX());
            break;
        
        //---AND---
        case 0x21:
            //And(imm());
            break;
        case 0x25:
            //And(zp());
            break;
        case 0x29:
            //And(zpX());
            break;
        case 0x2D:
            //And(abs());
            break;
        case 0x31:
            //And(abX());
            break;
        case 0x35:
            //And(absY());
            break;
        case 0x39:
            //And(indX());
            break;
        case 0x3D:
            //And(indY());
            break;
        
        //---ASL---
        case 0x06:
            //asl(acc());
            break;
        case 0x0A:
            //aslA(zp());
            break;
        case 0x0E:
        //asl(zpX());
        break;
        case 0x16:
            //asl(abs());
            break;
        case 0x1e:
            //asl(absX());
            break;
        
        
        // AXS (unofficial)
        case 0xcb:
            //axs(imm());
            break;
        
        //---BIT---
        case 0x24:
            bit(zp());
            break;
        case 0x2c:
            bit(abs());
            break;
        
        // Branches: every branch uses rel. addressing
        case 0x10:
            bpl(rel());
            break;
        case 0x30:
            bmi(rel());
            break;
        case 0x50:
            bvc(rel());
            break;
        case 0x70:
            bvs(rel());
            break;
        case 0x90:
            bcc(rel());
            break;
        case 0xB0:
            bcs(rel());
            break;
        case 0xD0:
            bne(rel());
            break;
        case 0xF0:
            beq(rel());
            break;
        
        //---BRK---
        case 0x00:
            brk();
            break;
        
        //---CMP---
        case 0xc1:
        cmp(imm());
        break;
        case 0xc5:
        //cmp(zp());
        break;
        case 0xc9:
            //cmp(zpX());
            break;
        case 0xcd:
        //cmp(abs());
        break;
        case 0xd1:
        //cmp(absX());
        break;
        case 0xd5:
            //cmp(absY());
            break;
        case 0xd9:
        //cmp(indX());
        break;
        case 0xdd:
            //cmp(indY());
            break;


        
        //---CPX---
        case 0xe0:
            cpx(imm());
            break;
        case 0xe4:
            //cpx(zp());
            break;
        case 0xec:
            //cpx(abs());
            break;
        
        //---CPY---
        case 0xc0:
            //cpy(imm());
            break;
        case 0xc4:
            //cpy(zp());
            break;
        case 0xcc:
            //cpy(abs());
            break;
        
        //---DEC---
        case 0xc6:
            //dec(zp());
            break;
        case 0xd6:
            //dec(zpgX());
            break;
        case 0xce:
            //dec(abs());
            break;
        case 0xde:
            //dec(absX());
            break;
        //DEX
        case 0xca:
        //dex();
        break;
        //DEY
        case 0x88:
        //dey();
        break;
        
        //---EOR---
        case 0x41:
        eor(imm());
        break;
        case 0x45:
        eor(zp());
        break;
        case 0x49:
            eor(zpX());
            break;
        case 0x4d:
            eor(abs());
        break;
        case 0x51:
            eor(absX());
        break;
        case 0x55:
            eor(absY());
            break;
        case 0x59:
            eor(indX());
        break;
        case 0x5d:
            eor(indY());
            break;
            break;
        
        //---INC---
        case 0xe6:
            inc(zp());
            break;
        case 0xee:
            inc(zpX());
            break;
        case 0xf6:
            inc(abs());
            break;
        case 0xfe:
        inc(absX());
            break;
        
        //INX
        case 0xe8:
        //inx();
        break;
        //INY
        case 0xc8:
        //iny();
        break;
        
        //---JMP---
        case 0x4c:
        jmp(abs());
            break;
        case 0x6c:
        jmp(ind());
            break;
        
        //---JSR---
        case 0x20:
            jsr(abs());
            break;
        
        //---LDA---
        case 0xa1:
            lda(imm());
            break;
        case 0xa5:
            lda(zp());
            break;
        case 0xa9:
            lda(zpX());
            break;
        case 0xad:
            lda(abs());
            break;
        case 0xb1:
            lda(absX());
            break;
        case 0xb5:
            lda(absY());
            break;
        case 0xb9:
            lda(indX());
            break;
        case 0xbd:
            lda(indY());
            break;
        
        //---LDX---
        case 0xa2:
            ldx(imm());
            break;
        case 0xa6:
            ldx(zp());
            break;
        case 0xae:
            ldx(zpY());
            break;
        case 0xb6:
            ldx(abs());
            break;
        case 0xbe:
            ldx(absY());
            break;
        
        //---LDY---
        case 0xa0:
            ldy(imm());
            break;
        case 0xa4:
            ldy(zp());
            break;
        case 0xac:
            ldy(zpX());
            break;
        case 0xb4:
            ldy(abs());
            break;
        case 0xbc:
            ldy(absX());
            break;
        
        //---LSR---
        case 0x46:
            lsr(accu());
            break;
        case 0x4a:
            lsr(zp());
            break;
        case 0x4e:
            lsr(zpX());
            break;
        case 0x56:
            lsr(abs());
            break;
        case 0x5e:
            lsr(absX());
            break;
        
        //NOP
        case 0xea:
        //nop();
        break;
        
        //---ORA---
        case 0x01:
            ora(imm());
            break;
        case 0x05:
            ora(zp());
            break;
        case 0x09:
            ora(zpX());
            break;
        case 0x0d:
            ora(abs());
            break;
        case 0x11:
            ora(absX());
            break;
        case 0x15:
            ora(absY());
            break;
        case 0x19:
            ora(indX());
            break;
        case 0x1d:
            ora(indY());
            break;
        
        //PHA
        case 0x48:
        //pha();
        break;
        
        //PHP
        case 0x08:
        //php();
        break;
        
        //PLA
        case 0x68:
        //pla();
        break;
        
        //PLP
        case 0x28:
        //plp();
        
        //---ROL---
        case 0x26:
            rol(accu());
            break;
        case 0x2a:
            rol(zp());
            break;
        case 0x2e:
            rol(zpX());
            break;
        case 0x36:
            rol(abs());
            break;
        case 0x3e:
            rol(absX());
            break;
        
        //---ROR---
        case 0x66:
            ror(accu());
            break;
        case 0x6a:
            ror(zp());
            break;
        case 0x6e:
            ror(zpX());
            break;
        case 0x76:
            ror(abs());
            break;
        case 0x7e:
            ror(absX());
            break;
        
        //---RTI---
        case 0x40:
            //rti();
            break;
        
        //---RTS---
        case 0x60:
            //rts();
            break;
        
        //---SBC---
        case 0xE1:
            sbc(imm());
            break;
        case 0xe5:
            sbc(zp());
            break;
        case 0xe9:
            sbc(zpX());
            break;
        case 0xed:
            sbc(abs());
            break;
        case 0xf1:
            sbc(absX());
            break;
        case 0xf5:
            sbc(absY());
            break;
        case 0xf9:
            sbc(indX());
            break;
        case 0xfd:
            sbc(indY());
            break;
        
        //SEC
        case 0x38:
        //sec();
        break;
        
        //SED
        case 0xf8:
        //sed();
        break;
        
        //SEI
        case 0x78:
        //sei();
        break;
        
        // STA
        case 0x81:
            sta(zp());
            break;
        case 0x85:
            sta(zpX());
            break;
        case 0x8d:
            sta(abs());
            break;
        case 0x91:
            sta(absX());
            break;
        case 0x95:
            sta(absY());
            break;
        case 0x99:
            sta(indX());
            break;
        case 0x9d:
            sta(indY());
            break;
        
        //---STX---
        case 0x86:
            stx(zp());
            break;
        case 0x8e:
            stx(zpY());
            break;
        case 0x96:
            stx(abs());
            break;
        
        //---STY---
        case 0x84:
            sty(zp());
            break;
        case 0x8c:
            sty(zpX());
            break;
        case 0x94:
            sty(abs());
            break;
        
        //TAX
        case 0xAA:
        //tax();
        break;
        
        //TAY
        case 0xA8:
        //tay();
        break;
        
        //TSX
        case 0xba:
        //tsx();
        break;
        
        //TXA
        case 0x8a:
        //txa(());
        break;
        
        //TXS
        case 0x9a:
        //txs(());
        break;
        
        //TYA
        case 0x98:
        //tya(());
        break;
        
        default:
            //illegal opcode
        break;
    }
}

//---Intrucciones---
void NES::adc(memoryAdr adr){
    
}
void NES::And(memoryAdr adr){
    
}
void NES::asl(memoryAdr adr){
    
}

//---Tipos de direccionamiento---
memoryAdr NES::abs(){
    return PC;
}
memoryAdr NES::absX(){
    return PC;
}
memoryAdr NES::absY(){
    return PC;
}
memoryAdr NES::accu(){
    return PC;
}
memoryAdr NES::imm(){
    return PC;
}
memoryAdr NES::ind(){
    return PC;
}
memoryAdr NES::indX(){
    return PC;
}
memoryAdr NES::indY(){
    return PC;
}
memoryAdr NES::rel(){
    return PC;
}
memoryAdr NES::zp(){
    return PC;
}
memoryAdr NES::zpX(){
    return PC;
}
memoryAdr NES::zpY(){
    return PC;
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
    pushStack(PC.adrHigh); //cuidado aca
    pushStack(PC.adrLow); //idem arriba
    pushStack(flags);
    this->PC = intToMem((ram->read(intToMem(0xFFFF)) << 8) | ram->read(intToMem(0xFFFE)));
}
void NES::brk(){
    setFlags(I_FLAG | B_FLAG, I_FLAG | B_FLAG);// be en 1, i en 1
    pushStack(flags);
    this->PC = intToMem((ram->read(intToMem(0xFFFF)) << 8) | ram->read(intToMem(0xFFFE)));
}
void NES::reset(){
    this->PC = intToMem((ram->read(intToMem(0xFFFD)) << 8) | ram->read(intToMem(0xFFFC)));
}
void NES::init(){
    //Borar memoria
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

void NES::setFlags(u8 flags, u8 flagsToSet){ //verificar que funcione
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

inline memoryAdr NES::realSP() { //hay que reducirlo -- creo que no hace falta
    memoryAdr adr;
    adr.adrHigh = 0x01;
    adr.adrLow = this->SP & 0xFF;
    return adr;
}
