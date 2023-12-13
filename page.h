#ifndef PAGE_H
#define PAGE_H

#include <string>
using namespace std;

// Représente une page de livre.
// Simple objet de transfert sans aucune logique métier.
// Ne pas doit avoir de référence avec Qt.
class Page
{

private:

    // Ressource vers l'image de fond.
    const string* backgroundImage;

    // Texte narratif.
    const string* story;

    // Largeur de la scène.
    int width;

    // Hauteur de la scène.
    int height;

public:

    // Construteur par défaut.
    Page();

    // Destructeur.
    ~Page();

    // Constructeur paramétré (recommandé).
    Page(const string* backgroundImage, const string* story, int width, int height);

    // Accesseurs...

    const string* getBackgroundImage();
    const string* getStory();
    int getWidth();
    int getHeight();

};

#endif // PAGE_H
