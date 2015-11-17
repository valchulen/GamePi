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
    mb = new MenuBiblioteca ();
    mb->show();
}

void MenuPrincipal::informacion() {
}

void MenuPrincipal::opciones() {
}
