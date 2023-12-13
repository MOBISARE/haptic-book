#include "page.h"

Page::Page()
{
    // RAS
}

Page::~Page()
{
    // RAS
}


Page::Page(const string* backgroundImage, const string* story, int width, int height)
{
    this->backgroundImage = backgroundImage;
    this->story = story;
    this->width = width;
    this->height = height;
}

// Accesseurs...


const string* Page::getBackgroundImage()
{
    return this->backgroundImage;
}

const string* Page::getStory()
{
    return this->story;
}

int Page::getWidth()
{
    return this->width;
}

int Page::getHeight()
{
    return this->height;
}
