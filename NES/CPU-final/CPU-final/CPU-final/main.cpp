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
    char c = ' ';
    while ( (c = cin.get()) != 'q') {
        if (c == 'n'){
            n.setFlags(N_FLAG, N_FLAG);
        } else if (c == '0') {
            n.X = 0xff;
        }
        n.exec();
        cout<<n.estado()<<endl;
    }
}

//llegamos con debug y todo resuelto hasta:
//llegamos hasta afcc
//seguro no anda el and, besitos
