#ifndef GRILLE_H
#define GRILLE_H

#include <vector>
#include <iostream>
#include "Cell.h"
#include "GestionFichier.h"

class Grille {
    protected:
        int larg;
        int longu;
        std::vector<Cell> cells;
    
    public:
        Grille(int largeur, int longueur);

        void initialiseDepuisFichier(const std::vector<std::vector<int>>& data);
        void miseAJour();

        //Gestion des Cellules
        bool estCellVivant(int x, int y) const;
        void setCellVivant(int x, int y, bool etat);

        int countVoisins(int x, int y) const; 

        void afficher() const;

        std::vector<std::vector<int>> getEtatActuel() const;

        bool estStable(const std::vector<std::vector<int>>& etatPrecedent) const;




};
#endif