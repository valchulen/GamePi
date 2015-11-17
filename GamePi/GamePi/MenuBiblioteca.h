#ifndef MENUBIBLIOTECA_H
#define MENUBIBLIOTECA_H

#include <QMainWindow>
#include <vector>
#include <QPushButton>
#include <thread.h>

namespace Ui {
class MenuBiblioteca;
}

class MenuBiblioteca : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuBiblioteca(QWidget *parent = 0);
    ~MenuBiblioteca();
    virtual void closeEvent(QCloseEvent*);

private slots:
    void exec ();

private:
    Ui::MenuBiblioteca *ui;
    void BuscarArchivos(QString);
    void CrearArchivo (QString);
    QString path;
    std::vector<QPushButton*> botones;
    Thread* thread;
};

#endif // MENUBIBLIOTECA_H
