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
