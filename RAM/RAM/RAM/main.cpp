//
//  main.cpp
//  RAM
//
//  Created by Valentin Paz Marcolla on 24/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include <iostream>
#include "Types.h"
#include "RAM.h"

using namespace std;
RAM r;

int main(int argc, const char * argv[]) {
    string s = "";
    cout<<"Ingrese read, write o quit"<<endl;
    cin>>s;
    while (s != "quit") {
        memoryAdr adr;
        if (s == "read") {
            char h1, h2, l1, l2;
            cout<<"Ingrese high en hex"<<endl;
            cin>>h1;
            cin>>h2;
            cout<<"Ingrese low en hex"<<endl;
            cin>>l1;
            cin>>l2;
            char h[2] = { h1, h2 }, l[2] = { l1, l2 };
            adr.adrHigh = toU8(h);
            adr.adrLow = toU8(l);
            cout<<"Valor en $"<<hex(adr.adrHigh)<<hex(adr.adrLow)<<" = "<<hex(r.read(adr))<<endl;
        } else if (s == "write"){
            cout<<"Ingrese high"<<endl;
            cin>>adr.adrHigh;
            cout<<"Ingrese low"<<endl;
            cin>>adr.adrLow;
            cout<<"Ingrese el valor"<<endl;
            u8 val;
            cin>>val;
            cout<< (r.write(adr, val) ? "Se pudo escribir" : "No se pudo escribir") <<endl;
        } else {
            cout<<"Valor ingresado no interpretable"<<endl;
        }
        cout<<"Ingrese read, write o quit"<<endl;
        cin>>s;
    }
    return 0;
}
