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
#include "NES.h"

using namespace std;

int main(int argc, const char * argv[]) {
    cout<<"Ingrese el nombre del archivo"<<endl;
    string n_archivo;
    cin>>n_archivo;
    Input i(n_archivo); //hay que destruir i
    RAM r(&i);
    NES n(&r);
    while (true) {
        n.exec();
        cout<<n.estado();
    }
    return 0;
}
