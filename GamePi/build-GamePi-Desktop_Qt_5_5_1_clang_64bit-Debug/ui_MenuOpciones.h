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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuOpciones
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QPushButton *btnPantalla;

    void setupUi(QMainWindow *MenuOpciones)
    {
        if (MenuOpciones->objectName().isEmpty())
            MenuOpciones->setObjectName(QStringLiteral("MenuOpciones"));
        MenuOpciones->resize(400, 300);
        MenuOpciones->setStyleSheet(QStringLiteral("background-color: rgb(0, 0, 0);"));
        centralwidget = new QWidget(MenuOpciones);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(110, 30, 161, 81));
        label->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/OpcionesT.png);"));
        btnPantalla = new QPushButton(centralwidget);
        btnPantalla->setObjectName(QStringLiteral("btnPantalla"));
        btnPantalla->setGeometry(QRect(110, 150, 171, 81));
        btnPantalla->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Pantallab.png);"));
        MenuOpciones->setCentralWidget(centralwidget);

        retranslateUi(MenuOpciones);

        QMetaObject::connectSlotsByName(MenuOpciones);
    } // setupUi

    void retranslateUi(QMainWindow *MenuOpciones)
    {
        MenuOpciones->setWindowTitle(QApplication::translate("MenuOpciones", "MainWindow", 0));
        label->setText(QString());
        btnPantalla->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuOpciones: public Ui_MenuOpciones {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUOPCIONES_H
