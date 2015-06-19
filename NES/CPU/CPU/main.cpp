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
    string ins="";
    while(ins!="exit"){
        cout<<"Ingrese instru, interrupt, exit"<<endl;
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
        }
        cout<<nes.estado()<<endl;
    }
}
