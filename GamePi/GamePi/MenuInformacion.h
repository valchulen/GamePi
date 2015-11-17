#ifndef MENUINFORMACION_H
#define MENUINFORMACION_H

#include <QWidget>

namespace Ui {
class MenuInformacion;
}

class MenuInformacion : public QWidget
{
    Q_OBJECT

public:
    explicit MenuInformacion(QWidget *parent = 0);
    ~MenuInformacion();

private:
    Ui::MenuInformacion *ui;
};

#endif // MENUINFORMACION_H
