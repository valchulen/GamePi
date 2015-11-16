//
//  Pines.hpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 29/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#ifndef Pines_h
#define Pines_h

#include "RAM.h"

#define A       13
#define B       15
#define LEFT    3
#define RIGHT   5
#define UP      11
#define DOWN    7
#define SELECT  16
#define START   12

class Pines {
public:
    Pines();
    u8 update();
private:
    bool estadoA;
    bool estadoB;
    bool estadoL;
    bool estadoR;
    bool estadoU;
    bool estadoD;
    bool estadoSta;
    bool estadoSel;
    
};


#endif /* Pines_hpp */
