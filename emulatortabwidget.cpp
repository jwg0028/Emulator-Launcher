#include "emulatortabwidget.h"
#include "ui_emulatortabwidget.h"
#include "QFileDialog"
#include <QListWidgetItem>
#include <QFileInfo>
#include <QDebug>

EmulatorTabWidget::EmulatorTabWidget(EmuData* emu, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::EmulatorTabWidget)
    , emulatorData(emu)
{
    ui->setupUi(this);


    //emulatorData.debugPrintGames();

    // Fill game list
    for (const GameData& game : emulatorData->getGames()) {
        QListWidgetItem* item = new QListWidgetItem(game.title);

        QString fullCommand = emulatorData->getArgs() + " \"" + game.romPath + "\"";

        qDebug() << "args: " << emulatorData->getArgs();

        item->setData(Qt::UserRole, fullCommand); // 👈 Now stores args + romPath
        ui->gameList->addItem(item);
    }

    //qDebug() << emulatorData.getName();

    // Connect double-click signal
    connect(ui->gameList, &QListWidget::itemDoubleClicked,
            this, &EmulatorTabWidget::launchSelectedGame);


    connect(ui->addGame, &QPushButton::clicked,
            this, &EmulatorTabWidget::addGameToEmulator);

}

EmulatorTabWidget::~EmulatorTabWidget()
{
    delete ui;
}

void EmulatorTabWidget::launchSelectedGame(QListWidgetItem* item)
{
    QProcess *myProcess = new QProcess(this);
    QString program = emulatorData->getPath();
    QString fullCmd = item->data(Qt::UserRole).toString();

    qDebug() << "Full Line: " << fullCmd;

    // Start the process with arguments
    QStringList arguments = QProcess::splitCommand(fullCmd);
    bool success = myProcess->startDetached(program, arguments);

    if (!success) {
        qDebug() << "Failed to start emulator with game.";
    } else {
        qDebug() << "Emulator started with game successfully.";
    }
}

void EmulatorTabWidget::on_launchButton_clicked()
{
    qDebug() << "Button pressed";
    qDebug() << "Button Successful:" << emulatorData->getName();
    QProcess::startDetached(emulatorData->getPath());
}

void EmulatorTabWidget::addGameToEmulator()
{
    QString romPath = QFileDialog::getOpenFileName(this, "Select ROM File");
    if (romPath.isEmpty())
        return;

    QString nativePath = QDir::toNativeSeparators(romPath);

    QString title = QFileInfo(nativePath).completeBaseName(); // You can add an input dialog if you want a custom title

    GameData game;
    game.title = title;
    game.romPath = nativePath;

    emulatorData->addGame(game); // store internally

    // Format full command
    QString fullCommand = emulatorData->getArgs() + " \"" + game.romPath + "\"";

    // Add to UI
    QListWidgetItem* item = new QListWidgetItem(game.title);
    item->setData(Qt::UserRole, fullCommand);
    ui->gameList->addItem(item);
}
