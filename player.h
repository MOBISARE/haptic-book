#ifndef PLAYER_H
#define PLAYER_H

#include <string>
using namespace std;

// Représente un personnage.
// Simple objet de transfert sans aucune logique métier.
// Ne pas doit avoir de référence avec Qt.
class Player
{

private:
    // Ressource vers l'image du personnage.
    const string* sprite;

    // Position X initiale lors du chargement du niveau.
    int positionX;

    // Position Y initiale lors du chargement du niveau.
    int positionY;

    // Largeur.
    int width;

    // Hauteur.
    int height;

public:

    // Construteur par défaut.
    Player();

    // Destructeur.
    ~Player();

    // Constructeur paramétré (recommandé).
    Player(const string* sprite, int positionX, int positionY, int width, int height);

    // Accesseurs...

    const string* getSprite();
    int getPositionX();
    int getPositionY();
    int getWidth();
    int getHeight();
};

#endif // PLAYER_H
