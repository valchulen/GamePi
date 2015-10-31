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

using namespace std;

class Input {
    ifstream* file;
private:
    u8* read (int, u8*);
    void skip (int);
    u8 read ();
public:
    u8 prg_16_rom,
        chr_8_rom,
        flags_6,
        flags_7,
        prg_8_ram,
        flags_9;
    int trainer_size = 0;
    u8* trainer;
    u8* prg_rom;
    u8* chr_rom;
    
    Input(string);
    //~Input();
};

#endif /* defined(____Input__) */
