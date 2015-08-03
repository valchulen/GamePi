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

using namespace std;

ifstream* archivo = NULL;

string read (ifstream* v, int size) {
    string s = "";
    for(int i = 0; i <= size; i++) s += v->get();
    return s;
}

char read (ifstream* v) {
    return v->get();
}

int main(int argc, const char * argv[]) {
    cout<<"Ingrese el nombre del archivo"<<endl;
    string n_archivo;
    cin>>n_archivo;
    archivo = new ifstream(n_archivo);
    if (!archivo->is_open()) {
        cout<<"No se pudo abrir el archivo "<<n_archivo<<endl;
        return -1;
    }
    cout<<"Se abrio el archivo "<<n_archivo<<endl;
    if ( read(archivo, 4) == "NESZ") {
        u8 n_16_rom = read(archivo);
        u8 n_8_rom = read(archivo);
        u8 cositas_1 = read(archivo),
            cositas_2 = read(archivo);
        u8 n_8_ram = read(archivo);
        u8 cositas_3 = read(archivo);
        u8 
        while (!archivo->eof()) {
            cout<<(char)archivo->get();
        }
    } else cout<<"Archvio no interpretable";
    cout<<endl;
    //Destructor de archivo;
    return 0;
}
