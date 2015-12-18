#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QLabel>
#include "NES.h"
#include "PPU.h"
#include "RAM.h"
#include "VRAM.h"
//#include "Pines.h"

class Thread : public QThread
{
public:
    Thread(QLabel*, QString);
    bool play = true;
protected:
    void run ();
private:
    QLabel *myLabel = NULL;
    void render ();
    void exec ();
    void delay(int);

    NES* cpu = NULL;
    PPU* ppu = NULL;
    RAM ram;
    VRAM vram;
    //Pines pines;
};

#endif // THREAD_H
