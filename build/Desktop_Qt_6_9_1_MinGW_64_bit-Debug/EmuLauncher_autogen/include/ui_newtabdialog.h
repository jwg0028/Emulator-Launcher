/********************************************************************************
** Form generated from reading UI file 'newtabdialog.ui'
**
** Created by: Qt User Interface Compiler version 6.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWTABDIALOG_H
#define UI_NEWTABDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_NewTabDialog
{
public:
    QDialogButtonBox *buttonBox;
    QLineEdit *lineEdit;
    QLineEdit *lineEdit_2;
    QPushButton *pushButton;
    QLineEdit *lineEdit_3;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;

    void setupUi(QDialog *NewTabDialog)
    {
        if (NewTabDialog->objectName().isEmpty())
            NewTabDialog->setObjectName("NewTabDialog");
        NewTabDialog->resize(400, 300);
        buttonBox = new QDialogButtonBox(NewTabDialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setGeometry(QRect(30, 240, 341, 32));
        buttonBox->setOrientation(Qt::Orientation::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::StandardButton::Cancel|QDialogButtonBox::StandardButton::Ok);
        lineEdit = new QLineEdit(NewTabDialog);
        lineEdit->setObjectName("lineEdit");
        lineEdit->setGeometry(QRect(50, 50, 181, 24));
        lineEdit_2 = new QLineEdit(NewTabDialog);
        lineEdit_2->setObjectName("lineEdit_2");
        lineEdit_2->setGeometry(QRect(50, 100, 181, 24));
        pushButton = new QPushButton(NewTabDialog);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(240, 100, 80, 24));
        lineEdit_3 = new QLineEdit(NewTabDialog);
        lineEdit_3->setObjectName("lineEdit_3");
        lineEdit_3->setGeometry(QRect(50, 150, 181, 24));
        label = new QLabel(NewTabDialog);
        label->setObjectName("label");
        label->setGeometry(QRect(50, 30, 101, 16));
        label_2 = new QLabel(NewTabDialog);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(50, 80, 101, 16));
        label_3 = new QLabel(NewTabDialog);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(50, 130, 101, 16));

        retranslateUi(NewTabDialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, NewTabDialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, NewTabDialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(NewTabDialog);
    } // setupUi

    void retranslateUi(QDialog *NewTabDialog)
    {
        NewTabDialog->setWindowTitle(QCoreApplication::translate("NewTabDialog", "Dialog", nullptr));
        pushButton->setText(QCoreApplication::translate("NewTabDialog", "Open File", nullptr));
        label->setText(QCoreApplication::translate("NewTabDialog", "Emulator Name:", nullptr));
        label_2->setText(QCoreApplication::translate("NewTabDialog", "Emulator Path:", nullptr));
        label_3->setText(QCoreApplication::translate("NewTabDialog", "Startup Options:", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewTabDialog: public Ui_NewTabDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWTABDIALOG_H
