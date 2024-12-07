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
/*
void Grille::initialiseDepuisFichier(const std::vector<std::vector<int>>& data) {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            cells[y * larg + x].setEstVivant(data[y][x] == 1);
        }
    }
}
*/

// Avec l'extension pour les cellules obstacles : 
void Grille::initialiseDepuisFichier(const std::vector<std::vector<int>>& data) {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            int value = data[y][x];
            if (value == 2) {
                cells[y * larg + x].setEstObstacle(true);
                cells[y * larg + x].setEstVivant(false);
            } 
            else if (value == 3){
                cells[y * larg + x].setEstObstacle(true);
                cells[y * larg + x].setEstVivant(true);
            }
            else {
                cells[y * larg + x].setEstVivant(value == 1);
            }
        }
    }
}

/*
void Grille::miseAJour() {
    std::vector<bool> nextEtat(cells.size(), false);

    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            int voisins = countVoisins(x, y);
            bool vivant = cells[y * larg + x].getEstVivant();

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
*/
bool Grille::estCellVivant(int x, int y) const {
    return cells[y*larg + x].getEstVivant();
}

void Grille::setCellVivant(int x, int y, bool etat){
    cells[y*larg + x].setEstVivant(etat);
}


// Avec l'extension des cellules obstacles 
void Grille::miseAJour() {
    std::vector<bool> nextEtat(cells.size(), false);

    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            int index = y * larg + x;

            if (cells[index].getEstObstacle()) {
                nextEtat[index] = cells[index].getEstVivant();
                continue;
            }

            int voisins = countVoisins(x, y);
            bool vivant = cells[index].getEstVivant();

            if (vivant) {
                nextEtat[index] = (voisins == 2 || voisins == 3);
            } else {
                nextEtat[index] = (voisins == 3);
            }
        }
    }

    for (int i = 0; i < cells.size(); ++i) {
        if (!cells[i].getEstObstacle()) {
            cells[i].setEstVivant(nextEtat[i]);
        }
    }
}

/*
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
*/

//Avec la gestion de la grille torique : 

int Grille::countVoisins(int x, int y) const {
    int count = 0;

    // Déplacements pour les 8 directions
    const int dx[] = {-1, 0, 1, -1, 1, -1, 0, 1};
    const int dy[] = {-1, -1, -1, 0, 0, 1, 1, 1};

    for (int dir = 0; dir < 8; ++dir) {
        int nx = (x + dx[dir] + larg) % larg;
        int ny = (y + dy[dir] + longu) % longu;
        count += cells[ny * larg + nx].getEstVivant();
    }

    return count;
}
//
std::vector<std::vector<int>> Grille::getEtatActuel() const {
    std::vector<std::vector<int>> etat(longu, std::vector<int>(larg));

    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            etat[y][x] = estCellVivant(x, y) ? 1 : 0;
        }
    }

    return etat;
}



void Grille::afficher() const {
    for (int y = 0; y < longu; ++y) {
        for (int x = 0; x < larg; ++x) {
            std::cout << (cells[y * larg + x].getEstVivant() ? '1' : '0');
        }
        std::cout << '\n';
    }
    std::cout << std::string(20, '-') << '\n';
}

bool Grille::estStable(const std::vector<std::vector<int>>& etatPrecedent) const {
    return etatPrecedent == getEtatActuel();
}

