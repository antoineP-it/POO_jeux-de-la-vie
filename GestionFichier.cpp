#include "GestionFichier.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


GestionFichier::GestionFichier(){
    std::cin >> this -> cheminAcces; 
}


void GestionFichier::ImportGrille() {
    int longueur;
    int largeur;
    std::vector<std::vector<int>> grille;

    std::ifstream fichier( this -> cheminAcces ); 
    if (!fichier) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier " << this -> cheminAcces << std::endl;
        return;
    }

    std::string ligne;
    if (std::getline(fichier, ligne)) {
        std::istringstream flux(ligne);
        flux >> longueur >> largeur;
    } else {
        std::cout << "Erreur : Fichier vide ou format incorrect." << std::endl;
        return;
    }

    while (std::getline(fichier, ligne)) {
        std::istringstream flux(ligne);
        std::vector<int> ligneGrille;
        int valeur;

        while (flux >> valeur) {
            ligneGrille.push_back(valeur);
        }

        grille.push_back(ligneGrille); 
    }
    
    fichier.close(); 
}


