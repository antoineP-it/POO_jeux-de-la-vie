#ifndef MGRAPH_SFML_H
#define MGRAPH_SFML_H

#include <SFML/Graphics.hpp>
#include <string>

using namespace std;

class MgraphSFML {
private:
    sf::RenduFenetre fenetre; // on utilise cet attribut pour  la fenêtre graphique où tout sera dessiné

public:

    MgraphSFML(int width = 800, int height = 600, const string& title = "Jeu de la Vie");


    void creeFenetre();                      // Préparation la fenêtre
    void renduCell(int x, int y, sf::Color color); // on dessine une cellule
    void handleEvents();                     // Gestionles événements utilisateur
    void closeFenetre();                     // Fermeture la fenêtre
    void displayFenetre();                   // on affiche le contenu de la fenêtre


    bool estOuverte() const;// on vérifie si la fenêtre est ouverte
};

#endif
