#ifndef BOOK_H
#define BOOK_H

#include <vector>
#include "page.h"
#include "player.h"

// Représente un livre avec ses pages et ses personnages.
// Simple objet de transfert sans aucune logique métier.
// Ne pas doit avoir de référence avec Qt.
class Book
{
private:
    // Liste séquentielle des pages.
    vector<Page> pages;

    // Protagoniste.
    Player hero;

    // Masque
    Player mask;

public:
    // Construteur par défaut.
    Book();

    // Destructeur.
    ~Book();

    // Constructeur paramétré (recommandé).
    Book(vector<Page> pages, Player hero, Player mask);

    // Accesseurs...

    vector<Page>* getPages();
    Player* getHero();
    Player* getMask();
};

#endif // BOOK_H
