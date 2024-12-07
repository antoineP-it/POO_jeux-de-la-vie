#include <vector>
#include <string>

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
