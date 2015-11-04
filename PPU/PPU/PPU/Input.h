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

using namespace std;

class Input {
    ifstream* file;
public:
    u8 prg_16_rom,
    chr_8_rom,
    flags_6,
    flags_7,
    prg_8_ram,
    flags_9;
    int trainer_size = 0;
    u8 trainer[512];
    
    Input(string, RAM*, VRAM*);
    //~Input();
private:
    void read (int, u8*);
    void readToRam(int, RAM*);
    void readToVram(VRAM*);
    void skip (int);
    u8 read ();
};

#endif /* defined(____Input__) */
