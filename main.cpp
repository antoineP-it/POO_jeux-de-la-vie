#include "Grille.h"
#include "MGraphSFML.h"
#include "Mconsole.h"
#include <iostream>

void Menu() {
    std::cout << "=== Jeu de la vie ==="<< std::endl;
    std::cout << "1. Mode Graphique!"<<std::endl;
    std::cout <<"2. Mode Console!"<<std::endl;
    std::cout <<"Choisissez votre option : ";
}

int main(){
    const int largeur=80; //Dimensions de la grille
    const int longueur=60;

    Grille grille(largeur, longueur);
    grille.initialiseRandom();

    int choix = 0;
    do {
        Menu();
        std::cin >> choix;

        switch (choix) {
            case 1: {
                MGraphSFML moteurGraphique(largeur, longueur); //Mode graphique

                while (moteurGraphique.isOpen()) {
                    moteurGraphique.handleEvents();
                    grille.miseAJour();
                    moteurGraphique.renduGrille(grille);

                }
                break;
            }
            case 2: {
                Mconsole moteurConsole; //Mode console

                char continuer = 'y';
                do {
                    moteurConsole.affichage(grille);
                    grille.miseAJour();

                    std::cout << "Continuer? (y/n): ";
                    std::cin >> continuer;

                }while (continuer == 'y');
                break;
            }
            case 3:
                std::cout << "Merci d'avoir joué à notre jeu ! " << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer" <<std::endl;
        }
    }while (choix !=3);

    return 0
}