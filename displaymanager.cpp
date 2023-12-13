#include "displaymanager.h"
#include "asset.h"

// Patron de conception : Façade
// Cette classe doit contenir toutes les fonctions nécessaires à la logique métier.
// Elle ne doit pas déprendre de Qt.

DisplayManager::DisplayManager() {

    // Initialisation des objets métiers.

    Player hero = Player(&Asset::HERO_LITTLE, 600, 300, 130, 120);
    Player mask = Player(&Asset::MASK_RED, 0, 0, 50, 50);

    vector<Page> pages;
    pages.push_back(Page(&Asset::PAGE_1, &Asset::PAGE_1_STORY, Asset::WIDTH, Asset::HEIGHT));
    pages.push_back(Page(&Asset::PAGE_2, &Asset::PAGE_2_STORY, Asset::WIDTH, Asset::HEIGHT));
    pages.push_back(Page(&Asset::PAGE_3, &Asset::PAGE_3_STORY, Asset::WIDTH, Asset::HEIGHT));
    pages.push_back(Page(&Asset::PAGE_4, &Asset::PAGE_4_STORY, Asset::WIDTH, Asset::HEIGHT));
    pages.push_back(Page(&Asset::PAGE_5, &Asset::PAGE_5_STORY, Asset::WIDTH, Asset::HEIGHT));
    pages.push_back(Page(&Asset::PAGE_6, &Asset::PAGE_6_STORY, Asset::WIDTH, Asset::HEIGHT));

    this->book = new Book(pages, hero, mask);
    this->currentPageIndex = 0;
}

DisplayManager::~DisplayManager()
{
    // Chaque objet créé avec "new" doit être détruit à la fin.
    delete this->book;
}

void DisplayManager::nextPage()
{
    // Si on arrive à la fin de la liste de pages,
    // on reboucle vers le début pour éviter l'application de planter.

    this->currentPageIndex++;
    if(this->currentPageIndex == this->book->getPages()->size()){
        this->currentPageIndex = 0;
    }
}

// Accesseurs...
// Cela permet pour la classe qui utilise "DisplayManager" de ne pas voir directement tous les concept sous-adjacent.
// Les fonctions de délégation n'ont pas ou très peu de logique.


int  DisplayManager::getCurrentPageIndex()
{
    return this->currentPageIndex;
}

Page DisplayManager::getCurrentPage()
{
    return this->book->getPages()->at(this->currentPageIndex);
}

const string* DisplayManager::getCurrentBackgroundImage()
{
    return this->getCurrentPage().getBackgroundImage();
}

int DisplayManager::getCurrentBackgroundImageWidth()
{
    return this->getCurrentPage().getWidth();
}

int DisplayManager::getCurrentBackgroundImageHeight()
{
    return this->getCurrentPage().getHeight();
}

const string* DisplayManager::getStory()
{
    return this->getCurrentPage().getStory();
}

const string* DisplayManager::getMaskImage()
{
    return this->book->getMask()->getSprite();
}

int DisplayManager::getMaskPositionX()
{
    return this->book->getMask()->getPositionX();
}

int DisplayManager::getMaskPositionY()
{
    return this->book->getMask()->getPositionY();
}

int DisplayManager::getMaskWidth()
{
    return this->book->getMask()->getWidth();
}

int DisplayManager::getMaskHeight()
{
    return this->book->getMask()->getHeight();
}

const string* DisplayManager::getHeroImage()
{
    return this->book->getHero()->getSprite();
}

int DisplayManager::getHeroPositionX()
{
    return this->book->getHero()->getPositionX();
}

int DisplayManager::getHeroPositionY()
{
    return this->book->getHero()->getPositionY();
}

int DisplayManager::getHeroWidth()
{
    return this->book->getHero()->getWidth();
}

int DisplayManager::getHeroHeight()
{
    return this->book->getHero()->getHeight();
}
