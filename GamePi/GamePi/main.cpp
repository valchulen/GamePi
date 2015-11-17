#include "MenuOpciones.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuOpciones w;

    w.show();

    return a.exec();
}
