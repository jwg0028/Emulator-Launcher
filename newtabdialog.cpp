#include "newtabdialog.h"
#include "ui_newtabdialog.h"
#include <QProcess>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

NewTabDialog::NewTabDialog(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::NewTabDialog)
{
    ui->setupUi(this);
}

NewTabDialog::~NewTabDialog()
{
    delete ui;
}

QString NewTabDialog::getEmulatorName() const {
    return ui->lineEdit->text();
}

QString NewTabDialog::getExecutablePath() const {
    return ui->lineEdit_2->text();
}



void NewTabDialog::on_pushButton_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Select Emulator EXE", "G:/Emulator", "Game Files (*.exe)");

    if (!file.isEmpty()) {
        QString nativePath = QDir::toNativeSeparators(file);  // Converts to G:\Emulator\Whatever.exe
        ui->lineEdit_2->setText(nativePath);
        qDebug() << "Selected EXE path:" << nativePath;
    }
}


void NewTabDialog::on_buttonBox_accepted()
{
    emuData = EmuData(getEmulatorName(), getExecutablePath(), ui->lineEdit_3->text());
}

EmuData NewTabDialog::getEmuData() const {
    return emuData;
}
