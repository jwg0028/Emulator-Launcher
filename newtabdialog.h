#ifndef NEWTABDIALOG_H
#define NEWTABDIALOG_H

#include "emudata.h"
#include <QDialog>

namespace Ui {
class NewTabDialog;
}

class NewTabDialog : public QDialog
{
    Q_OBJECT

public:
    explicit NewTabDialog(QWidget *parent = nullptr);
    ~NewTabDialog();

    EmuData getEmuData() const;

    QString getEmulatorName() const;
    QString getExecutablePath() const;

private slots:
    void on_pushButton_clicked();

    void on_buttonBox_accepted();

private:
    Ui::NewTabDialog *ui;
    EmuData emuData;
};

#endif // NEWTABDIALOG_H
