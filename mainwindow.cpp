#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include "newtabdialog.h"
#include "emudata.h"
#include "emulatortabwidget.h"
#include <QCloseEvent>
#include <QProcess>
#include <QTextStream>
#include <QDebug>
#include <QFileDialog>

QString romPath;  // stores the selected ROM file path

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    loadEmulatorsFromFile("emulators.txt");
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadEmulatorsFromFile(const QString& filePath)
{
    QFile file(filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qDebug() << "Current working directory:" << QDir::currentPath();
        qDebug() << "Could not open file:" << filePath;
        return;
    }

    QTextStream in(&file);
    QString currentEmulatorName;
    int gameCount = 0;

    while (!in.atEnd()) {
        QString line = in.readLine().trimmed();
        qDebug() << "Current Line: " << line;
        if (line.isEmpty()) continue;

        if (line.startsWith("#") && gameCount == 0) {
            //Remove first character
            QString trueLine = line.mid(1).trimmed();

            EmuData emu = EmuData::fromString(trueLine);
            emulatorMap.insert(emu.getName(), emu);
            currentEmulatorName = emu.getName();

            qDebug() << "This is an emulator";
        }
        else if(line.startsWith("-")) {
            //Remove first character
            QString trueLine = line.mid(1).trimmed();

            //emulatorMap[currentEmulatorName].debugPrintGames();
            GameData game = GameData::fromString(trueLine);


            emulatorMap[currentEmulatorName].addGame(game);

            gameCount++;
            qDebug() << "This is a game";
        }
        else if (line.startsWith("+")) {
            int insertIndex = ui->tabWidget->count() - 1;
            EmulatorTabWidget* newTab = new EmulatorTabWidget(&emulatorMap[currentEmulatorName]);
            ui->tabWidget->insertTab(insertIndex, newTab, emulatorMap[currentEmulatorName].getName());

            gameCount = 0;
            qDebug() << "This is a new emulator, make a tab for the last one";
            qDebug() << gameCount;
        }
        else {continue;}
    }

    file.close();
}

void MainWindow::on_chooseDolphin_clicked()
{

    QString file = QFileDialog::getOpenFileName(this, "Select Game ROM", "G:/Emulator/Dolbin/Dolphin-x64/Games", "Game Files (*.iso *.gcm *.rvz *.wad)");

    if (!file.isEmpty()) {
        romPath = file;
        qDebug() << "Selected ROM path:" << romPath;
    }
}

void MainWindow::on_openDolphin_clicked()
{
    QProcess *myProcess = new QProcess(this);
    QString program = "G:/Emulator/Dolbin/Dolphin-x64/Dolphin.exe";

    // Correctly form the arguments list
    QStringList arguments;
    arguments << "-b" << "-e" << romPath;

    // Start the process with arguments
    bool success = myProcess->startDetached(program, arguments);

    if (!success) {
        qDebug() << "Failed to start Dolphin with game.";
    } else {
        qDebug() << "Dolphin started with game successfully.";
    }
}


void MainWindow::on_tabWidget_currentChanged(int index)
{
    if (ui->tabWidget->tabText(index) == "+") {
        NewTabDialog dialog(this);
        if (dialog.exec() == QDialog::Accepted) {
            EmuData newEmulator = dialog.getEmuData();
            QString name = newEmulator.getName();

            emulatorMap.insert(name, newEmulator);

            EmuData* emuPtr = &emulatorMap[name];

            EmulatorTabWidget* newTab = new EmulatorTabWidget(emuPtr);
            // Optionally set up layout or store emulator config

            int insertIndex = ui->tabWidget->count() - 1;
            ui->tabWidget->insertTab(insertIndex, newTab, newEmulator.getName());
            ui->tabWidget->setCurrentIndex(insertIndex);
        } else {
            // User cancelled
            ui->tabWidget->setCurrentIndex(0);  // Or previous tab
        }
        updateFile();
    }
}

void MainWindow::updateFile()
{
    QFile file("emulators.txt");
    if (!file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
        qDebug() << "Failed to open file for writing.";
        return;
    }

    QTextStream out(&file);

    for (auto it = emulatorMap.constBegin(); it != emulatorMap.constEnd(); ++it)
    {
        const EmuData& emu = it.value();

        // Write emulator with '#' prefix
        out << emu.toString() << "\n";

        // Write each game with '-' prefix
        for (const GameData& game : emu.getGames()) {
            out << game.toString() << "\n";
        }

        // Write '+' to mark end of emulator entry
        out << "+\n";
    }

    file.close();
    qDebug() << "emulators.txt updated successfully.";
}


void MainWindow::on_debugButton_clicked()
{
    qDebug() << "";
    qDebug() << "List of All Emulators, Paths, and Games";

    for (auto it = emulatorMap.constBegin(); it != emulatorMap.constEnd(); ++it) {
        const EmuData& emu = it.value();
        qDebug() << "----------------------------------------";
        qDebug() << "Emulator Name:" << emu.getName();
        qDebug() << "Executable Path:" << emu.getPath();
        qDebug() << "Launch Arguments:" << emu.getArgs();

        const QVector<GameData>& games = emu.getGames();
        if (games.isEmpty()) {
            qDebug() << "  No games found.";
        } else {
            for (const GameData& game : games) {
                qDebug() << "  Game Title:" << game.title;
                qDebug() << "  ROM Path:" << game.romPath;
                qDebug() << "  Game toString: " << game.toString();
            }
        }
    }

    qDebug() << "----------------------------------------";
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    updateFile(); // 🟢 Save emulatorMap and games to emulators.txt
    event->accept(); // Proceed with closing
}
