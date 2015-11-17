#ifndef MENUBIBLIOTECA_H
#define MENUBIBLIOTECA_H

#include <QMainWindow>

namespace Ui {
class MenuBiblioteca;
}

class MenuBiblioteca : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuBiblioteca(QWidget *parent = 0);
    ~MenuBiblioteca();

private:
    Ui::MenuBiblioteca *ui;
    void BuscarArchivos(QString);
    void CrearArchivo (QString);
    QString path;
private slots:
    void exec ();
};

#endif // MENUBIBLIOTECA_H
