#include "MenuPrincipal.h"
#include "ui_MenuPrincipal.h"

MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);
}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}
