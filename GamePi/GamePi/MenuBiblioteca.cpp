#include "MenuBiblioteca.h"
#include "ui_MenuBiblioteca.h"
#include <QDirIterator>
#include <QPushButton>
#include <QDebug>

MenuBiblioteca::MenuBiblioteca(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MenuBiblioteca)
{
    ui->setupUi(this);
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
}

void MenuBiblioteca::exec() {
    qDebug() << (this->path + "/" + ((QPushButton*)sender())->text());
}
