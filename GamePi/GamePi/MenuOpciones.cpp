#include "MenuOpciones.h"
#include "ui_MenuOpciones.h"
#include "MenuPrincipal.h"
#include <QMessageBox>

MenuOpciones::MenuOpciones(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuOpciones)
{
    ui->setupUi(this);

    connect(ui->btnPantalla, SIGNAL(released()), this, SLOT(especificaciones()));
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

void MenuOpciones::especificaciones() {
    QMessageBox* credits = new QMessageBox;
    const QString s = "Especificaciones:"
                      "\nModelo MI0283QT-11"
                      "\nTamaño: 2.83’’"
                      "\nResolucion:240x320 pixel"
                      "\nDimensión: 50.2x69.3 mm"
                      "\nInterfaz: CPU paralelo/serial/RGB"
                      "\nTipo: TFT"
                      "\nConexión: 50 pin ZIF o,5mm";
    credits->setText(s);
    credits->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);");
    credits->show();
}
