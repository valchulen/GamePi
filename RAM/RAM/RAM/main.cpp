//
//  main.cpp
//  RAM
//
//  Created by Valentin Paz Marcolla on 24/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include <iostream>
#include "Types.h"
#include "RAM.cpp"

using namespace std;
RAM r;

int main(int argc, const char * argv[]) {
    string s = "";
    cout<<"Ingrese read, write o quit"<<endl;
    cin>>s;
    while (s != "quit") {
        memoryAdr adr;
        if (s == "read") {
            cout<<"Ingrese high"<<endl;
            cin>>adr.adrHigh;
            cout<<"Ingrese low"<<endl;
            cin>>adr.adrLow;
            cout<<"Valor en $"<<hex(adr.adrHigh)<<hex(adr.adrLow)<<" = "<<hex(r.read(adr))<<endl;
        } else if (s == "write"){
            cout<<"Ingrese high"<<endl;
            cin>>adr.adrHigh;
            cout<<"Ingrese low"<<endl;
            cin>>adr.adrLow;
            cout<<"Ingrese el valor"<<endl;
            u8 val;
            cin>>val;
            r.write(adr, val);
        } else {
            cout<<"Valor ingresado no interpretable"<<endl;
        }
        cout<<"Ingrese read, write o quit"<<endl;
        cin>>s;
    }
    return 0;
}
