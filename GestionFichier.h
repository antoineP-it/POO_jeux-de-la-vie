#include <vector>
#include <string>

#include <filesystem> // Pour la gestion des dossiers
#include <iomanip>    // Pour mettre le temps au format date time classique
#include <iostream>
#include <fstream>
class GestionFichier {
private:
    std::string cheminAcces;
    std::string dossierSauvegarde;

public:
    GestionFichier();
    std::vector<int> dimensionsGrille();
    std::vector<std::vector<int>> contenueGrille();
    void initialiserDossierSauvegarde();
    void sauvegarderEtatGrille(const std::vector<std::vector<int>>& grille, int iteration);
};
