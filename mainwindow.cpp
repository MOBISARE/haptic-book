#include "mainwindow.h"
#include "asset.h"

#include <QDebug>
#include <QPixmap>
#include <QLabel>
#include <QString>
#include <QRect>
#include <string>

using namespace std;


MainWindow::MainWindow(QWidget *parent): QMainWindow(parent)
{
    // Initialisation des objets techniques de Qt.

    qDebug() << "Construction de l'affichage...";

    this->backgroundLabel = new QLabel("Backgound", this);
    this->storyLabel = new QLabel("story", this);
    this->maskLabel = new QLabel("Mask", this);
    this->heroLabel = new QLabel("Hero", this);
    this->display = new DisplayManager();

    this->configure();
    this->loadLevel();
}

MainWindow::~MainWindow()
{
    // Chaque objet créé avec "new" doit être détruit à la fin.
    delete this->backgroundLabel;
    delete this->storyLabel;
    delete this->maskLabel;
    delete this->heroLabel;
    delete this->display;
}

void MainWindow::configure()
{
    this->setFixedSize(Asset::WIDTH, Asset::HEIGHT);
}

void MainWindow::loadLevel()
{
    qDebug() << "Chargement du niveau :" << this->display->getCurrentPageIndex();

    // Image de fond.
    qDebug() << "Chargement de l'image de fond ... ";

    QPixmap backgroundPixmap = QPixmap(this->display->getCurrentBackgroundImage()->c_str());
    this->backgroundLabel->setPixmap(backgroundPixmap);
    this->backgroundLabel->setFixedSize(
        this->display->getCurrentBackgroundImageWidth(),
        this->display->getCurrentBackgroundImageHeight()
    );
    this->backgroundLabel->setScaledContents(true);

    // Texte narratif.
    qDebug() << "Chargement de l'histoire ... ";
    QFont storyFont = QFont("Hevelcita", 12);

    this->storyLabel->setText(this->display->getStory()->c_str());
    this->storyLabel->setFont(storyFont);
    this->storyLabel->setStyleSheet("color: yellow");
    this->storyLabel->move(
        0,
        this->height() - 40
    );

    // Masque.
    qDebug() << "Chargement du masque ... ";

    QPixmap maskPixmap = QPixmap(this->display->getMaskImage()->c_str());
    QRect maskRect = QRect(
        this->display->getMaskPositionX(),
        this->display->getMaskPositionY(),
        this->display->getMaskWidth(),
        this->display->getMaskHeight()
    );
    this->maskLabel->setPixmap(maskPixmap);
    this->maskLabel->setGeometry(maskRect);
    this->maskLabel->setScaledContents(true);

    // Protagoniste.
    qDebug() << "Chargement du héros ... ";

    QPixmap heroPixmap = QPixmap(this->display->getHeroImage()->c_str());
    QRect heroRect = QRect(
        this->display->getHeroPositionX(),
        this->display->getHeroPositionY(),
        this->display->getHeroWidth(),
        this->display->getHeroHeight()
    );
    this->heroLabel->setPixmap(heroPixmap);
    this->heroLabel->setGeometry(heroRect);
    this->heroLabel->setScaledContents(true);

}


void MainWindow::mouseMoveEvent(QMouseEvent* event)
{
    qDebug() << "Cuseur x=" << event->x() << ", y=" << event->y();

    // Premettre le déplacement du protagoniste avec le clic de la souris.
    if (this->heroLabel->geometry().contains(event->pos())){
        qDebug() << "Héros";

        // Calcul des nouvelles ccordonnées par rapport à la position de la souris.

        int heroX = event->x() - this->heroLabel->width() / 2;
        int heroY = event->y() - this->heroLabel->height() / 2;

        int maxX = this->width() - this->heroLabel->width();
        int maxY = this->height() - this->heroLabel->height();

        // Faire en sorte que le protagoniste ne sorte pas des limites de la taille de la fenêtre.
        heroX = qBound(0, heroX, maxX);
        heroY = qBound(0, heroY, maxY);

        // Déplacer le protagoniste.
        // On ne déplace que le composant graphique.
        // Et non pas l'objet "Player" qui contient les coordonnées de départ uniquement.
        this->heroLabel->move(heroX, heroY);
    }

    // Permettre le changement de niveau
    // si le protagoniste touche le masque.
    if(this->maskLabel->geometry().intersects(this->heroLabel->geometry())){
        qDebug() << "Insection avec le masque";
        this->display->nextPage();
        this->loadLevel();
    }

}

void MainWindow::mousePressEvent(QMouseEvent* event)
{
    // RAS
}

void MainWindow::mouseReleaseEvent(QMouseEvent* event)
{
    // RAS
}
