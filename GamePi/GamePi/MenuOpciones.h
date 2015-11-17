#ifndef MENUOPCIONES_H
#define MENUOPCIONES_H

#include <QWidget>

namespace Ui {
class MenuOpciones;
}

class MenuOpciones : public QWidget
{
    Q_OBJECT

public:
    explicit MenuOpciones(QWidget *parent = 0);
    ~MenuOpciones();

private:
    Ui::MenuOpciones *ui;
};

#endif // MENUOPCIONES_H
