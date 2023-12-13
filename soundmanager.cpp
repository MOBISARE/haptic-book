#include "soundmanager.h"
#include <QMediaPlayer>

SoundManager::SoundManager() {
    sounds = QMap<QString, QMediaPlayer*>();

    this->addSound("fire", QString::fromStdString((Asset::FIRE)));
}

SoundManager::~SoundManager()
{
    qDeleteAll(sounds);
    sounds.clear();
    if (instance) {
       instance = nullptr;
    };
}

SoundManager* SoundManager::instance = nullptr;

SoundManager* SoundManager::getInstance()
{
    if(!instance){
        instance = new SoundManager();
    }

    return instance;
}

void SoundManager::addSound(const QString& soundName, const QString& soundFilePath)
{
    QMediaPlayer* mediaPlayer = new QMediaPlayer;
    mediaPlayer->setMedia(QUrl(soundFilePath));
    sounds[soundName] = mediaPlayer;
}

void SoundManager::playSound(const QString& soundName, bool loop)
{
    if (sounds.contains(soundName) && !this->isSoundPlaying(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];

        if (loop) {
            mediaPlayer->connect(mediaPlayer, &QMediaPlayer::stateChanged, [=](QMediaPlayer::State state) {
                if (state == QMediaPlayer::StoppedState) {
                    mediaPlayer->play();
                }
            });
        }

        mediaPlayer->play();
    }
}

void SoundManager::restartSound(const QString& soundName)
{
    if (sounds.contains(soundName))
    {
        if (this->isSoundPlaying(soundName))
            sounds[soundName]->setPosition(0);
        else
            this->playSound(soundName);
    }
}

void SoundManager::stopSound(const QString& soundName)
{
    if (sounds.contains(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];
        mediaPlayer->disconnect(mediaPlayer, &QMediaPlayer::stateChanged, 0, 0);
        mediaPlayer->stop();
    }
}

void SoundManager::stopAllSounds()
{
    for (const QString& key : sounds.keys()) {
        stopSound(key);
    }
}

bool SoundManager::isSoundPlaying(const QString& soundName)
{
    if (sounds.contains(soundName))
    {
        QMediaPlayer* mediaPlayer = sounds[soundName];
        return mediaPlayer->state() == QMediaPlayer::PlayingState;
    }
    return false;
}
