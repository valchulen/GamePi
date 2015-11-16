#include "thread.h"
#include "Input.h"

const QSize s(32* 8 , 30 * 8 );
QImage myImage(s, QImage::Format_RGB32);

Thread::Thread(QLabel* mw, QString s)
{
    this->myLabel = mw;
    Input i (s, &ram, &vram);
    cpu = new NES (&ram);
    ppu = new PPU (&ram, &vram);
}

void Thread::run() {
    bool a = true;
    while (a) {
        exec ();
        render ();
        a = false;
    }
}

void Thread::exec() {
    cpu->exec();
}

void Thread::render() {
    ppu->render();
    for (int x = 0; x < 32*8 ; x++) {
        for (int y = 0; y < 30*8 ; y++){
            myImage.setPixel(x, y, ppu->pixels[x][y]);
        }
    }
    myLabel->setPixmap(QPixmap::fromImage(myImage));
}
