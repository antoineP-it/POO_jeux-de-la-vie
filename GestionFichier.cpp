#include "GestionFichier.h"
#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <filesystem> // Pour la gestion des dossiers
#include <iomanip>    // Pour le formatage du temps
#include <ctime>      // Pour obtenir le timestamp

GestionFichier::GestionFichier(){
    std::cout << "Veuillez renseigner le chemin d'accés du fichier source" << std::endl;
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
void GestionFichier::initialiserDossierSauvegarde() {
    // Obtenir la date et l'heure actuelles pour un nom unique
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);
    std::tm date = *std::localtime(&t);

    std::ostringstream nom;
    nom << "Sauvegardes_"
        << std::put_time(&date, "%Y-%m-%d_%H-%M-%S");
    this -> dossierSauvegarde = nom.str();

    // Créer le dossier
    std::filesystem::create_directory( this -> dossierSauvegarde);
}

void GestionFichier::sauvegarderEtatGrille(const std::vector<std::vector<int>>& grille, int iteration) {
    // Créer un nom de fichier basé sur l'itération
    std::ostringstream nom;
    nom << this -> dossierSauvegarde << "/grille_" << iteration << ".txt";

    std::ofstream fichier(nom.str());
    if (!fichier) {
        std::cerr << "Erreur : Impossible de créer le fichier " << nom.str() << std::endl;
        return;
    }

    // Écrire la grille dans le fichier
    for (const auto& ligne : grille) {
        for (int cell : ligne) {
            fichier << cell << " ";
        }
        fichier << "\n";
    }

    fichier.close();
}

