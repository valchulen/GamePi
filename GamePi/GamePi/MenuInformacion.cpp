#include "MenuInformacion.h"
#include "ui_MenuInformacion.h"
#include "MenuPrincipal.h"
#include <QMessageBox>

MenuInformacion::MenuInformacion(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuInformacion)
{
    ui->setupUi(this);

    connect(ui->btnCreditos, SIGNAL(released()), this, SLOT(creditos()));
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

void MenuInformacion::creditos() {
    QMessageBox* credits = new QMessageBox;
    const QString s = "Programadores:"
                      "\nEden Torres"
                      "\nValentin Paz Marcolla"
                      "\nGuido Lipina";
    credits->setText(s);
    credits->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);");
    credits->show();
}
