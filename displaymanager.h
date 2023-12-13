#ifndef DISPLAYMANAGER_H
#define DISPLAYMANAGER_H

#include "book.h"

// Gestionnaire d'affichage.
// Contient la logique métier et des fonctions de délégations.
// Ne pas doit avoir de référence avec Qt.
class DisplayManager
{
private:
    // Livre.
    Book* book;

    // Page du livre actuel.
    int currentPageIndex;

public:
    // Construteur par défaut (recommandé).
    DisplayManager();

    // Destructeur.
    ~DisplayManager();

    // Passer à la page suivante.
    void nextPage();

    // Obtenir la page courante.
    int getCurrentPageIndex();

    // Accesseurs...
    // (fonctions de délégation)

    const string* getCurrentBackgroundImage();
    Page getCurrentPage();
    int getCurrentBackgroundImageWidth();
    int getCurrentBackgroundImageHeight();

    const string* getStory();

    const string* getMaskImage();
    int getMaskPositionX();
    int getMaskPositionY();
    int getMaskWidth();
    int getMaskHeight();

    const string* getHeroImage();
    int getHeroPositionX();
    int getHeroPositionY();
    int getHeroWidth();
    int getHeroHeight();
};

#endif // DISPLAYMANAGER_H
