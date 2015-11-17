#include "MenuBiblioteca.h"
#include "ui_MenuBiblioteca.h"
#include <QDirIterator>
#include <QPushButton>
#include <QDebug>
#include "thread.h"
#include "MenuPrincipal.h"

MenuBiblioteca::MenuBiblioteca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuBiblioteca)
{
    ui->setupUi(this);
    ui->myLabel->hide();
    BuscarArchivos("/Users/valchu/Documents/GamePi/GamePi");
}

MenuBiblioteca::~MenuBiblioteca()
{
    delete ui;
}

void MenuBiblioteca::BuscarArchivos(QString path) {
    QDirIterator dir (path, QDirIterator::Subdirectories);
    this->path = path;
    while (dir.hasNext()) {
        if (dir.fileInfo().isFile() && dir.fileName().endsWith(".nes", Qt::CaseInsensitive))
            CrearArchivo(dir.fileName());
        dir.next();
    }
}

void MenuBiblioteca::CrearArchivo(QString filename) {
    QPushButton* b = new QPushButton(filename);
    connect(b, SIGNAL(released()), this, SLOT(exec()));
    this->ui->verticalLayout->addWidget(b);
    this->botones.push_back(b);
}

void MenuBiblioteca::exec() {
    for (std::vector<QPushButton*>::iterator it = this->botones.begin(); it != this->botones.end(); ++it)
        ((QPushButton*)(*it))->hide();
    //qDebug() << (this->path + "/" + ((QPushButton*)sender())->text());
    ui->myLabel->show();
    thread = new Thread(ui->myLabel, (this->path + "/" + ((QPushButton*)sender())->text()));
}

void MenuBiblioteca::closeEvent(QCloseEvent * event) {
    MenuPrincipal* mp = new  MenuPrincipal;
    mp->show();
    this->close();
}
