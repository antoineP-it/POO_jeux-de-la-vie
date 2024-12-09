#include "MgraphSFML.h"
#include <iostream>
#include <thread> 
#include <chrono>

void afficherMenu() {
    std::cout << "=== Jeu de la Vie ===" << std::endl;
    std::cout << "1. Mode Graphique (SFML)" << std::endl;
    std::cout << "2. Mode Console" << std::endl;
    std::cout << "3. Test unitaire" << std::endl;
    std::cout << "4. Quitter" << std::endl;
    std::cout << "Choisissez une option : ";
}
void testUnitaire(Grille& grille, GestionFichier& fichier){
    int nb_iterations;
    std::cout << "Quelle iteration voulez vous voir ?" << std::endl;
    std::cin >> nb_iterations;
    int iteration;
    for (int i = 0; i < nb_iterations; i++) {
        grille.miseAJour();
        iteration = i;
    }
    grille.afficher();
    fichier.sauvegarderEtatGrille(grille.getEtatActuel(), iteration+1);
}

int main() {
    GestionFichier fichier;
    fichier.initialiserDossierSauvegarde();
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
                MgraphSFML moteurGraphique(largeur*50, longueur*50, "Jeux de la vie");
                int iteration = 0;
                auto etatPrecedent = grille.getEtatActuel();
                while (moteurGraphique.estOuverte()) {
                    moteurGraphique.handleEvents();
                    fichier.sauvegarderEtatGrille(grille.getEtatActuel(), iteration++);
                    grille.miseAJour();
                    if (grille.estStable(etatPrecedent)){
                        std::cout << "Simulation terminée car Grille stable" << std::endl;
                        break;
                    }
                    etatPrecedent= grille.getEtatActuel();
                    moteurGraphique.renduGrille(grille, longueur, largeur);
                    std::this_thread::sleep_for(std::chrono::milliseconds(300));
                }

                break;
            }
            case 2: {
                int nb_iterations;
                std::cout << "Combien d'itérations voulez-vous ?" << std::endl;
                std::cin >> nb_iterations;

                auto etatPrecedent = grille.getEtatActuel();
                for (int i = 0; i < nb_iterations; i++) {
                    grille.afficher();
                    fichier.sauvegarderEtatGrille(grille.getEtatActuel(), i);
                    grille.miseAJour();
                    if (grille.estStable(etatPrecedent)) {
                        std::cout << "Simulation terminée car Grille stable après " << i << " itérations." << std::endl;
                        break;
                    }

                    etatPrecedent = grille.getEtatActuel();
                }
                break;
            }
            case 3: {
                testUnitaire(grille, fichier);
                break;
            }
            case 4:
                std::cout << "Merci d'avoir joué ! À bientôt !" << std::endl;
                break;
            default:
                std::cout << "Option invalide. Veuillez réessayer." << std::endl;
        }
    } while (choix != 4);

    return 0;
}
