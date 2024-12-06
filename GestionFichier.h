#ifndef GESTIONFICHIER_H
#define GESTIONFICHIER_H
#include <string>
#include <vector>


class GestionFichier {
    private :
    std::string cheminAcces;

    public : 
    GestionFichier();
    std::vector<int> dimensionsGrille() ;
    std::vector<std::vector<int>> contenueGrille();
    void SauvegarderGrille();
};



#endif
