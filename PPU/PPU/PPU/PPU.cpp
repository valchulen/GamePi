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


PPU::PPU(RAM* ram, Input* i){
    this->ram = ram;
    this->vram = new VRAM(i);
    dir2000 = ram->toRealAdr(intToMem(0x2000));
    dir2001 = ram->toRealAdr(intToMem(0x2001));
    dir2002 = ram->toRealAdr(intToMem(0x2002));
    cargarPallete();
    cargarCHR(i);
    for (int i = 0; i < 0x1FFF * 2; i+= 32) {
        makePattern(i/32, patterns+i);
    }
}

PPU::~PPU() {
}

void PPU::cargarCHR (Input* i) {
    for (int j = 0; j < i->chr_8_rom * 8192; j++) {
        this->vram->write(j, i->chr_rom[j]);
    }
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
    
}
void PPU::updatePallete(){
    for (int i = 0; i < 16; i++) {
        if (getDsiplayType() == 0) { //color display
            BGP[i] = pallete[(vram->read(0x3F00 + i) & 63)]; //saca el indice y los busca en los RGB
        }
        else { //monocolor display
            BGP[i] = pallete[(vram->read(0x3F00 + i) & 32)];
        }
    }
    for (int i = 0; i < 16; i++) {
        if (getDsiplayType() == 0) {
            SprP[i] = pallete[(vram->read(0x3F10 + i) & 63)];
        }
        else {
            SprP[i] = pallete[(vram->read(0x3F10 + i) & 32)];
        }
    }
}

void PPU::makePattern(int n, u8* arr) { //recibo el numero de pattern, tengo que limpiarlo
    //si usa la primera patterTable
    u8 temp[16];
    const int base = (n<<4); //aca sumo si usa la 0x1000, lo corro 4 porque tiene que empezar ahi
    for (int i = 0; i < 16; i++) {
        temp[i] = vram->read(base+i);
    }
    for (int i = 0; i < 32; i++) {
        arr[i] = 0;
    }
    for (int y = 0; y < 8; y++) {
        for (int x = 0; x < 8; x++) {
            const u8 index = ((y*8 + x) / 2);
            const u8 low = (temp[y] & (1<<x));
            const u8 high = (temp[y+8] & (1<<x));
            const u8 nFinal = (low | (high<<1))>>x;
            arr[index] |= nFinal<<(x % 2 == 0 ? 0 : 4); //podrian ser en vez de 0 y 4, 2 y 6 respectivamente
        }
    }
}

void PPU::makeTile(int adr) {
    
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
    return *dir2001 & 0x01; //0 = Colour display, 1 = Monochrome display
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