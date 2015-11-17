#ifndef MENUINFORMACION_H
#define MENUINFORMACION_H

#include <QMainWindow>

namespace Ui {
class MenuInformacion;
}

class MenuInformacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuInformacion(QWidget *parent = 0);
    ~MenuInformacion();

private:
    Ui::MenuInformacion *ui;
};

#endif // MENUINFORMACION_H
