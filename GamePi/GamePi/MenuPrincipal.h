#ifndef MENUPRINCIPAL_H
#define MENUPRINCIPAL_H

#include <QWidget>

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
private slots:
    void biblioteca ();
    void informacion ();
    void opciones ();
};

#endif // MENUPRINCIPAL_H
