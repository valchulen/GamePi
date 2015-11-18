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
    botones = new vector<QPushButton*>;
    BuscarArchivos(this->path);
}

MenuBiblioteca::~MenuBiblioteca()
{
    delete ui;
}

void MenuBiblioteca::BuscarArchivos(QString path) {
    QDirIterator* dir = new QDirIterator (path, QDirIterator::Subdirectories);
    while (dir->hasNext()) {
        //qDebug() << dir->filePath();
        if (dir->fileInfo().isFile() && dir->fileName().endsWith(".nes", Qt::CaseInsensitive))
            CrearArchivo(dir->fileName());
        dir->next();
    }
}

void MenuBiblioteca::CrearArchivo(QString filename) {
    QPushButton* b = new QPushButton(filename);
    b->setStyleSheet("background-color: rgb(0, 0, 0); color: rgb(255, 255, 255);");
    connect(b, SIGNAL(released()), this, SLOT(exec()));
    this->ui->verticalLayout->addWidget(b);
    this->botones->push_back(b);
}

void MenuBiblioteca::exec() {
    for (std::vector<QPushButton*>::iterator it = this->botones->begin(); it != this->botones->end(); ++it)
        ((QPushButton*)(*it))->hide();
    //qDebug() << (this->path + "/" + ((QPushButton*)sender())->text());
    ui->myLabel->show();
    thread = new Thread(ui->myLabel, (this->path + "/" + ((QPushButton*)sender())->text()));
    MenuInformacion::empezarReloj();
    thread->start();
}

void MenuBiblioteca::closeEvent(QCloseEvent * event) {
    thread->play = false;
    MenuInformacion::terminarReloj();
    MenuPrincipal* mp = new  MenuPrincipal;
    mp->show();
    this->close();
}
