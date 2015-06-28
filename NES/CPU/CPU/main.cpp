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
    int i = 0xFFFC;
    cout<<"pudo leer: 0x"<<hex(r.read(intToMem(i)))<<" en addr "<<i<<endl;
     i = 0xFFFD;
    
    cout<<"pudo leer: 0x"<<hex(r.read(intToMem(i)))<<" en addr "<<i<<endl;
    
    string ins="";
    while(ins!="exit"){
        cout<<"Ingrese instru, interrupt, flags o exit"<<endl;
        cin>>ins;
        if (ins=="instru"){
            nes.exec(0x20);
        }
        else if (ins=="interrupt"){
            int cual=0;
            cout<<"Ingrese que interrupt"<<endl;
            cin>>cual;
            if (cual==0){
                nes.nmi();
            }
            else if (cual==1){
                nes.irq();
            }
            else if (cual==2){
                nes.reset();
            }
        }else if (ins=="flags") {
            u8 flags = 0x00, flagsToSet = 0x00;
            char info = ' ';
            while (info != 'E') {
                cout<<"Ingrese flag a setear, o E para salir"<<endl;
                cin>>info;
                switch (info) {
                    case 'C':
                        cout<<"Ingrese 1 para setar el flag de carry"<<endl;
                        flagsToSet |= C_FLAG;
                        cin>>info;
                        if (info == '1') flags |= C_FLAG;
                        break;
                    case 'Z':
                        cout<<"Ingrese 1 para setar el flag de zero"<<endl;
                        flagsToSet |= Z_FLAG;
                        cin>>info;
                        if (info == '1') flags |= Z_FLAG;
                        break;
                    case 'I':
                        cout<<"Ingrese 1 para setar el flag de irq"<<endl;
                        flagsToSet |= I_FLAG;
                        cin>>info;
                        if (info == '1') flags |= I_FLAG;
                        break;
                    case 'D':
                        cout<<"Ingrese 1 para setar el flag de decimal"<<endl;
                        flagsToSet |= D_FLAG;
                        cin>>info;
                        if (info == '1') flags |= D_FLAG;
                        break;
                    case 'B':
                        cout<<"Ingrese 1 para setar el flag de break"<<endl;
                        flagsToSet |= B_FLAG;
                        cin>>info;
                        if (info == '1') flags |= B_FLAG;
                        break;
                    case 'O':
                        cout<<"Ingrese 1 para setar el flag de overflow"<<endl;
                        flagsToSet |= O_FLAG;
                        cin>>info;
                        if (info == '1') flags |= O_FLAG;
                        break;
                    case 'N':
                        cout<<"Ingrese 1 para setar el flag de negative"<<endl;
                        flagsToSet |= N_FLAG;
                        cin>>info;
                        if (info == '1') flags |= N_FLAG;
                        break;
                }
            }
            cout<<"Los flags ingresados son: 0x"<<hex(flagsToSet)<<" con el valor "<<hex(flags)<<endl;
//            nes.setFlags(flags, flagsToSet);
        }
        cout<<nes.estado()<<endl;
    }
}
