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

u8* read (ifstream* v, int size) {
    u8 val[size];
    for(int i = 0; i < size; i++) val[i] = v->get();
    return val; //Si se usa, hay que liberarlo despues
}
void skip (ifstream* v, int size) {
    for(int i = 0; i < size; i++) v->get();
}

u8 read (ifstream* v) {
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
        skip(archivo, 3);//corresponde con el "NES", lo leo porque paja convertir de u8 a string
    //el header deberia tene siempre 16 bytes
        skip(archivo, 2); //skipeo dos porqye tiene " " + el EOF de ms
        u8 prg_16_rom = read(archivo);
        u8 chr_8_rom = read(archivo); //es de la PPU-ROM
        u8 flags_6 = read(archivo),
            flags_7 = read(archivo);
        u8 prg_8_ram = read(archivo); //no se usa en donkey kong
        u8 cositas_3 = read(archivo);
        skip(archivo, 5);
    u8* trainer;
    if (flags_6 & 0x04) trainer = read(archivo, 512);
        u8* prg_rom = read(archivo, 16384 * prg_16_rom);
    u8* chr_rom = read(archivo, 8192 * chr_8_rom);
    //Destructor de archivo;
    archivo->close();
    return 0;
}
