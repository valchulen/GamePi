//
//  Input.h
//  
//
//  Created by Valentin Paz Marcolla on 10/8/15.
//
//

#ifndef ____Input__
#define ____Input__

#include <iostream>
#include <fstream>
#include "Types.h"
#include "RAM.h"
#include "VRAM.h"
#include <QtCore>
using namespace std;

class Input {
    QTextStream* file;
public:
    u8 prg_16_rom,
    chr_8_rom,
    flags_6,
    flags_7,
    prg_8_ram,
    flags_9;
    int trainer_size = 0;
    u8 trainer[512];
    
    Input(QString, RAM*, VRAM*);
    //~Input();
private:
    QTextStream* in;
    int iFile = 0;
    void read (int, u8*);
    u8 read ();
    void readToRam(int, RAM*);
    void readToVram(VRAM*);
    void skip (int);
};

#endif /* defined(____Input__) */
