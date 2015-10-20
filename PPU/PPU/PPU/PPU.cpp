//
//  PPU.cpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 16/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#include "PPU.h"
#include "Types.h"

using namespace std;


PPU::PPU(RAM* ram){
    this->ram = ram;
    dir2000 = ram->toRealAdr(intToMem(0x2000));
    dir2001 = ram->toRealAdr(intToMem(0x2001));
    dir2002 = ram->toRealAdr(intToMem(0x2002));
}

PPU::~PPU() {
}

memoryAdr PPU::getNameTable(){
    u8 val= *dir2000 & 0x03;
    switch (val) {
        case 0:
            return intToMem(0x2000);
            break;
        case 1:
            return intToMem(0x2400);
            break;
        case 2:
            return intToMem(0x2800);
            break;
        case 3:
            return intToMem(0x2C00);
            break;
        default:
            return intToMem(0x0000);
            break;
    }
}

memoryAdr PPU::getSpriteTable(){
    if ((*dir2000>>3&0x01)==0)
        return intToMem(0x0000);
    else
        return intToMem(0x1000);
}

memoryAdr PPU::getBGTable(){
    if ((*dir2000>>4&0x01)==0)
        return intToMem(0x0000);
    else
        return intToMem(0x1000);
}

u8 PPU::getIncrement(){
    return *dir2000>>2 & 0x01; //0-> increment by 1, 1->increment by 32
}

u8 PPU::getSpriteSize(){
    return *dir2000>>5 & 0x01; //0-> 8x8, 1->8x16
}

u8 PPU::getNmi(){
    return *dir2000>>7 & 0x01; //0-> disable, 1->enable
}

u8 PPU::getDsiplayType(){
    return *dir2001 & 0x01;
}

u8 PPU::getBGClip(){
    return *dir2001>>1 & 0x01; //0->BG invisible in lef 8 pixel column, 1-> no clipping
}

u8 PPU::getSpriteClip(){
    return *dir2001>>2 & 0x01; //0->Sprite invisible in lef 8 pixel column, 1-> no clipping
}

u8 PPU::getBgVisibility(){
    return *dir2001>>3 & 0x01; //0-> not visble, 1->visible
}

u8 PPU::getSpriteVisibility(){
    return *dir2001>>4 & 0x01; //0-> not visble, 1->visible
}

u8 PPU::getColorBG(){
    return *dir2001>>5 & 0x07; //0->none, 1->verde, 2->azul, 4->rojo
}

u8 PPU::getVramFlag(){
    return *dir2002>>4 & 0x01; //1->writes to VRAM ignored
}

u8 PPU::getSpriteCount(){
    return *dir2002>>5 & 0x01; //1->mas de 8
}

u8 PPU::getSpriteCero(){
    return *dir2002>>6 & 0x01; //0->Sprite #0 not found, 1->PPU has hit Sprite #0
}

u8 PPU::getVblank(){
    return *dir2002>>7 & 0x01; //0-> not ocurring, 1->in VBlank
}