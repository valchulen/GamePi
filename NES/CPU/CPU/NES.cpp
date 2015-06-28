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

void NES::exec(u8 instru) {
    
    switch (instru) {
        // ADC
        case 0x69:
            //adc(imm());
            break;
        case 0x65:
            //adc(zpg());
            break;
        case 0x75:
            //adc(zpg(X));
            break;
        case 0x6d:
            //adc(abs());
            break;
        case 0x7d:
            //adc(abs(X, dummy.ONCARRY));
            break;
        case 0x79:
            //adc(abs(Y, dummy.ONCARRY));
            break;
        case 0x61:
            //adc(indX());
            break;
        case 0x71:
            //adc(indY());
            break;
        // AHX (unofficial)
        case 0x93:
            //ahx(indY(dummy.ALWAYS));
            break;
        case 0x9f:
            //ahx(abs(Y, dummy.ALWAYS));
            break;
        // ALR (unofficial)
        case 0x4b:
            //alr(imm());
            break;
        // ANC (unofficial)
        case 0x0b:
            //anc(imm());
            break;
        case 0x2b:
            //anc(imm());
            break;
        // AND
        case 0x29:
            //and(imm());
            break;
        case 0x25:
            //and(zpg());
            break;
        case 0x35:
            //and(zpg(X));
            break;
        case 0x2D:
            //and(abs());
            break;
        case 0x3D:
            //and(abs(X, dummy.ONCARRY));
            break;
        case 0x39:
            //and(abs(Y, dummy.ONCARRY));
            break;
        case 0x21:
            //and(indX());
            break;
        case 0x31:
            //and(indY(dummy.ONCARRY));
            break;
        // ARR (unofficial)
        case 0x6b:
            //arr(imm());
            break;
        // ASL
        case 0x0A:
            //aslA();
            break;
        case 0x06:
            //asl(zpg());
            break;
        case 0x16:
            //asl(zpg(X));
            break;
        case 0x0e:
            asl(abs());
            break;
        case 0x1e:
            asl(abs(X, dummy.ALWAYS));
            break;
        // AXS (unofficial)
        case 0xcb:
            axs(imm());
            break;
        // BIT
        case 0x24:
            bit(zpg());
            break;
        case 0x2c:
            bit(abs());
            break;
        // Branches: every branch uses rel. addressing
        case 0x10:
            branch(!negativeFlag);
            break;
        case 0x30:
            branch(negativeFlag);
            break;
        case 0x50:
            branch(!overflowFlag);
            break;
        case 0x70:
            branch(overflowFlag);
            break;
        case 0x90:
            branch(!carryFlag);
            break;
        case 0xB0:
            branch(carryFlag);
            break;
        case 0xD0:
            branch(!zeroFlag);
            break;
        case 0xF0:
            branch(zeroFlag);
            break;
        // BRK
        case 0x00:
            breakinterrupt();
            break;
        // CMP
        case 0xc9:
            cmp(A, imm());
            break;
        case 0xc5:
            cmp(A, zpg());
            break;
        case 0xd5:
            cmp(A, zpg(X));
            break;
        case 0xcd:
            cmp(A, abs());
            break;
        case 0xdd:
            cmp(A, abs(X, dummy.ONCARRY));
            break;
        case 0xd9:
            cmp(A, abs(Y, dummy.ONCARRY));
            break;
        case 0xc1:
            cmp(A, indX());
            break;
        case 0xd1:
            cmp(A, indY(dummy.ONCARRY));
            break;
        // CPX
        case 0xe0:
            cmp(X, imm());
            break;
        case 0xe4:
            cmp(X, zpg());
            break;
        case 0xec:
            cmp(X, abs());
            break;
        // CPY
        case 0xc0:
            cmp(Y, imm());
            break;
        case 0xc4:
            cmp(Y, zpg());
            break;
        case 0xcc:
            cmp(Y, abs());
            break;
        // DEC
        case 0xc6:
            dec(zpg());
            break;
        case 0xd6:
            dec(zpg(X));
            break;
        case 0xce:
            dec(abs());
            break;
        case 0xde:
            dec(abs(X, dummy.ALWAYS));
            break;
        // DCP (unofficial)
        case 0xc3:
            dcp(A, indX());
            break;
        case 0xd3:
            dcp(A, indY(dummy.ALWAYS));
            break;
        case 0xc7:
            dcp(A, zpg());
            break;
        case 0xd7:
            dcp(A, zpg(X));
            break;
        case 0xdb:
            dcp(A, abs(Y, dummy.ALWAYS));
            break;
        case 0xcf:
            dcp(A, abs());
            break;
        case 0xdf:
            dcp(A, abs(X, dummy.ALWAYS));
            break;
        // EOR
        case 0x49:
            eor(imm());
            break;
        case 0x45:
            eor(zpg());
            break;
        case 0x55:
            eor(zpg(X));
            break;
        case 0x4d:
            eor(abs());
            break;
        case 0x5d:
            eor(abs(X, dummy.ONCARRY));
            break;
        case 0x59:
            eor(abs(Y, dummy.ONCARRY));
            break;
        case 0x41:
        eor(indX());
        break;
        case 0x51:
        eor(indY(dummy.ONCARRY));
        break;
        // Flag set/clear
        case 0x18:
        break;
        case 0x38:
        break;
        case 0x58:
        //cli
        break;
        case 0x78:
        //sei
        break;
        case 0xb8:
        break;
        case 0xd8:
        break;// decimal mode doesnt
        case 0xf8:
        break;// do anything on NES
        // INC
        case 0xe6:
        inc(zpg());
        break;
        case 0xf6:
        inc(zpg(X));
        break;
        case 0xee:
        inc(abs());
        break;
        case 0xfe:
        inc(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // ISC (unofficial)
        case 0xe3:
        isc(indX());
        cycles += 8;
        break;
        case 0xf3:
        isc(indY(dummy.ALWAYS));
        cycles += 8;
        break;
        case 0xe7:
        isc(zpg());
        cycles += 5;
        break;
        case 0xf7:
        isc(zpg(X));
        cycles += 6;
        break;
        case 0xfb:
        isc(abs(Y, dummy.ALWAYS));
        cycles += 7;
        break;
        case 0xef:
        isc(abs());
        cycles += 6;
        break;
        case 0xff:
        isc(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // JMP
        case 0x4c:
        PC = abs();
        cycles += 3;
        break;
        case 0x6c:
        PC = ind();
        cycles += 5;
        break;
        // JSR
        case 0x20:
        jsr(abs());
        cycles += 6;
        break;
        // KIL (unofficial)
        case 0x02:
        case 0x12:
        case 0x22:
        case 0x32:
        case 0x42:
        case 0x52:
        case 0x62:
        case 0x72:
        case 0x92:
        case 0xb2:
        case 0xd2:
        case 0xf2:
        System.err.println("KIL - CPU locked");
        ram.apu.nes.runEmulation = false;
        break;
        // LAS (unofficial)
        case 0xbb:
        las(abs(Y, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        // LAX (unofficial)
        case 0xa3:
        lax(indX());
        cycles += 6;
        break;
        case 0xb3:
        lax(indY(dummy.ONCARRY));
        cycles += 5 + pb;
        break;
        case 0xa7:
        lax(zpg());
        cycles += 3;
        break;
        case 0xb7:
        lax(zpg(Y));
        cycles += 4;
        break;
        case 0xab:
        lax(imm());
        cycles += 2;
        break;
        case 0xaf:
        lax(abs());
        cycles += 4;
        break;
        case 0xbf:
        lax(abs(Y, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        // LDA
        case 0xa9:
        lda(imm());
        cycles += 2;
        break;
        case 0xa5:
        lda(zpg());
        cycles += 3;
        break;
        case 0xb5:
        lda(zpg(X));
        cycles += 4;
        break;
        case 0xad:
        lda(abs());
        cycles += 4;
        break;
        case 0xbd:
        lda(abs(X, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        case 0xb9:
        lda(abs(Y, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        case 0xa1:
        lda(indX());
        cycles += 6;
        break;
        case 0xb1:
        lda(indY(dummy.ONCARRY));
        cycles += 5 + pb;
        break;
        // LDX
        case 0xa2:
        ldx(imm());
        cycles += 2;
        break;
        case 0xa6:
        ldx(zpg());
        cycles += 3;
        break;
        case 0xb6:
        ldx(zpg(Y));
        cycles += 4;
        break;
        case 0xae:
        ldx(abs());
        cycles += 4;
        break;
        case 0xbe:
        ldx(abs(Y, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        // LDY
        case 0xa0:
        ldy(imm());
        cycles += 2;
        break;
        case 0xa4:
        ldy(zpg());
        cycles += 3;
        break;
        case 0xb4:
        ldy(zpg(X));
        cycles += 4;
        break;
        case 0xac:
        ldy(abs());
        cycles += 4;
        break;
        case 0xbc:
        ldy(abs(X, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        // LSR
        case 0x4a:
        lsrA();
        cycles += 2;
        break;
        case 0x46:
        lsr(zpg());
        cycles += 5;
        break;
        case 0x56:
        lsr(zpg(X));
        cycles += 6;
        break;
        case 0x4e:
        lsr(abs());
        cycles += 6;
        break;
        case 0x5e:
        lsr(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // NOP
        case 0x1a:
        case 0x3a:
        case 0x5a:
        case 0x7a:
        case 0xda:
        case 0xEA:
        case 0xfa:
        cycles += 2;
        break;
        case 0x80:
        case 0x82:
        case 0xc2:
        case 0xe2:
        case 0x89:
        imm();
        cycles += 2;
        break;
        case 0x04:
        case 0x44:
        case 0x64:
        zpg();
        cycles += 3;
        break;
        case 0x14:
        case 0x34:
        case 0x54:
        case 0x74:
        case 0xd4:
        case 0xf4:
        zpg(X);
        cycles += 4;
        break;
        case 0x0C:
        abs();
        cycles += 4;
        break;
        case 0x1c:
        case 0x3c:
        case 0x5c:
        case 0x7c:
        case 0xdc:
        case 0xfc:
        abs(X, dummy.ONCARRY);
        cycles += 4 + pb;
        break;
        // ORA
        case 0x09:
        ora(imm());
        cycles += 2;
        break;
        case 0x05:
        ora(zpg());
        cycles += 3;
        break;
        case 0x15:
        ora(zpg(X));
        cycles += 4;
        break;
        case 0x0d:
        ora(abs());
        cycles += 4;
        break;
        case 0x1d:
        ora(abs(X, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        case 0x19:
        ora(abs(Y, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        case 0x01:
        ora(indX());
        cycles += 6;
        break;
        case 0x11:
        ora(indY(dummy.ONCARRY));
        cycles += 5 + pb;
        break;
        // Register instrs.
        case 0xAA:
        X = A;
        cycles += 2;
        setflags(A);
        break;
        case 0x8a:
        A = X;
        cycles += 2;
        setflags(A);
        break;
        case 0xca:
        X--;
        X &= 0xFF;
        setflags(X);
        cycles += 2;
        break;
        case 0xe8:
        X++;
        X &= 0xFF;
        setflags(X);
        cycles += 2;
        break;
        case 0xa8:
        Y = A;
        cycles += 2;
        setflags(A);
        break;
        case 0x98:
        A = Y;
        cycles += 2;
        setflags(A);
        break;
        case 0x88:
        Y--;
        Y &= 0xFF;
        setflags(Y);
        cycles += 2;
        break;
        case 0xc8:
        Y++;
        Y &= 0xFF;
        setflags(Y);
        cycles += 2;
        break;
        // RLA (unofficial)
        case 0x23:
        rla(indX());
        cycles += 8;
        break;
        case 0x33:
        rla(indY(dummy.ALWAYS));
        cycles += 8;
        break;
        case 0x27:
        rla(zpg());
        cycles += 5;
        break;
        case 0x37:
        rla(zpg(X));
        cycles += 6;
        break;
        case 0x3b:
        rla(abs(Y, dummy.ALWAYS));
        cycles += 7;
        break;
        case 0x2f:
        rla(abs());
        cycles += 6;
        break;
        case 0x3f:
        rla(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // ROL
        case 0x2a:
        rolA();
        cycles += 2;
        break;
        case 0x26:
        rol(zpg());
        cycles += 5;
        break;
        case 0x36:
        rol(zpg(X));
        cycles += 6;
        break;
        case 0x2e:
        rol(abs());
        cycles += 6;
        break;
        case 0x3e:
        rol(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // ROR
        case 0x6a:
        rorA();
        cycles += 2;
        break;
        case 0x66:
        ror(zpg());
        cycles += 5;
        break;
        case 0x76:
        ror(zpg(X));
        cycles += 6;
        break;
        case 0x6e:
        ror(abs());
        cycles += 6;
        break;
        case 0x7e:
        ror(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // RRA (unofficial)
        case 0x63:
        rra(indX());
        cycles += 8;
        break;
        case 0x73:
        rra(indY(dummy.ALWAYS));
        cycles += 8;
        break;
        case 0x67:
        rra(zpg());
        cycles += 5;
        break;
        case 0x77:
        rra(zpg(X));
        cycles += 6;
        break;
        case 0x7b:
        rra(abs(Y, dummy.ALWAYS));
        cycles += 7;
        break;
        case 0x6f:
        rra(abs());
        cycles += 6;
        break;
        case 0x7f:
        rra(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // RTI
        case 0x40:
        rti();
        cycles += 6;
        break;
        // RTS
        case 0x60:
        rts();
        cycles += 6;
        break;
        // SAX (unofficial)
        case 0x83:
        sax(indX());
        cycles += 6;
        break;
        case 0x87:
        sax(zpg());
        cycles += 3;
        break;
        case 0x97:
        sax(zpg(Y));
        cycles += 4;
        break;
        case 0x8f:
        sax(abs());
        cycles += 4;
        break;
        // SBC
        case 0xE1:
        sbc(indX());
        cycles += 6;
        break;
        case 0xF1:
        sbc(indY(dummy.ONCARRY));
        cycles += 5 + pb;
        break;
        case 0xE5:
        sbc(zpg());
        cycles += 3;
        break;
        case 0xF5:
        sbc(zpg(X));
        cycles += 4;
        break;
        case 0xE9:
        sbc(imm());
        cycles += 2;
        break;
        case 0xF9:
        sbc(abs(Y, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        case 0xeb:
        sbc(imm());
        cycles += 2;
        break;
        case 0xEd:
        sbc(abs());
        cycles += 4;
        break;
        case 0xFd:
        sbc(abs(X, dummy.ONCARRY));
        cycles += 4 + pb;
        break;
        // SHX (unofficial)
        case 0x9e:
        shx(abs(Y, dummy.ALWAYS));
        cycles += 5;
        break;
        // SHY (unofficial)
        case 0x9c:
        shy(abs(X, dummy.ALWAYS));
        cycles += 5;
        break;
        // SLO (unofficial)
        case 0x03:
        slo(indX());
        cycles += 8;
        break;
        case 0x07:
        slo(zpg());
        cycles += 5;
        break;
        case 0x0f:
        slo(abs());
        cycles += 6;
        break;
        case 0x13:
        slo(indY(dummy.ALWAYS));
        cycles += 8;
        break;
        case 0x17:
        slo(zpg(X));
        cycles += 6;
        break;
        case 0x1b:
        slo(abs(Y, dummy.ALWAYS));
        cycles += 7;
        break;
        case 0x1f:
        slo(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // SRE (unofficial)
        case 0x43:
        sre(indX());
        cycles += 8;
        break;
        case 0x53:
        sre(indY(dummy.ALWAYS));
        cycles += 8;
        break;
        case 0x47:
        sre(zpg());
        cycles += 5;
        break;
        case 0x57:
        sre(zpg(X));
        cycles += 6;
        break;
        case 0x5b:
        sre(abs(Y, dummy.ALWAYS));
        cycles += 7;
        break;
        case 0x4f:
        sre(abs());
        cycles += 6;
        break;
        case 0x5f:
        sre(abs(X, dummy.ALWAYS));
        cycles += 7;
        break;
        // STA
        case 0x85:
        sta(zpg());
        cycles += 3;
        break;
        case 0x95:
        sta(zpg(X));
        cycles += 4;
        break;
        case 0x8d:
        sta(abs());
        break;
        case 0x9d:
        sta(abs(X, dummy.ALWAYS));
        break;
        case 0x99:
        sta(abs(Y, dummy.ALWAYS));
        break;
        case 0x81:
        sta(indX());
        break;
        case 0x91:
        sta(indY(dummy.ALWAYS));
        break;
        // Stack instructions
        case 0x9A:
        break;
        case 0xBA:
        break;
        case 0x48:
        break;
        case 0x68:
        break;
        case 0x08:

        break;
        case 0x28:
        //plp
        break;
        // STX
        case 0x86:
        stx(zpg());
        break;
        case 0x96:
        stx(zpg(Y));
        break;
            case 0x8E:
        stx(abs());
            break;
        // STY
        case 0x84:
            sty(zpg());
            break;
        case 0x94:
            sty(zpg(X));
            break;
        case 0x8c:
            sty(abs());
            break;
        // TAS (unofficial)
        case 0x9b:
            tas(abs(Y, dummy.ALWAYS));
            break;
        // XAA (unofficial)
        case 0x8b:
            xaa(imm());
            break;
        default:
            //illegal opcode
        break;
    }
    

    
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