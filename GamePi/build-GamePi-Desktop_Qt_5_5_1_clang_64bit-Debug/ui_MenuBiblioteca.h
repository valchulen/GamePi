/********************************************************************************
** Form generated from reading UI file 'MenuBiblioteca.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MENUBIBLIOTECA_H
#define UI_MENUBIBLIOTECA_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MenuBiblioteca
{
public:
    QWidget *centralwidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;

    void setupUi(QMainWindow *MenuBiblioteca)
    {
        if (MenuBiblioteca->objectName().isEmpty())
            MenuBiblioteca->setObjectName(QStringLiteral("MenuBiblioteca"));
        MenuBiblioteca->resize(399, 296);
        centralwidget = new QWidget(MenuBiblioteca);
        centralwidget->setObjectName(QStringLiteral("centralwidget"));
        verticalLayoutWidget = new QWidget(centralwidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(0, 0, 401, 301));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        MenuBiblioteca->setCentralWidget(centralwidget);

        retranslateUi(MenuBiblioteca);

        QMetaObject::connectSlotsByName(MenuBiblioteca);
    } // setupUi

    void retranslateUi(QMainWindow *MenuBiblioteca)
    {
        MenuBiblioteca->setWindowTitle(QApplication::translate("MenuBiblioteca", "MainWindow", 0));
    } // retranslateUi

};

namespace Ui {
    class MenuBiblioteca: public Ui_MenuBiblioteca {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MENUBIBLIOTECA_H
