#ifndef HAPTICMANAGER_H
#define HAPTICMANAGER_H

#undef UNICODE

#include <ifc.h>
#include <QPoint>
#include <QMainWindow>
#include "asset.h"

#define SAND "sand"
#define ICE "ice"
#define WIND "wind"
#define WAVE "wave"
#define FIGHT "fight"
#define WALK "walk"

class MainWindow;

class HapticManager{
public:
    HapticManager(MainWindow *window);
    ~HapticManager();

    CImmCompoundEffect *getSand() const;
    CImmCompoundEffect *getIce() const;
    CImmCompoundEffect *getWind() const;
    CImmCompoundEffect *getWave() const;
    CImmCompoundEffect *getFight() const;
    CImmCompoundEffect *getWalk() const;

    void launchEffect(std::string effect);
    void stopEffect(std::string effect);

 private:
    MainWindow *window;

    CImmMouse* mouse;
    CImmProject* project;

    CImmCompoundEffect *sand;
    CImmCompoundEffect *ice;
    CImmCompoundEffect *wave;
    CImmCompoundEffect *walk;
    CImmCompoundEffect *wind;
    CImmCompoundEffect *fight;
};


#endif // HAPTICMANAGER_H


