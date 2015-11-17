#include "MenuOpciones.h"
#include "ui_MenuOpciones.h"

MenuOpciones::MenuOpciones(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuOpciones)
{
    ui->setupUi(this);
}

MenuOpciones::~MenuOpciones()
{
    delete ui;
}
