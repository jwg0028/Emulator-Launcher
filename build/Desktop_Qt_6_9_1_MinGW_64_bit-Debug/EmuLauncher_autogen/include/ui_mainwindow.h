/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *tab;
    QPushButton *chooseDolphin;
    QPushButton *openDolphin;
    QPushButton *debugButton;
    QWidget *tab_2;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 600);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 801, 601));
        tab = new QWidget();
        tab->setObjectName("tab");
        chooseDolphin = new QPushButton(tab);
        chooseDolphin->setObjectName("chooseDolphin");
        chooseDolphin->setGeometry(QRect(10, 30, 111, 71));
        openDolphin = new QPushButton(tab);
        openDolphin->setObjectName("openDolphin");
        openDolphin->setGeometry(QRect(130, 30, 111, 71));
        debugButton = new QPushButton(tab);
        debugButton->setObjectName("debugButton");
        debugButton->setGeometry(QRect(10, 120, 231, 61));
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName("tab_2");
        tabWidget->addTab(tab_2, QString());
        MainWindow->setCentralWidget(centralwidget);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        chooseDolphin->setText(QCoreApplication::translate("MainWindow", "open file", nullptr));
        openDolphin->setText(QCoreApplication::translate("MainWindow", "open dolphin", nullptr));
        debugButton->setText(QCoreApplication::translate("MainWindow", "Debug Print", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QCoreApplication::translate("MainWindow", "Debug Tab", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QCoreApplication::translate("MainWindow", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
