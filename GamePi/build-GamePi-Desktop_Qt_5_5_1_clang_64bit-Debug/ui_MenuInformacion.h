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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuInformacion
{
public:
    QWidget *centralwidget;

    void setupUi(QMainWindow *MenuInformacion)
    {
        if (MenuInformacion->objectName().isEmpty())
            MenuInformacion->setObjectName(QStringLiteral("MenuInformacion"));
        MenuInformacion->resize(400, 300);
        centralwidget = new QWidget(MenuInformacion);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        MenuInformacion->setCentralWidget(centralwidget);

        retranslateUi(MenuInformacion);

        QMetaObject::connectSlotsByName(MenuInformacion);
    } // setupUi

    void retranslateUi(QMainWindow *MenuInformacion)
    {
        MenuInformacion->setWindowTitle(QApplication::translate("MenuInformacion", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuInformacion: public Ui_MenuInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUINFORMACION_H
