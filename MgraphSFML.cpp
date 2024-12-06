#include "MgraphSFML.h"


MgraphSFML::MgraphSFML(int largeur, int longueur, const string& title) 
    : fenetre(sf::VideoMode(largeur, longueur), title) {}


void MgraphSFML::creeFenetre() {
    fenetre.clear(sf::Color::Black); // pour effacer le contenu précédent de la fenêtre avec un fond noir.
}


void MgraphSFML::renduCell(int x, int y, sf::Color color) { //Méthode pour dessiner une cellule à une position donnée avec une couleur

    sf::RectangleShape cell(sf::Vector2f(100.0f, 100.0f)); // on définit ici la cellule comme un rectangle
    cell.setPosition(static_cast<float>(x * 10), static_cast<float>(y * 10));
    cell.setFillColor(color);
    fenetre.draw(cell);
}


void MgraphSFML::handleEvents() {//méthode pour gérer les événements utilisateur
    sf::Event event;
    while (fenetre.pollEvent(event)) {
        if (event.type == sf::Event::Closed) {
            closeFenetre(); // Ferme la fenêtre si l'utilisateur clique sur la croix
        }
    }
}


void MgraphSFML::closeFenetre() { // fermeture de la fenêtre
    fenetre.close();
}


void MgraphSFML::displayFenetre() {// on affiche le contenu de la fenêtre
    fenetre.display();
}


bool MgraphSFML::estOuverte() const {// on  vérifie si la fenêtre est ouverte
    return fenetre.isOpen();
}

void MgraphSFML::renduGrille(const Grille& grille) {
    fenetre.clear(sf::Color::Black);

    float cellWidth = fenetre.getSize().x / static_cast<float>(largeur);
    float cellHeight = fenetre.getSize().y / static_cast<float>(longueur);

    for (int x = 0; x < largeur; ++x) {
        for (int y = 0; y < longueur; ++y) {
            sf::RectangleShape cell(sf::Vector2f(cellWidth, cellHeight));
            cell.setPosition(x * cellWidth, y * cellHeight);

            // Colorer les cellules vivantes
            if (grille.estCellVivant(x, y)) {
                cell.setFillColor(sf::Color::Green);
            } else {
                cell.setFillColor(sf::Color::Black);
            }

            cell.setOutlineThickness(1);
            cell.setOutlineColor(sf::Color::White);
            fenetre.draw(cell);
        }
    }

    fenetre.display();
};
