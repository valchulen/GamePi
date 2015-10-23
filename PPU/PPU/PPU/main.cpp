//
//  main.cpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 13/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#include <iostream>
#include "Input.h"
#include "NES.h"
#include "RAM.h"
#include "Types.h"
#include "PPU.h"

using namespace std;

int main(int argc, const char * argv[]) {
    string filename;
    cin>>filename;
    Input input (filename);
    RAM ram (&input);
    NES cpu (&ram);
    PPU ppu (&ram);
}