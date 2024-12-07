#ifndef CELL_H
#define CELL_H


class Cell {
    protected:
        bool estVivant;
        bool estObstacle;
        int x;
        int y;
    
    public:
        Cell (); //Constructeur par défaut
        Cell(bool vivant, bool obstacle, int coordx, int coordy); //Constructeur paramétré

        //Accesseurs
        bool getEstVivant() const;
        bool getEstObstacle() const; 
        int getCoordX() const;
        int getCoordY() const;

        //Modificateur
        void setEstVivant(bool etat);
        void setEstObstacle(bool obs);
        void setCoordX(int coordx);
        void setCoordY(int coordy);

        //Méthodes
        void inverseEtat(); //Méthode permettant d'inverser l'état de vivant à mort et inversement



};

#endif