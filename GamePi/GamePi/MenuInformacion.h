#ifndef MENUINFORMACION_H
#define MENUINFORMACION_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class MenuInformacion;
}

class MenuInformacion : public QMainWindow
{
    Q_OBJECT

public:
    explicit MenuInformacion(QWidget *parent = 0);
    ~MenuInformacion();
    virtual void closeEvent(QCloseEvent*);
    static void empezarReloj () {
        MenuInformacion::comienzo = time(0);
    }
    static void terminarReloj () {
        long double previo = MenuInformacion::leer();
        if (MenuInformacion::comienzo != 0) {
            long double final = time(0);
            previo += (final - MenuInformacion::comienzo);
        }
        escribir(previo);
    }

private:
    static long double comienzo;
    static long double previo;
    static const QString archivoTimer;
    static long double leer () {
        long double temp = 0;
        QFile file(MenuInformacion::archivoTimer);
        if (file.exists())
            if (file.open(QFile::ReadOnly | QFile::Text)) {
                QTextStream qts(&file);
                temp = qts.readLine().toDouble();
                file.close();
            } else qDebug() << "no pudo abrir "+ MenuInformacion::archivoTimer;

        return temp;
    }
    static void escribir (long double tiempo) {
        QFile file(MenuInformacion::archivoTimer);
            if (file.open(QFile::WriteOnly | QFile::Text)) {
                QTextStream qts(&file);
                qts << QString::number((double)tiempo);
                file.close();
            } else qDebug() << "no pudo abrir "+ MenuInformacion::archivoTimer;
    }

    Ui::MenuInformacion *ui;

private slots:
    void creditos ();
};

#endif // MENUINFORMACION_H
