#include "GestionFichier.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>


GestionFichier::GestionFichier(){
    std::cin >> this -> cheminAcces; 
}


std::vector<int> GestionFichier::dimensionsGrille() {
    int longueur;
    int largeur;
    
    std::ifstream fichier( this -> cheminAcces ); 
    if (!fichier) {
        std::cout << "Erreur : Impossible d'ouvrir le fichier " << this -> cheminAcces << std::endl;
    }

    std::string ligne;

    if (std::getline(fichier, ligne)) {
        std::istringstream flux(ligne);
        flux >> longueur >> largeur;
    } else {
        std::cout << "Erreur : Fichier vide ou format incorrect." << std::endl;

    }
    fichier.close(); 
    std::vector<int> dim;
    dim.push_back(longueur);
    dim.push_back(largeur);
    return dim;
}

std::vector<std::vector<int>> GestionFichier::contenueGrille() {
    std::vector<std::vector<int>> grille;

    std::ifstream fichier(this->cheminAcces);
    if (!fichier) {
        std::cerr << "Erreur : Impossible d'ouvrir le fichier " << this->cheminAcces << std::endl;
        return grille;
    }

    std::string ligne;
    // Ignorer la première ligne contenant les dimensions
    std::getline(fichier, ligne);

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
    return grille;
}

