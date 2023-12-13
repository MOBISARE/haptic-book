#ifndef ASSET_H
#define ASSET_H

#include <string>
using namespace std;

// Regroupe les constantes applicatives.
// Ne pas doit avoir de référence avec Qt.
class Asset{
public:

    // Personnages
    static const string HERO_BIG;
    static const string HERO_LITTLE;

    // Masques
    static const string MASK_RED;
    static const string MASK_BLUE;
    static const string MASK_BLACK;
    static const string MASK_BROWN;
    static const string MASK_WHITE;
    static const string MASK_GREEN;

    // Niveaux
    static const string PAGE_1;
    static const string PAGE_2;
    static const string PAGE_3;
    static const string PAGE_4;
    static const string PAGE_5;
    static const string PAGE_6;

    // Textes narratifs
    static const string PAGE_1_STORY;
    static const string PAGE_2_STORY;
    static const string PAGE_3_STORY;
    static const string PAGE_4_STORY;
    static const string PAGE_5_STORY;
    static const string PAGE_6_STORY;

    // Audios
    static const string FIRE;

    // Affichage
    static const int WIDTH;
    static const int HEIGHT;

    Asset();
    ~Asset();
};

#endif // ASSET_H
