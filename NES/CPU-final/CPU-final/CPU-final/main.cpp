//
//  main.cpp
//  CPU-final
//
//  Created by Valentin Paz Marcolla on 4/9/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include <iostream>
#include "Types.h"
#include "Input.h"
#include "NES.h"
#include "RAM.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Ingrese el nombre del archivo"<<endl;
    string n_arch;
    cin>>n_arch;
    Input i(n_arch);
    RAM r(&i);
    //destructor de i
    NES n(&r);
    while ( cin.get() != 'q') {
        n.exec();
        cout<<n.estado()<<endl;
    }
}

//llegamos con debug y todo resuelto hasta:
//a040 ad09 014a 9002 a0c0 8c----
//0x03 no anda, porque no es instruccion pero lo levanta como que si
