#include "MenuPrincipal.h"
#include "ui_MenuPrincipal.h"
#include "MenuInformacion.h"
#include "MenuOpciones.h"

MenuPrincipal::MenuPrincipal(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::MenuPrincipal)
{
    ui->setupUi(this);

    connect(ui->btnBiblioteca, SIGNAL(released()), this, SLOT(biblioteca()));
    connect(ui->btnInformacion, SIGNAL(released()), this, SLOT(informacion()));
    connect(ui->btnOpciones, SIGNAL(released()), this, SLOT(opciones()));
}

MenuPrincipal::~MenuPrincipal()
{
    delete ui;
}

void MenuPrincipal::biblioteca() {
    // link a biblio
}

void MenuPrincipal::informacion() {
    MenuInformacion mi;
    mi.show();
    this->hide();
}

void MenuPrincipal::opciones() {
    MenuOpciones mo;
    mo.show();
}
