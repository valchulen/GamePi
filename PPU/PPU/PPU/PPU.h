//
//  PPU.hpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 16/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#ifndef PPU_h
#define PPU_h

#include <stdio.h>

#include "RAM.h"
#include "Types.h"
#include "VRAM.h"
#include "Sprite.h"

using namespace std;
class PPU{
    RAM* ram;
    realMemory dir2000, dir2001, dir2002;
    //$2000
    memoryAdr nameTable; // (0 = $2000; 1 = $2400; 2 = $2800; 3 = $2C00)
    u8 increment; // VRAM address increment per CPU read/write of PPUDAT    (0: add 1, going across; 1: add 32, going down
    memoryAdr spriteTable; //(0: $0000; 1: $1000; ignored in 8x16 mode)
    memoryAdr bgTable; //(0: $0000; 1: $1000)
    u8 spritesize;//(0: 8x8; 1: 8x16)
    u8 nmi; //Execute NMI on VBlank    |0 = Disabled |1 = Enabled
    //$2001
    u8 displaytype;
    VRAM* vram;
    Sprite SPR[64];
    
    int pallete[64];
    
    u8 BGP0[3];
    u8 BGP1[3];
    u8 BGP2[3];
    u8 BGP3[3];
    u8 SpP0[3];
    u8 SpP1[3];
    u8 SpP2[3];
    u8 SpP3[3];
    
public:
    PPU(RAM*);
    ~PPU();
    void cargarPallete();
    memoryAdr getNameTable();
    memoryAdr getSpriteTable();
    memoryAdr getBGTable();
    u8 getIncrement();
    u8 getSpriteSize();
    u8 getNmi();
    //$2001
    u8 getDsiplayType();
    u8 getBGClip();
    u8 getSpriteClip();
    u8 getBgVisibility();
    u8 getSpriteVisibility();
    u8 getColorBG();
    //$2002
    u8 getVramFlag();
    u8 getSpriteCount();
    u8 getSpriteCero();
    u8 getVblank();
};


#endif /* PPU_hpp */