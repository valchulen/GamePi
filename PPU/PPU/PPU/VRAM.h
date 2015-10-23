//
//  VRAM.hpp
//  PPU
//
//  Created by Valentin Paz Marcolla on 16/10/15.
//  Copyright © 2015 GamePi. All rights reserved.
//

#ifndef VRAM_h
#define VRAM_h

#include <stdio.h>
#include "Types.h"
#include "Input.h"

class VRAM {
#define PT0_SIZE 0x1000
#define PT0_START 0x0000
    u8 PT0[PT0_SIZE];
#define PT0_END 0x0FFF
    
#define PT1_SIZE 0x1000
#define PT1_START 0x1000
    u8 PT1[PT1_SIZE];
#define PT1_END 0x2FFF
    
#define NT0_SIZE 0x03C0
#define NT0_START 0x2000
    u8 NT0[NT0_SIZE];
#define NT0_END 0x23BF
    
#define AT0_SIZE 0x0040
#define AT0_START 0x23C0
    u8 AT0[AT0_SIZE];
#define AT0_END 0x23FF
    
#define NT1_SIZE 0x03C0
#define NT1_START 0x2400
    u8 NT1[NT1_SIZE];
#define NT1_END 0x27BF
    
#define AT1_SIZE 0x0040
#define AT1_START 0x27C0
    u8 AT1[AT1_SIZE];
#define AT1_END 0x27FF
    
#define NT2_SIZE 0x03C0
#define NT2_START 0x2800
    u8 NT2[NT2_SIZE];
#define NT2_END 0x2BBF
    
#define AT2_SIZE 0x0040
#define AT2_START 0x2BC0
    u8 AT2[AT2_SIZE];
#define AT2_END 0x2BFF
    
#define NT3_SIZE 0x03C0
#define NT3_START 0x2C00
    u8 NT3[NT3_SIZE];
#define NT3_END 0x2FBF
    
#define AT3_SIZE 0x0040
#define AT3_START 0x2FC0
    u8 AT3[AT3_SIZE];
#define AT3_END 0x2FFF
    
#define VRAM_MIR0_SIZE 0x0F00
#define VRAM_MIR0_START 0x3000
#define VRAM_MIR0_END 0x3EFF
    
#define IP1_SIZE 0x0010
#define IP1_START 0x3F00
    u8 IP1[IP1_SIZE];
#define IP1_END 0x3F0F
    
#define SP1_SIZE 0x0010
#define SP1_START 0x3F10
    u8 SP1[SP1_SIZE];
#define SP1_END 0x3F1F
    
#define PM_MIR_START 0x3F20
#define PM_MIR_END 0x3FFF
    
public:
    u8 read(const int);
    void write(const int, const u8);
    VRAM(const Input*);
    bool horizontal = true;
    
private:
    u8* getVRAMAdr(const int);
};

#endif /* VRAM_hpp */
