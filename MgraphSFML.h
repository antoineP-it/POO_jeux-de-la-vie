#ifndef MGRAPH_SFML_H
#define MGRAPH_SFML_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Grille.h"

using namespace std;
using namespace sf;

class MgraphSFML { // : public Grille //( pour l'héritage)//
private:
    sf::RenderWindow fenetre; // on utilise cet attribut pour  la fenêtre graphique où tout sera dessiné
    int largeur, longueur;

public:

    MgraphSFML(int largeur, int longueur, const string& title);

    void creeFenetre();                      // Préparation la fenêtre
    void renduCell(int x, int y, sf::Color color); // on dessine une cellule
    void handleEvents();                     // Gestionles événements utilisateur
    void closeFenetre();                     // Fermeture la fenêtre
    void displayFenetre();                   // on affiche le contenu de la fenêtre
    void renduGrille (const Grille& grille);

    bool estOuverte() const;// on vérifie si la fenêtre est ouverte
};


#endif

/*
#ifndef MGRAPH_SFML_H
#define MGRAPH_SFML_H

#include <SFML/Graphics.hpp>
#include "Grille.h"

using namespace std;
using namespace sf;

const int CELL_SIZE = 10; // Taille des cellules

class MgraphSFML : public Grille {
private:
    RenderWindow fenetre; // Fenêtre graphique pour le rendu

public:
    // Constructeur
    MgraphSFML(int largeur, int longueur, const string& titre);

    // Méthodes principales
    void initializeGrid();            // Initialise aléatoirement la grille
    void renderGrid();                // Affiche la grille
    void handleEvents();              // Gère les événements utilisateur
    void run();                       // Lancement de la simulation
};

#endif

*/
