#include "MenuBiblioteca.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MenuBiblioteca w;

    w.show();

    return a.exec();
}
