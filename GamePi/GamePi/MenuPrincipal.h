#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QWidget>
#include "MenuBiblioteca.h"
#include "MenuOpciones.h"
#include "MenuInformacion.h"

namespace Ui {
class MenuPrincipal;
}

class MenuPrincipal : public QWidget
{
    Q_OBJECT

public:
    explicit MenuPrincipal(QWidget *parent = 0);
    ~MenuPrincipal();

private:
    Ui::MenuPrincipal *ui;
    MenuBiblioteca* mb;
    MenuInformacion* mi;
    MenuOpciones* mo;

private slots:
    void biblioteca ();
    void informacion ();
    void opciones ();
};

#endif // MENUPRINCIPAL_H
