//
//  VRAM.cpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 16/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#include "VRAM.h"
#include "Types.h"
#include "Input.h"

using namespace std;

VRAM::VRAM(const Input* i) {
    //no puedo avanzar hasta tener internet gracias wifi <3
}

void VRAM::write(const int adr, const u8 val) {
    *getVRAMAdr(adr) = val;
}

u8 VRAM::read(const int adr) {
    return *getVRAMAdr(adr);
}

u8* VRAM::getVRAMAdr(const int adr0) {
    const int adr = adr0 & 0xFFFF;
    u8* retval = NULL;
    if (adr <= PT0_END)
        retval = &PT0[adr - PT0_START];
    else if (adr <= PT1_END)
        retval = &PT1[adr - PT1_START];
    else if (adr <= NT0_END)
        retval = &NT0[adr - NT0_START];
    else if (adr <= AT0_END)
        retval = &AT0[adr - AT0_START];
    else if (adr <= NT1_END)
        retval = &NT1[adr - NT1_START];
    else if (adr <= AT1_END)
        retval = &AT1[adr - AT1_START];
    else if (adr <= NT2_END)
        retval = &NT2[adr - NT2_START];
    else if (adr <= AT2_END)
        retval = &AT2[adr - AT2_START];
    else if (adr <= NT3_END)
        retval = &NT3[adr - NT3_START];
    else if (adr <= AT3_END)
        retval = &AT3[adr - AT3_START];
    else if (adr <= VRAM_MIR0_END)
        retval = &VRAM_MIR0[adr - VRAM_MIR0_START];
    else if (adr <= IP1_END)
        retval = &IP1[adr - IP1_START];
    else if (adr <= SP1_END)
        retval = &SP1[adr - SP1_START];
    else if (adr <= PM_MIR_END)
        retval = &PM_MIR[adr - PM_MIR_START];
    else if (adr <= VRAM_MIR1_END)
        retval = &VRAM_MIR1[adr - VRAM_MIR1_START];
    
    return retval;
}