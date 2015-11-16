#ifndef THREAD_H
#define THREAD_H

#include <QThread>
#include <QLabel>
#include "mainwindow.h"
#include "NES.h"
#include "PPU.h"
#include "RAM.h"
#include "VRAM.h"

class Thread : public QThread
{
public:
    Thread(QLabel*, QString);
protected:
    void run ();
private:
    QLabel *myLabel = NULL;
    void render ();
    void exec ();

    NES* cpu = NULL;
    PPU* ppu = NULL;
    RAM ram;
    VRAM vram;
};

#endif // THREAD_H
