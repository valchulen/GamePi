//
//  main.cpp
//  CPU
//
//  Created by Valentin Paz Marcolla on 8/6/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include <iostream>
#include "Types.h"
#include "NES.h"
using namespace std;
RAM r;
NES nes(&r);


int main(int argc, const char * argv[]) {
    /*while (true) {
        int a;
        cin>>a;
        memoryAdr val = intToMem(a);
    }*/
    
    string ins="";
    while(ins!="exit"){
        cout<<"Ingrese instru, interrupt, push, exit"<<endl;
        cin>>ins;
        if (ins=="instru"){
            nes.exec(0x20);
        }
        else if (ins=="interrupt"){
            int cual=0;
            cout<<"Ingrese que interrupt"<<endl;
            cin>>cual;
            if (cual==0)
                nes.nmi();
            else if (cual==1)
                nes.irq();
            else if (cual==2)
                nes.reset();
        }
        else if(ins=="push"){
            /*string vpush;
            cout<<"Que valor desea pushear"<<endl;
            cin>>vpush;
            nes.pushStack(toU8(vpush.c_str()));
            u8 val= nes.popStack();*/ 
            nes.pushStack(0xbc);
            u8 val= nes.popStack();
            cout<<"Valor popeado del stack: "<<hex(val)<<endl;
        }
        cout<<nes.estado()<<endl;
    }
}
