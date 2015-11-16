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

VRAM::VRAM() {
}

void VRAM::write(const int adr, const u8 val) {
    *getVRAMAdr(adr) = val;
}

u8 VRAM::read(const int adr) {
    return *getVRAMAdr(adr);
}

u8* VRAM::getVRAMAdr(const int adr0) {
    int adr = adr0 & PM_MIR_END; //wrapeo para que la ultima direccion sea 0x3FFF
    
    u8* retval = NULL;
    //para los mirrors x defecto
    if (VRAM_MIR0_START <= adr && adr <= VRAM_MIR0_END) //mirrorea 0x2000-0x2EFF / termina en 0x3EFF
        adr -= VRAM_MIR0_SIZE;
    else if (PM_MIR_START <= adr) //mirrorea 0x3F00-0x3F1F / termina en 0x3FFF / entra 7 veces
        adr &= SP1_END;
    
    if (horizontal){ //mirror horizontal y vertical de nametables y attributetables
        if ((NT1_START <= adr && adr <= AT1_END) || (NT3_START <= adr && adr <= AT3_END))
        adr -= NT1_SIZE;
    } else
        if ((NT2_START <= adr && adr <= AT2_END) || (NT3_START <= adr && adr <= AT3_END))
            adr -= NT2_SIZE * 2;
    
    if (PT0_START <= adr && adr <= PT0_END) //hasta 0x0FFF
        retval = &PT0[adr - PT0_START];
    else if (PT1_START <= adr && adr <= PT1_END) //hasta 0x1FFF
        retval = &PT1[adr - PT1_START];
    else if (NT0_START <= adr && adr <= NT0_END)
        retval = &NT0[adr - NT0_START];
    else if (AT0_START <= adr && adr <= AT0_END)
        retval = &AT0[adr - AT0_START];
    else if (NT1_START <= adr && adr <= NT1_END)
        retval = &NT1[adr - NT1_START];
    else if (AT1_START <= adr && adr <= AT1_END)
        retval = &AT1[adr - AT1_START];
    else if (NT2_START <= adr && adr <= NT2_END)
        retval = &NT2[adr - NT2_START];
    else if (AT2_START <= adr && adr <= AT2_END)
        retval = &AT2[adr - AT2_START];
    else if (NT3_START <= adr && adr <= NT3_END)
        retval = &NT3[adr - NT3_START];
    else if (AT3_START <= adr && adr <= AT3_END) //hasta 0x2FFF
        retval = &AT3[adr - AT3_START];
    else if (IP1_START <= adr && adr <= IP1_END)
        retval = &IP1[adr - IP1_START];
    else if (SP1_START <= adr && adr <= SP1_END)
        retval = &SP1[adr - SP1_START];
    
    return retval;
}