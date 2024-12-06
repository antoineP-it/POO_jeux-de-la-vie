#include "Cell.h"

//Constructeur par défaut
Cell::Cell() : estVivant(false), estObstacle(false), x(0), y(0) {}

//Constructeur paramétré
Cell::Cell(bool vivant, bool obstacle, int coordx, int coordy) : estVivant(vivant), estObstacle(obstacle), x(coordx), y(coordy) {}

//Modificateur pour l'état de vie
// logiquement accesseur pour l'état de vie
bool Cell::getEstVivant() const {
    return estVivant;
}
//Modificateur pour l'état vivant
void Cell::setEstVivant(bool etat) {
    estVivant = etat;
}

//Accesseur pour etat d'obstacle
bool Cell::getEstObstacle() const {
    return estObstacle;
}

//Modificateur pour l'état d'obstacle
void Cell::setEstObstacle(bool obs) {
    estObstacle = obs;
}

//Accesseur pour les coordonnéesde x
int Cell::getCoordX() const {
    return x;
}

//Modificateur pour les coodonnées de x
void Cell::setCoordX(int coordx) {
    x = coordx;
}

//Idem pour les coordonnées de y
int Cell::getCoordY() const {
    return y;
}

void Cell::setCoordY(int coordy) {
    y = coordy;
}

//Méthode d'inversion d'état
void Cell::inverseEtat() {
    estVivant = !estVivant;
}
