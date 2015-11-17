/********************************************************************************
** Form generated from reading UI file 'MenuOpciones.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUOPCIONES_H
#define UI_MENUOPCIONES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuOpciones
{
public:
    QLabel *lblOpciones;
    QPushButton *btnPantalla;

    void setupUi(QWidget *MenuOpciones)
    {
        if (MenuOpciones->objectName().isEmpty())
            MenuOpciones->setObjectName(QStringLiteral("MenuOpciones"));
        MenuOpciones->resize(400, 300);
        MenuOpciones->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        lblOpciones = new QLabel(MenuOpciones);
        lblOpciones->setObjectName(QStringLiteral("lblOpciones"));
        lblOpciones->setGeometry(QRect(128, 30, 161, 81));
        lblOpciones->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/OpcionesT.png);"));
        btnPantalla = new QPushButton(MenuOpciones);
        btnPantalla->setObjectName(QStringLiteral("btnPantalla"));
        btnPantalla->setGeometry(QRect(120, 110, 181, 81));
        btnPantalla->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Pantallab.png);"));

        retranslateUi(MenuOpciones);

        QMetaObject::connectSlotsByName(MenuOpciones);
    } // setupUi

    void retranslateUi(QWidget *MenuOpciones)
    {
        MenuOpciones->setWindowTitle(QApplication::translate("MenuOpciones", "Form", 0));
        lblOpciones->setText(QString());
        btnPantalla->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuOpciones: public Ui_MenuOpciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOPCIONES_H
