//
//  main.cpp
//  CPU
//
//  Created by Valentin Paz Marcolla on 8/6/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Types.h"
#include "NES.h"
using namespace std;
RAM r;
NES nes(&r);

int main(int argc, const char * argv[]) {
    string ins="";
    while(ins!="exit"){
        cout<<"Ingrese instru, direc, int, push, bcd, exit"<<endl;
        cin>>ins;
        if (ins=="instru"){
            char a, b;
            cout<<"Ingrese instruccion:"<<endl;
            cin>>a>>b;
            char op[2] = {a, b};
            const u8 opcode = toU8(op);
            nes.exec(opcode);
        } else if (ins=="int"){
            string cual="";
            cout<<"Ingrese que interrupt: nmi, irq, brk, reset"<<endl;
            cin>>cual;
            if (cual=="nmi")
                nes.nmi();
            else if (cual=="irq")
                nes.irq();
            else if (cual=="reset")
                nes.reset();
            else if(cual=="brk")
                nes.brk();
            else
                cout<<"Error"<<endl;
        } else if (ins=="direc"){
            string cual="";
            cout<<"Ingrese que modo de direc: ind, indx, indy, imm, abs, absx, absy, zp, zpx, zpy, accu"<<endl;
            cin>>cual;
            cout<<nes.estado()<<endl;
            u8 val = 0;
            memoryAdr mem;
            if (cual=="abs") {
                val = nes.abs();
            } else if (cual=="accu"){
                val = nes.accu();
            } else if (cual=="zp") {
                val = nes.zp();
            } else if (cual=="zpx") {
                val = nes.zpX();
            } else if (cual=="zpy") {
                val = nes.zpY();
            } else if (cual=="absx") {
                val = nes.absX();
            } else if (cual=="absy") {
                val = nes.absY();
            } else if (cual=="imm") {
                val = nes.imm();
            } else if (cual=="ind") {
                mem = nes.ind();
            } else if (cual=="indx") {
                mem = nes.indX();
            } else if (cual=="indy") {
                mem = nes.indY();
            }
            if (val == 0) cout<<"Valor: 0x"<<hex(mem.adrHigh)<<hex(mem.adrLow)<<endl;
            else cout<<"Valor: 0x"<<hex(val)<<endl;
        } else if(ins=="push"){
            nes.pushStack(0xbc);
            u8 val= nes.popStack();
            cout<<"Valor popeado del stack: "<<hex(val)<<endl;
        } else if (ins=="bcd"){
            cout<<"BCD: "<<hex(u8toBCD(0X13))<<endl;
            cout<<"Hex: "<<hex(BCDtou8(u8toBCD(0X13)))<<endl;
        }
        cout<<nes.estado()<<endl;
    }
}
