#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMap>
#include "emudata.h"  // Include this to use EmuData

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:

    void on_openDolphin_clicked();

    void on_chooseDolphin_clicked();

    void on_tabWidget_currentChanged(int index);

    void on_debugButton_clicked();

    void updateFile();

private:
    Ui::MainWindow *ui;

    QMap<QString, EmuData> emulatorMap;

    void loadEmulatorsFromFile(const QString& filePath);
protected:
    void closeEvent(QCloseEvent *event) override;
};
#endif // MAINWINDOW_H
