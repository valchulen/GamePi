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
    bool play = true;
    while (play) {
        exec ();
        render ();
        delay(3000);
    }
}
void Thread::delay( int millisecondsToWait )
{
    QTime dieTime = QTime::currentTime().addMSecs( millisecondsToWait );
    while( QTime::currentTime() < dieTime )
    {
        QCoreApplication::processEvents( QEventLoop::AllEvents, 100 );
    }
}

void Thread::exec() {
    cpu->exec();
    qDebug() << cpu->estado().c_str();
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
