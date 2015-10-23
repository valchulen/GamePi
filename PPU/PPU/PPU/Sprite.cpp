//
//  Sprite.cpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 16/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#include "Sprite.h"

Sprite::Sprite(u8* ptr) {
    this->Y = *ptr;
    this->tileNum = *(ptr+1);
    this->data = *(ptr+2);
    this->X = *(ptr+3);
}