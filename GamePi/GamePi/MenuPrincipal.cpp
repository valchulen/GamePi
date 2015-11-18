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
    this->close();
}

void MenuPrincipal::informacion() { //todavia no andan, tiene que ser QMainWindow
    mi = new MenuInformacion;
    mi->show();
    this->close();
}

void MenuPrincipal::opciones() {
    mo = new MenuOpciones;
    mo->show();
    this->close();
}
