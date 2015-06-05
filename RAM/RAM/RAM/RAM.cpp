//
//  RAM.cpp
//  RAM
//
//  Created by Valentin Paz Marcolla on 24/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include "RAM.h"
#include "Types.h"
#include <iostream>
using namespace std;


u8 RAM::read(memoryAdr adr){
    return *this->toRealAdr(adr);
}

bool RAM::write(memoryAdr adr, u8 val){
    if (adr.adrHigh < 0x80)
        *this->toRealAdr(adr) = val;
    else return false;
    return true;
}

realMemory RAM::toRealAdr(memoryAdr adr){
    return &this->R_2007;
}