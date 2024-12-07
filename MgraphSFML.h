#ifndef MGRAPH_SFML_H
#define MGRAPH_SFML_H

#include <SFML/Graphics.hpp>
#include <string>
#include "Grille.h"

using namespace std;
using namespace sf;

class MgraphSFML {
private:
    sf::RenderWindow fenetre; // on utilise cet attribut pour  la fenêtre graphique où tout sera dessiné
    int largeur, longueur;

public:

    MgraphSFML(int largeur, int longueur, const string& title);

    void creeFenetre();
    void renduCell(int x, int y, sf::Color color);
    void handleEvents();
    void closeFenetre();
    void displayFenetre();
    void renduGrille (const Grille& grille, int longu, int larg);

    bool estOuverte() const;
};


#endif