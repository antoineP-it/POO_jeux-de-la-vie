/*#include "Grille.h"
#include <cstdlib>
#include <iostream>
#include <iterator>

Grille::Grille(int largeur, int longueur) : larg(largeur), longu(longueur), cells(largeur * longueur) {
    for (int y = 0; y < longueur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            cells[y * largeur + x] = Cell(false, false, x, y);
        }
    }
}

void Grille::initialiseRandom() {
    for (auto& cell : cells) {
        cell.setEstVivant(rand() % 2 == 0);
    }
    //notifObservers();
}

void Grille::initialiseDepuisFichier(const std::vector<std::vector<int>>& data) {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            setCellVivant(x, y, data[y][x] == 1);
        }
    }
}



void Grille::miseAJour() {
    std::vector<Cell> nextEtat = cells; // Copie de l'état actuel

    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            int voisins = countVoisins(x, y); // Nombre de voisins vivants
            bool vivant = estCellVivant(x, y);

            // Règles du jeu de la vie
            if (vivant) {
                // Une cellule vivante meurt si elle a moins de 2 voisins (isolement)
                // ou plus de 3 voisins (surpopulation)
                nextEtat[y * larg + x].setEstVivant(voisins == 2 || voisins == 3);
            } else {
                // Une cellule morte devient vivante si elle a exactement 3 voisins vivants
                nextEtat[y * larg + x].setEstVivant(voisins == 3);
            }
        }
    }

    cells = nextEtat; // Mettre à jour l'état actuel avec l'état futur
}



bool Grille::estCellVivant(int x, int y) const {
    return cells[y*larg + x].getEstVivant();
}

void Grille::setCellVivant(int x, int y, bool etat){
    cells[y*larg + x].setEstVivant(etat);
    //notifObservers(); //Notifie après changement
}

int Grille::countVoisins(int x, int y) const {
    int count = 0;

    for (int dy = -1; dy <= 1; ++dy) {
        for (int dx = -1; dx <= 1; ++dx) {
            // Ignorer la cellule elle-même
            if (dx == 0 && dy == 0) continue;

            int nx = x + dx; // Nouvelle coordonnée x
            int ny = y + dy; // Nouvelle coordonnée y

            // Vérification des limites
            if (nx >= 0 && nx < larg && ny >= 0 && ny < longu) {
                count += estCellVivant(nx, ny) ? 1 : 0;
            }
        }
    }
    return count;
}


void Grille::afficher() const {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            std::cout << (estCellVivant(x, y) ? "." : "O");
        }
        std::cout << '\n';
    }
    std::cout << std::string(20, '-') << '\n'; // Ligne de séparation entre états
}











*/

///////////////////////////////////////////////
#include "Grille.h"
#include <cstdlib>
#include <iostream>
#include <iterator>

Grille::Grille(int largeur, int longueur) : larg(largeur), longu(longueur), cells(largeur * longueur) {
    for (int y = 0; y < longueur; ++y) {
        for (int x = 0; x < largeur; ++x) {
            cells[y * largeur + x] = Cell(false, false, x, y);
        }
    }
}


void Grille::initialiseDepuisFichier(const std::vector<std::vector<int>>& data) {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            cells[y * larg + x].setEstVivant(data[y][x] == 1);
        }
    }
}




void Grille::miseAJour() {
    std::vector<bool> nextEtat(cells.size(), false);

    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            int voisins = countVoisins(x, y);
            bool vivant = cells[y * larg + x].getEstVivant();

            /*std::cout << "Cellule (" << x << ", " << y << ") : "
                  << (vivant ? "Vivante" : "Morte") << ", Voisins : " << voisins
                  << " -> ";
            std::cout << ((vivant && (voisins == 2 || voisins == 3)) || (!vivant && voisins == 3) ? "Vivra\n" : "Mourra\n");
            */
            if (vivant) {
                nextEtat[y * larg + x] = (voisins == 2 || voisins == 3);
            } else {
                nextEtat[y * larg + x] = (voisins == 3);
            }
        }
    }

    for (int i = 0; i < cells.size(); ++i) {
        cells[i].setEstVivant(nextEtat[i]);
    }
}




bool Grille::estCellVivant(int x, int y) const {
    return cells[y*larg + x].getEstVivant();
}

void Grille::setCellVivant(int x, int y, bool etat){
    cells[y*larg + x].setEstVivant(etat);
    //notifObservers(); //Notifie après changement
}

int Grille::countVoisins(int x, int y) const {
    int count = 0;

    // Déplacements pour les 8 directions
    const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    for (int dir = 0; dir < 8; ++dir) {
        int nx = x + dx[dir];
        int ny = y + dy[dir];

        if (nx >= 0 && nx < larg && ny >= 0 && ny < longu) {
            count += cells[ny * larg + nx].getEstVivant();
        }
    }

    return count;
}




void Grille::afficher() const {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            std::cout << (cells[y * larg + x].getEstVivant() ? '1' : '0');
        }
        std::cout << '\n';
    }
    std::cout << std::string(20, '-') << '\n'; // Ligne de séparation entre générations
}
