#include "thread.h"

const QSize s(32* 8 , 30 * 8 );
QImage myImage(s, QImage::Format_ARGB32);
unsigned char i = 0;
Thread::Thread(QLabel* mw)
{
    this->myLabel = mw;
}

void Thread::run() {
    while (true)
        render();
}

void Thread::render() {
    for (int x = 0; x < 32*8 ; x++) {
        for (int y = 0; y < 30*8
             ; y++){
            myImage.setPixel(x, y, 0xff000000 + x + (y * 0xFF)+ (i* 0xff00));
        }
    }
    i++;
    myLabel->setPixmap(QPixmap::fromImage(myImage));
}
