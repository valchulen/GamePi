/********************************************************************************
** Form generated from reading UI file 'MenuPrincipal.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUPRINCIPAL_H
#define UI_MENUPRINCIPAL_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuPrincipal
{
public:
    QLabel *lblGamePi;
    QPushButton *btnBiblioteca;
    QPushButton *btnOpciones;
    QPushButton *btnInformacion;

    void setupUi(QWidget *MenuPrincipal)
    {
        if (MenuPrincipal->objectName().isEmpty())
            MenuPrincipal->setObjectName(QStringLiteral("MenuPrincipal"));
        MenuPrincipal->resize(400, 300);
        MenuPrincipal->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lblGamePi = new QLabel(MenuPrincipal);
        lblGamePi->setObjectName(QStringLiteral("lblGamePi"));
        lblGamePi->setGeometry(QRect(110, 10, 161, 81));
        lblGamePi->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/GamePi.png);"));
        btnBiblioteca = new QPushButton(MenuPrincipal);
        btnBiblioteca->setObjectName(QStringLiteral("btnBiblioteca"));
        btnBiblioteca->setGeometry(QRect(110, 91, 171, 71));
        btnBiblioteca->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Bibliotecab.png);"));
        btnOpciones = new QPushButton(MenuPrincipal);
        btnOpciones->setObjectName(QStringLiteral("btnOpciones"));
        btnOpciones->setGeometry(QRect(110, 160, 171, 71));
        btnOpciones->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Opcionesb.png);"));
        btnInformacion = new QPushButton(MenuPrincipal);
        btnInformacion->setObjectName(QStringLiteral("btnInformacion"));
        btnInformacion->setGeometry(QRect(110, 230, 171, 71));
        btnInformacion->setCursor(QCursor(Qt::ArrowCursor));
        btnInformacion->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Informacionb.png);"));

        retranslateUi(MenuPrincipal);

        QMetaObject::connectSlotsByName(MenuPrincipal);
    } // setupUi

    void retranslateUi(QWidget *MenuPrincipal)
    {
        MenuPrincipal->setWindowTitle(QApplication::translate("MenuPrincipal", "Form", 0));
        lblGamePi->setText(QString());
        btnBiblioteca->setText(QString());
        btnOpciones->setText(QString());
        btnInformacion->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuPrincipal: public Ui_MenuPrincipal {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUPRINCIPAL_H
