#include "MenuOpciones.h"
#include "ui_MenuOpciones.h"
#include "MenuPrincipal.h"

MenuOpciones::MenuOpciones(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuOpciones)
{
    ui->setupUi(this);
}

MenuOpciones::~MenuOpciones()
{
    delete ui;
}

void MenuOpciones::closeEvent(QCloseEvent * event) {
    MenuPrincipal* mp = new  MenuPrincipal;
    mp->show();
    this->close();
}
