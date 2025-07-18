#ifndef EMULATORTABWIDGET_H
#define EMULATORTABWIDGET_H

#include <QWidget>
#include <QProcess>
#include <QListWidgetItem>
#include "emudata.h"

namespace Ui {
class EmulatorTabWidget;
}

class EmulatorTabWidget : public QWidget
{
    Q_OBJECT

public:
    explicit EmulatorTabWidget(EmuData* emu, QWidget *parent = nullptr);
    ~EmulatorTabWidget();

private slots:
    void launchSelectedGame(QListWidgetItem* item);
    void on_launchButton_clicked();
    void addGameToEmulator();

private:
    Ui::EmulatorTabWidget *ui;
    EmuData* emulatorData;
};

#endif // EMULATORTABWIDGET_H
