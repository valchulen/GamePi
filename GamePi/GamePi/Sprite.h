//
//  Sprite.hpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 16/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#ifndef Sprite_h
#define Sprite_h

#include <stdio.h>
#include "Types.h"

class Sprite {
public:
    Sprite (u8*);
    u8 Y = 0;
    u8 X = 0;
    u8 tileNum = 0;
    u8 data = 0;
};

#endif /* Sprite_hpp */
