/********************************************************************************
** Form generated from reading UI file 'emulatortabwidget.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EMULATORTABWIDGET_H
#define UI_EMULATORTABWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_EmulatorTabWidget
{
public:
    QPushButton *launchButton;
    QPushButton *emuFolderButton;
    QPushButton *romFolderButton;
    QListWidget *gameList;
    QPushButton *addGame;

    void setupUi(QWidget *EmulatorTabWidget)
    {
        if (EmulatorTabWidget->objectName().isEmpty())
            EmulatorTabWidget->setObjectName("EmulatorTabWidget");
        EmulatorTabWidget->resize(400, 218);
        launchButton = new QPushButton(EmulatorTabWidget);
        launchButton->setObjectName("launchButton");
        launchButton->setGeometry(QRect(10, 10, 131, 41));
        emuFolderButton = new QPushButton(EmulatorTabWidget);
        emuFolderButton->setObjectName("emuFolderButton");
        emuFolderButton->setGeometry(QRect(10, 70, 131, 41));
        romFolderButton = new QPushButton(EmulatorTabWidget);
        romFolderButton->setObjectName("romFolderButton");
        romFolderButton->setGeometry(QRect(10, 130, 131, 41));
        gameList = new QListWidget(EmulatorTabWidget);
        gameList->setObjectName("gameList");
        gameList->setGeometry(QRect(160, 10, 221, 171));
        addGame = new QPushButton(EmulatorTabWidget);
        addGame->setObjectName("addGame");
        addGame->setGeometry(QRect(300, 180, 80, 24));

        retranslateUi(EmulatorTabWidget);

        QMetaObject::connectSlotsByName(EmulatorTabWidget);
    } // setupUi

    void retranslateUi(QWidget *EmulatorTabWidget)
    {
        EmulatorTabWidget->setWindowTitle(QCoreApplication::translate("EmulatorTabWidget", "Form", nullptr));
        launchButton->setText(QCoreApplication::translate("EmulatorTabWidget", "Launch Emulator", nullptr));
        emuFolderButton->setText(QCoreApplication::translate("EmulatorTabWidget", "Open Emulator Folder", nullptr));
        romFolderButton->setText(QCoreApplication::translate("EmulatorTabWidget", "Open ROM Folder", nullptr));
        addGame->setText(QCoreApplication::translate("EmulatorTabWidget", "Add Game", nullptr));
    } // retranslateUi

};

namespace Ui {
    class EmulatorTabWidget: public Ui_EmulatorTabWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EMULATORTABWIDGET_H
