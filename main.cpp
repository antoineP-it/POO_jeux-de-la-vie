
/*
#include "Grille.h"

int main(){
    
    GestionFichier fichier;
    Grille grille(fichier.dimensionsGrille()[1], fichier.dimensionsGrille()[0]);
    //grille.initialiseRandom(); //à changer afin de l'initialiser en fonction du fichier source 
    auto contenu = fichier.contenueGrille();
    grille.initialiseDepuisFichier(contenu);

    grille.afficher();
    for (int i=0; i<5; i++){
        grille.miseAJour();
        grille.afficher();
    }

    


    return 0;



    
}
*/


//#include "Grille.h"
#include "MgraphSFML.h"
#include "Mconsole.h"
#include <iostream>
#include <thread> 
#include <chrono>

void afficherMenu() {
    std::cout << "=== Jeu de la Vie ===" << std::endl;
    std::cout << "1. Mode Graphique (SFML)" << std::endl;
    std::cout << "2. Mode Console" << std::endl;
    std::cout << "3. Quitter" << std::endl;
    std::cout << "Choisissez une option : ";
}

int main() {
    GestionFichier fichier;
    int longueur = fichier.dimensionsGrille()[0];
    int largeur = fichier.dimensionsGrille()[1];
    Grille grille(largeur, longueur);
    
    auto contenu = fichier.contenueGrille();
    grille.initialiseDepuisFichier(contenu);

    int choix = 0;
    do {
        afficherMenu();
        std::cin >> choix;

        switch (choix) {
            case 1: {
                MgraphSFML moteurGraphique(largeur*10, longueur*10, "Jeux de la vie");
                while (moteurGraphique.estOuverte()) {
                    moteurGraphique.handleEvents();
                    grille.miseAJour();
                    moteurGraphique.renduGrille(grille);
                    std::this_thread::sleep_for(std::chrono::seconds(0));
                }
                break;
            }
            case 2: {
                for (int i = 0; i<5; i++){
                    grille.afficher();
                    grille.miseAJour();
                }
                
                break;
            }
            case 3:
                std::cout << "Merci d'avoir joué ! À bientôt !" << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
        }
    } while (choix != 3);

    return 0;
}

/*
#include "MgraphSFML.h"
#include "Grille.h"

int main() {
    // Créer une fenêtre SFML et une grille
    MgraphSFML fenetre(800, 600, "Simulation");
    Grille grille(80, 60); // Grille 80x60 cellules

    while (fenetre.estOuverte()) {
        fenetre.handleEvents();  // Gérer les événements utilisateur
        fenetre.renduGrille(grille); // Dessiner la grille
    }

    return 0;
}
*/