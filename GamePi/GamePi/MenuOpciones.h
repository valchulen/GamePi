#ifndef MENUOPCIONES_H
#define MENUOPCIONES_H

#include <QMainWindow>

namespace Ui {
class MenuOpciones;
}

class MenuOpciones : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuOpciones(QWidget *parent = 0);
    ~MenuOpciones();
    virtual void closeEvent(QCloseEvent*);

private:
    Ui::MenuOpciones *ui;
};

#endif // MENUOPCIONES_H
