#include "Mconsole.h"
#include <iostream>
using namespace std;


Mconsole::Mconsole(int lignes, int colonnes, const vector<vector<bool>>& etatInitial)
    : lignes(lignes), colonnes(colonnes), grille(etatInitial), prochaineGrille(lignes, vector<bool>(colonnes, false)) {}


void Mconsole::affichage() const {
    for (const auto& ligne : grille) {
        for (bool cellule : ligne) {
            cout << (cellule ? "1 " : "0 ");
        }
        cout << endl;
    }
    cout << endl;
}


bool Mconsole::MaJ() {
    bool aChange = false;

    for (int x = 0; x < lignes; ++x) {
        for (int y = 0; y < colonnes; ++y) {
            int voisinsVivants = compterVoisinsVivants(x, y);

            if (grille[x][y]) {
                prochaineGrille[x][y] = (voisinsVivants == 2 || voisinsVivants == 3);
            } else {
                prochaineGrille[x][y] = (voisinsVivants == 3);
            }

            if (prochaineGrille[x][y] != grille[x][y]) {
                aChange = true;
            }
        }
    }

    grille = prochaineGrille;
    return aChange;
}


int Mconsole::compterVoisinsVivants(int x, int y) const {
    static const vector<pair<int, int>> directions = {
        {-1, -1}, {-1, 0}, {-1, 1},
        { 0, -1},          { 0, 1},
        { 1, -1}, { 1, 0}, { 1, 1}
    };

    int compteur = 0;
    for (const auto& [dx, dy] : directions) {
        int nx = x + dx, ny = y + dy;
        if (nx >= 0 && nx < lignes && ny >= 0 && ny < colonnes && grille[nx][ny]) {
            ++compteur;
        }
    }
    return compteur;
}
