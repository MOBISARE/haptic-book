#include "hapticmanager.h"
#include <QApplication>
#include "mainwindow.h"
#include <QDebug>
#include "asset.h"

HapticManager::HapticManager(MainWindow *window):window(window){
    mouse = new CImmMouse();

    if (!mouse->Initialize(qWinAppInst(),  (HWND)window->effectiveWinId()  ))
    {qDebug()<<"===>Erreur chargement souris "<<mouse;
        delete mouse;
        mouse = NULL;
        qApp->quit();
    }

    project = new CImmProject();
    if(project->OpenFile("./../HapticBook\\effects.ifr", mouse)){
        qDebug()<<"Loading project ifr";

        sand = project->CreateEffect("Sable", mouse, IMM_PARAM_NODOWNLOAD);
        if (!sand) {
            qDebug()<<"===>Error : Sand effect loading ";
            delete sand;
            sand = NULL;
        }else{
            qDebug()<<"Loading sand effect";
        }

        ice = project->CreateEffect("Glace", mouse, IMM_PARAM_NODOWNLOAD);
        if (!ice) {
            qDebug()<<"===>Error : ice effect loading ";
            delete ice;
            ice = NULL;
        }else{
            qDebug()<<"Loading ice effect";
        };

        wave = project->CreateEffect("Vague", mouse, IMM_PARAM_NODOWNLOAD);
        if (!wave) {
            qDebug()<<"===>Error : wave effect loading ";
            delete wave;
            wave = NULL;
        }else{
            qDebug()<<"Loading wave effect";
        };

        walk = project->CreateEffect("Pas", mouse, IMM_PARAM_NODOWNLOAD);
        if (!walk) {
            qDebug()<<"===>Error : walk effect loading ";
            delete walk;
            walk = NULL;
        }else{
            qDebug()<<"Loading walk effect";
        };

        wind = project->CreateEffect("Vent", mouse, IMM_PARAM_NODOWNLOAD);
        if (!wind) {
            qDebug()<<"===>Error : wind effect loading ";
            delete wind;
            wind = NULL;
        }else{
            qDebug()<<"Loading wind effect";
        };

        fight = project->CreateEffect("Combat", mouse, IMM_PARAM_NODOWNLOAD);
        if (!fight) {
            qDebug()<<"===>Error : fight effect loading ";
            delete fight;
            fight = NULL;
        }else{
            qDebug()<<"Loading fight effect";
        };
    }else{
        qDebug()<<"===>Error when loading project :  "<<CIFCErrors::GetLastErrorCode() ;
    }
}

HapticManager::~HapticManager(){
}

CImmCompoundEffect *HapticManager::getSand() const
{
    return sand;
}
CImmCompoundEffect *HapticManager::getIce() const
{
    return ice;
}
CImmCompoundEffect *HapticManager::getFight() const
{
    return fight;
}
CImmCompoundEffect *HapticManager::getWalk() const
{
    return walk;
}
CImmCompoundEffect *HapticManager::getWave() const
{
    return wave;
}
CImmCompoundEffect *HapticManager::getWind() const
{
    return wind;
}

void HapticManager::launchEffect(std::string effect){
    qDebug()<<"search effect";
    if(effect.compare(SAND) == 0){
        qDebug()<<"effect sand find";
        this->getSand()->Start();
    }else if(effect.compare(ICE) == 0){
        this->getIce()->Start();
    }else if(effect.compare(WIND) == 0){
        this->getWind()->Start();
    }else if(effect.compare(WAVE) == 0){
        this->getWave()->Start();
    }else if(effect.compare(FIGHT) == 0){
        this->getFight()->Start();
    }else if(effect.compare(WALK) == 0){
        this->getWalk()->Start();
    }
}

void HapticManager::stopEffect(std::string effect){
    if(effect.compare(SAND) == 0){
        this->getSand()->Stop();
    }else if(effect.compare(ICE) == 0){
        this->getIce()->Stop();
    }else if(effect.compare(WIND) == 0){
        this->getWind()->Stop();
    }else if(effect.compare(WAVE) == 0){
        this->getWave()->Stop();
    }else if(effect.compare(FIGHT) == 0){
        this->getFight()->Stop();
    }else if(effect.compare(WALK) == 0){
        this->getWalk()->Stop();
    }
}
