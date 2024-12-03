#include "Grille.h"
#include <cstdlib>

Grille::Grille(int largeur, int longueur) : larg(largeur), longu(longueur), cells(largeur * longueur) {}

void Grille::initialiseRandom() {
    for (auto& cell : cells) {
        cell.setEstVivant(rand() % 2 == 0);
    }
    notifObservers();
}


void Grille::miseAJour() {
    std::vector<Cell> nextEtat = cells;
    for (int y = 0; y< longu; ++y) {
        for (int x = 0; x<larg; ++x) {
            int voisins = countVoisins(x,y);
            bool vivant = estCellVivant(x,y);

            if (vivant && (voisins<2 || voisins >3)) {
                nextEtat[y*larg + x].setEstVivant(false); //la cellule meurt
            }
            else if (!vivant && voisins ==3) {
                nextEtat[y*larg + x].setEstVivant(true); //la cellule devient vivante
            }
        }
    }
    cells = nextEtat;
}

bool Grille::estCellVivant(int x, int y) const {
    return cells[y*larg + x].getEstVivant();
}

void Grille::setCellVivant(int x, int y, bool etat){
    cells[y*larg + x].setEstVivant(etat);
    notifObservers(); //Notifie après changement
}

int Grille::countVoisins(int x, int y) const {
    int count = 0;
    for (int dy = -1; dy<=1; ++dy) {
        for (int dx = -1; dx<=1; ++dx) {
            if (dx==0 && dy==0) continue;

            int nx = x+dx;
            int ny = y+dy;

            if (nx>=0&& nx < larg && ny >=0 && ny <longu) {
                count += estCellVivant(nx, ny) ? 1 : 0;
            }
        }
    }
    return count;
}