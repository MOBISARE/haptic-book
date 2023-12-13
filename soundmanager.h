#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H

#include <QString>
#include <QMediaPlayer>
#include <QMap>
#include "asset.h"
#include <string>
using namespace std;

class SoundManager
{
public:
    ~SoundManager();
    static SoundManager* getInstance();
    SoundManager(SoundManager &other) = delete;
    void operator=(const SoundManager&) = delete;
    void addSound(const QString& soundName, const QString& soundFilePath);
    void playSound(const QString& soundName, bool loop = false);
    void restartSound(const QString& soundName);
    void stopSound(const QString& soundName);
    void stopAllSounds();
    bool isSoundPlaying(const QString& soundName);
protected:
    SoundManager();
    static SoundManager* instance;
private:
    QMap<QString, QMediaPlayer*> sounds;
};

#endif // SOUNDMANAGER_H
