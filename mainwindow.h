#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QMouseEvent>
#include <QLabel>
#include "displaymanager.h"

// Affichage principale.
// Contient la logique de traitement technique avec Qt.
class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    // Gestionnaire d'affichage.
    DisplayManager* display;

    // Composant graphique de l'image de fond.
    QLabel* backgroundLabel;

    // Composant graphique du texte naratif.
    QLabel* storyLabel;

    // Composant graphique du masque.
    QLabel* maskLabel;

    // Composant graphique du protagoniste.
    QLabel* heroLabel;

    // Configurer l'affichage.
    void configure();

    // Charger le niveau courant.
    void loadLevel();

public:
    // Construteur paramétré par Qt (recommandé).
    MainWindow(QWidget *parent = nullptr);

     // Destructeur.
    ~MainWindow();

    // Détecter les événements de déplacement de la souris.
    void mouseMoveEvent(QMouseEvent* event);

    // Détecter les événements de clic de la souris.
    void mousePressEvent(QMouseEvent* event);

    // Détecter les événements de clic relaché de la souris.
    void mouseReleaseEvent(QMouseEvent* event);
};
#endif // MAINWINDOW_H
