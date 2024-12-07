#include "Cell.h"

//Constructeur par défaut
Cell::Cell() {
    this -> estVivant = false;
    this -> estObstacle = false;
    this -> x = 0;
    this -> y = 0;
}

//Constructeur paramétré
Cell::Cell(bool vivant, bool obstacle, int coordx, int coordy) {
    this -> estVivant = vivant;
    this -> estObstacle = obstacle;
    this -> x = coordx;
    this -> y = coordy;
}

//Modificateur pour l'état de vie
bool Cell::getEstVivant() const {
    return this -> estVivant;
}
//Modificateur pour l'état vivant
void Cell::setEstVivant(bool etat) {
    this -> estVivant = etat;
}

//Accesseur pour etat d'obstacle
bool Cell::getEstObstacle() const {
    return this -> estObstacle;
}

//Modificateur pour l'état d'obstacle
void Cell::setEstObstacle(bool obs) {
    this -> estObstacle = obs;
}

//Accesseur pour les coordonnéesde x
int Cell::getCoordX() const {
    return this -> x;
}

//Modificateur pour les coodonnées de x
void Cell::setCoordX(int coordx) {
    this -> x = coordx;
}

//Idem pour les coordonnées de y
int Cell::getCoordY() const {
    return this -> y;
}

void Cell::setCoordY(int coordy) {
    this -> y = coordy;
}

//Méthode d'inversion d'état
void Cell::inverseEtat() {
    this -> estVivant = ! this -> estVivant;
}