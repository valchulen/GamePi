//
//  Input.cpp
//  
//
//  Created by Valentin Paz Marcolla on 10/8/15.
//
//

#include "Input.h"
#include "Types.h"
#include "RAM.h"
#include "VRAM.h"
#include <fstream>
#include <iostream>
#include <stdio.h>
#include <QTextStream>

using namespace std;

//esta funcion no se usa porque esta mal implementada, el stack se queda con todo :)
//u8* Input::read(int size) {
//    u8 val[size];
//    for(int i = 0; i < size; i++)
//        val[i] = this->file->get();
//    return val; //Si se usa, hay que liberarlo despues
//}

void Input::skip(int size) {
    for (int i = 0; i < size; i++)
        read ();
}

void Input::read(int size, u8 ptr[]) {
    for(int i = 0; i < size; i++)
        ptr[i] = read();
}

void Input::readToRam(int size, RAM* ram) {
    if (size > PRG1_SIZE) ram->PRG2_mirror = true;
    for(int i = 0; i < size; i++)
        ram->write(intToMem(i+PRG1_START), read());
}

void Input::readToVram(VRAM* vram) {
    for(int i = 0; i < 0x3FFF; i++)
        vram->write(i, read());
}

u8 Input::read () {
    bool bstatus = false;
    u8 byte = this->in->read(2).toInt(&bstatus, 16); // el 0x20 lo lee bien
    this->iFile++;
    if (this->iFile % 16 == 0)
        this->in->read(1); //esto hay que hacerlo para que lea de a lineas de 16 bits
    return byte;
}

Input::Input (QString filename, RAM* ram, VRAM* vram) {
    //this->file = new ifstream(filename.c_str());
    //if (this->file->is_open()) {
    QFile file(filename);
    if(!file.open(QFile::ReadOnly | QFile::Text))
    {
        qDebug() << " Could not open the file for reading";
        return;
    }

    in = new QTextStream(&file);

        skip(3);//corresponde con el "NES", lo leo porque paja convertir de u8 a string
        //el header deberia tene siempre 16 bytes
        skip(2); //skipeo dos porqye tiene " " + el EOF de ms
        this->prg_16_rom = read();
        this->chr_8_rom = read(); //es de la PPU-ROM
        this->flags_6 = read();
        this->flags_7 = read();
        this->prg_8_ram = read(); //no se usa en donkey kong
        this->flags_9 = read();
        skip(5);
        if (flags_6 & 0x04)
            read(512, this->trainer);
        this->trainer_size = 512;
        readToRam(16384 * this->prg_16_rom, ram);
        readToVram(vram);
        //Destructor de archivo;
        //this->file->close();
    //}

        file.close();

}

/*Input::~Input() {
    free(this->file);
    free(this->trainer);
    free(this->prg_rom);
    free(this->chr_rom);
}*/
