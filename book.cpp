#include "book.h"

Book::Book()
{
    // RAS
}

Book::~Book()
{
    // RAS
}


Book::Book(vector<Page> pages, Player hero, Player mask)
{
    this->pages = pages;
    this->hero = hero;
    this->mask = mask;
}

// Accesseurs...


vector<Page>* Book::getPages()
{
    return &(this->pages);
}

Player* Book::getHero()
{
    return &(this->hero);
}

Player* Book::getMask()
{
    return &(this->mask);
}
