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
    cargarPallete();
}

PPU::~PPU() {
}

void PPU::cargarPallete(){
    pallete[0]=0x808080;
    pallete[1]=0x003DA6;
    pallete[2]=0x0012B0;
    pallete[3]=0x440096;
    pallete[4]=0xA1005E;
    pallete[5]=0xC70028;
    pallete[6]=0xBA0600;
    pallete[7]=0x8C1700;
    pallete[8]=0x5C2F00;
    pallete[9]=0x104500;
    pallete[10]=0x054A00;
    pallete[11]=0x00472E;
    pallete[12]=0x004166;
    pallete[13]=0x000000;
    pallete[14]=0x050505;
    pallete[15]=0x050505;
    pallete[16]=0xC7C7C7;
    pallete[17]=0x0077FF;
    pallete[18]=0x2155FF;
    pallete[19]=0x8237FA;
    pallete[20]=0xEB2FB5;
    pallete[21]=0xFF2950;
    pallete[22]=0xFF2200;
    pallete[23]=0xD63200;
    pallete[24]=0xC46200;
    pallete[25]=0x358000;
    pallete[26]=0x058F00;
    pallete[27]=0x008A55;
    pallete[28]=0x0099CC;
    pallete[29]=0x212121;
    pallete[30]=0x090909;
    pallete[31]=0x090909;
    pallete[32]=0xFFFFFF;
    pallete[33]=0x0FD7FF;
    pallete[34]=0x69A2FF;
    pallete[35]=0xD480FF;
    pallete[36]=0xFF45F3;
    pallete[37]=0xFF618B;
    pallete[38]=0xFF8833;
    pallete[39]=0xFF9C12;
    pallete[40]=0xFABC20;
    pallete[41]=0x9FE30E;
    pallete[42]=0x2BF035;
    pallete[43]=0x0CF0A4;
    pallete[44]=0x05FBFF;
    pallete[45]=0x5E5E5E;
    pallete[46]=0x0D0D0D;
    pallete[47]=0x0D0D0D;
    pallete[48]=0xFFFFFF;
    pallete[49]=0xA6FCFF;
    pallete[50]=0xB3ECFF;
    pallete[51]=0xDAABEB;
    pallete[52]=0xFFA8F9;
    pallete[53]=0xFFABB3;
    pallete[54]=0xFFD2B0;
    pallete[55]=0xFFEFA6;
    pallete[56]=0xFFF79C;
    pallete[57]=0xD7E895;
    pallete[58]=0xA6EDAF;
    pallete[59]=0xA2F2DA;
    pallete[60]=0x99FFFC;
    pallete[61]=0xDDDDDD;
    pallete[62]=0x111111;
    pallete[63]=0x111111;
    
    /*{
     //0/8           1/9         2/A         3/B         4/C         5/D         6/E         7/F
     0x00808080, 0x00003DA6, 0x000012B0, 0x00440096, 0x00A1005E, 0x00C70028, 0x00BA0600, 0x008C1700, //0
     0x005C2F00, 0x00104500, 0x00054A00, 0x0000472E, 0x00004166, 0x00000000, 0x00050505, 0x00050505,
     
     0x00C7C7C7, 0x000077FF, 0x002155FF, 0x008237FA, 0x00EB2FB5, 0x00FF2950, 0x00FF2200, 0x00D63200, //1
     0x00C46200, 0x00358000, 0x00058F00, 0x00008A55, 0x000099CC, 0x00212121, 0x00090909, 0x00090909,
     
     0x00FFFFFF, 0x000FD7FF, 0x0069A2FF, 0x00D480FF, 0x00FF45F3, 0x00FF618B, 0x00FF8833, 0x00FF9C12, //2
     0x00FABC20, 0x009FE30E, 0x002BF035, 0x000CF0A4, 0x0005FBFF, 0x005E5E5E, 0x000D0D0D, 0x000D0D0D,
     
     0x00FFFFFF, 0x00A6FCFF, 0x00B3ECFF, 0x00DAABEB, 0x00FFA8F9, 0x00FFABB3, 0x00FFD2B0, 0x00FFEFA6, //3
     0x00FFF79C, 0x00D7E895, 0x00A6EDAF, 0x00A2F2DA, 0x0099FFFC, 0x00DDDDDD, 0x00111111, 0x00111111
     };*/
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