//
//  Types.cpp
//  RAM
//
//  Created by Valentin Paz Marcolla on 25/5/15.
//  Copyright (c) 2015 GamePi. All rights reserved.
//

#include "Types.h"
#include <iostream>

using namespace std;

inline char h (u8 e){
    if (0 <= e && e <= 9)
        return ('0' + e);
    else //if (0xA <= e && e <= 0xF)
        return ('A' + e - 10);
}

string hex (u8 val) {
    u8 k1 = (val & 0xF0) >> 4, k2 = val & 0x0F;
    return { h(k1), h(k2) };
}

inline int memToInt(memoryAdr adr) {
    return (adr.adrHigh << 8) | adr.adrLow;
}

u8 toU8(const char * str){
    u8 val = 0;
    for (int i = 0; i < 2; i++) {
        u8 v = 0;
        const char c = str[i];
        if ( ('0' <= c) && (c <= '9') ) {
            v = c - '0';
        } else if( ('A' <= c) && (c <= 'F') ) {
            v = 0x0A + (c - 'A');
        } else cout<<"La letra "<<c<<" será interpretada como un 0"<<endl;
        val |= v << (4*(1-i));
    }
    return val;
}