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
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuInformacion
{
public:
    QWidget *centralwidget;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QPushButton *btnCreditos;

    void setupUi(QMainWindow *MenuInformacion)
    {
        if (MenuInformacion->objectName().isEmpty())
            MenuInformacion->setObjectName(QStringLiteral("MenuInformacion"));
        MenuInformacion->resize(400, 300);
        MenuInformacion->setStyleSheet(QStringLiteral("background-color: rgb(2, 2, 2);"));
        centralwidget = new QWidget(MenuInformacion);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        label = new QLabel(centralwidget);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(120, 0, 165, 71));
        label->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/InformacionT.png);"));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 70, 171, 61));
        label_2->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/HorasTotalesJugadas.png);"));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(60, 130, 171, 81));
        label_3->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/JuegoFavorito.png);"));
        btnCreditos = new QPushButton(centralwidget);
        btnCreditos->setObjectName(QStringLiteral("btnCreditos"));
        btnCreditos->setGeometry(QRect(110, 210, 171, 81));
        btnCreditos->setStyleSheet(QStringLiteral("background-image: url(:/Imagines Finales/Creditos.png);"));
        MenuInformacion->setCentralWidget(centralwidget);

        retranslateUi(MenuInformacion);

        QMetaObject::connectSlotsByName(MenuInformacion);
    } // setupUi

    void retranslateUi(QMainWindow *MenuInformacion)
    {
        MenuInformacion->setWindowTitle(QApplication::translate("MenuInformacion", "MainWindow", 0));
        label->setText(QString());
        label_2->setText(QString());
        label_3->setText(QString());
        btnCreditos->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class MenuInformacion: public Ui_MenuInformacion {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUINFORMACION_H
