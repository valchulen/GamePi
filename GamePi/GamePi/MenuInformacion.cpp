#include "MenuInformacion.h"
#include "ui_MenuInformacion.h"
#include "MenuPrincipal.h"

MenuInformacion::MenuInformacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuInformacion)
{
    ui->setupUi(this);
}

MenuInformacion::~MenuInformacion()
{
    delete ui;
}

void MenuInformacion::closeEvent(QCloseEvent * event) {
    MenuPrincipal* mp = new  MenuPrincipal;
    mp->show();
    this->close();
}
