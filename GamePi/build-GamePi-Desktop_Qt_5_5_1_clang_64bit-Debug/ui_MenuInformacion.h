/********************************************************************************
** Form generated from reading UI file 'MenuInformacion.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUINFORMACION_H
#define UI_MENUINFORMACION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuInformacion
{
public:
    QLabel *lblInformacion;
    QLabel *lblHorasJugads;
    QLabel *lblJuegoFavorito;
    QPushButton *btnCreditos;

    void setupUi(QWidget *MenuInformacion)
    {
        if (MenuInformacion->objectName().isEmpty())
            MenuInformacion->setObjectName(QStringLiteral("MenuInformacion"));
        MenuInformacion->resize(400, 300);
        MenuInformacion->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lblInformacion = new QLabel(MenuInformacion);
        lblInformacion->setObjectName(QStringLiteral("lblInformacion"));
        lblInformacion->setGeometry(QRect(130, 10, 171, 61));
        lblInformacion->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/InformacionT.png);"));
        lblHorasJugads = new QLabel(MenuInformacion);
        lblHorasJugads->setObjectName(QStringLiteral("lblHorasJugads"));
        lblHorasJugads->setGeometry(QRect(130, 70, 171, 71));
        lblHorasJugads->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/HorasTotalesJugadas.png);"));
        lblJuegoFavorito = new QLabel(MenuInformacion);
        lblJuegoFavorito->setObjectName(QStringLiteral("lblJuegoFavorito"));
        lblJuegoFavorito->setGeometry(QRect(130, 140, 171, 71));
        lblJuegoFavorito->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/JuegoFavorito.png);"));
        btnCreditos = new QPushButton(MenuInformacion);
        btnCreditos->setObjectName(QStringLiteral("btnCreditos"));
        btnCreditos->setGeometry(QRect(130, 210, 171, 81));
        btnCreditos->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Creditos.png);"));

        retranslateUi(MenuInformacion);

        QMetaObject::connectSlotsByName(MenuInformacion);
    } // setupUi

    void retranslateUi(QWidget *MenuInformacion)
    {
        MenuInformacion->setWindowTitle(QApplication::translate("MenuInformacion", "Form", 0));
        lblInformacion->setText(QString());
        lblHorasJugads->setText(QString());
        lblJuegoFavorito->setText(QString());
        btnCreditos->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuInformacion: public Ui_MenuInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUINFORMACION_H
