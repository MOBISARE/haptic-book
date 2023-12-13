#include "asset.h"

// Personnages
const string Asset::HERO_BIG = ":/resources/images/hero_big.png";
const string Asset::HERO_LITTLE = ":/resources/images/hero_little.png";

// Masques
const string Asset::MASK_RED = ":/resources/images/mask_red.png";
const string Asset::MASK_BLUE = ":/resources/images/mask_blue.png";
const string Asset::MASK_BLACK = ":/resources/images/mask_black.png";
const string Asset::MASK_BROWN = ":/resources/images/mask_brown.png";
const string Asset::MASK_WHITE = ":/resources/images/mask_white.png";
const string Asset::MASK_GREEN = ":/resources/images/mask_green.png";

// Niveaux
const string Asset::PAGE_1 = ":/resources/images/page1.png";
const string Asset::PAGE_2 = ":/resources/images/page2.png";
const string Asset::PAGE_3 = ":/resources/images/page3.png";
const string Asset::PAGE_4 = ":/resources/images/page4.png";
const string Asset::PAGE_5 = ":/resources/images/page5.png";
const string Asset::PAGE_6 = ":/resources/images/page6.png";

// Textes narratifs
const string Asset::PAGE_1_STORY = "Page 1";
const string Asset::PAGE_2_STORY = "Page 2";
const string Asset::PAGE_3_STORY = "Page 3";
const string Asset::PAGE_4_STORY = "Page 4";
const string Asset::PAGE_5_STORY = "Page 5";
const string Asset::PAGE_6_STORY = "Page 6";


// Audios
const string Asset::FIRE  = ":/resources/sounds/fire2.mp3";

// Affichage
// Calculé avec un rapport 16:9
const int Asset::WIDTH = 800;
const int Asset::HEIGHT = Asset::WIDTH / 16 * 9;

Asset::Asset()
{
    // RAS
}

Asset::~Asset()
{
    // RAS
}
