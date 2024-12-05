#ifndef MCONSOLE_H
#define MCONSOLE_H

#include <vector>
using namespace std;

class Mconsole {
private:
    int lignes, colonnes; // Dimensions de la grille
    vector<vector<bool>> grille; // Grille actuelle
    vector<vector<bool>> prochaineGrille; // Grille pour la mise à jour

    
    int compterVoisinsVivants(int x, int y) const; // Méthode privée pour compter les voisins vivants d'une cellule

public:
    
    Mconsole(int lignes, int colonnes, const vector<vector<bool>>& etatInitial);

    void affichage() const;

    bool MaJ();
};

#endif 
