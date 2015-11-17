#include "MenuInformacion.h"
#include "ui_MenuInformacion.h"

MenuInformacion::MenuInformacion(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuInformacion)
{
    ui->setupUi(this);
}

MenuInformacion::~MenuInformacion()
{
    delete ui;
}
