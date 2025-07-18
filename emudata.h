#ifndef EMUDATA_H
#define EMUDATA_H

#include <QString>
#include <QVector>
#include <QDebug>

struct GameData {
    QString title;
    QString romPath;

    QString toString() const {
        return "- " + title + "|" + romPath;
    }

    static GameData fromString(const QString& line) {
        QStringList parts = line.split("|");
        return GameData{ parts.value(0), parts.value(1) };
    }
};

class EmuData {
public:
    EmuData(const QString& name = "", const QString& exePath = "", const QString& args = "")
        : name(name), path(exePath), launchArgs(args) {}

    QString getName() const { return name; }
    QString getPath() const { return path; }
    QString getArgs() const { return launchArgs; }

    void setName(const QString& newName) { name = newName; }
    void setPath(const QString& newPath) { path = newPath; }
    void setArgs(const QString& newArgs) { launchArgs = newArgs; }

    void addGame(const GameData& game) {
        games.append(game);
        gameNum++;
    }

    int returnGameNum(){return gameNum;}

    void debugPrintGames() const {
        qDebug() << "Emulator:" << name << "- Total Games:" << gameNum;
        for (const GameData& game : games) {
            qDebug() << "  Game Title:" << game.title << ", ROM Path:" << game.romPath;
        }
    }

    const QVector<GameData>& getGames() const {
        return games;
    }

    // Add this for saving/loading later
    QString toString() const {
        qDebug() << path;
        return "# " + name + "|" + path;
    }

    static EmuData fromString(const QString& line) {
        // Expected format: Name|Path{Args
        QStringList parts = line.split("|");
        QString name = parts.value(0);
        QString pathWithArgs = parts.value(1);

        QString path;
        QString args;

        int argStart = pathWithArgs.indexOf('{');
        if (argStart != -1) {
            path = pathWithArgs.left(argStart);
            args = pathWithArgs.mid(argStart + 1).trimmed();  // remove '{'
        } else {
            path = pathWithArgs;
        }

        return EmuData(name.trimmed(), path.trimmed(), args.trimmed());
    }

private:
    QString name;
    QString path;
    QString launchArgs = "-b -e";
    int gameNum = 0;
    QVector<GameData> games;
};

#endif // EMUDATA_H
