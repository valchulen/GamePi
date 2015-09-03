//
//  main.cpp
//  Input
//
//  Created by Valentin Paz Marcolla on 3/8/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#include <iostream>
#include <fstream>
#include "Types.h"
#include "Input.h"
#include "RAM.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Ingrese el nombre del archivo"<<endl;
    string n_archivo;
    cin>>n_archivo;
    Input i(n_archivo);
    RAM r(&i);
    for (int i  = 0x8000; i < 0xFFFF; i++) {
        cout<<hex(r.read(intToMem(i++)));
        cout<<hex(r.read(intToMem(i)));
        cout<<endl;
    }
    return 0;
}
