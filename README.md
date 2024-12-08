# POO_jeux-de-la-vie - Documentation

## Introduction
Le jeu de la vie est un automate cellulaire conçu par le mathématicien John Conway en 1970. Il consiste à simuler l’évolution d’une population de cellules placées dans une grille rectangulaire bidimensionnelle. Chaque cellule possède deux états ,  elle est  soit vivante, soit morte et peut interagir avec ses huit voisines adjacentes. Le jeu évolue sur un intervalle de temps discret, où l’état des cellules est mis à jour après chaque itération selon les règles suivantes :
- Une cellule morte possédant exactement trois voisines vivantes devient vivante.
- Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.
L’objectif de notre projet est l’implémentation de ce jeu en C++ avec des concepts de Programmation Orientée Objet (POO). Le programme devra lire un fichier contenant la taille de grille et l’état initial des cellules. Il devra par la suite mettre à jour l’état des cellules à chaque itération selon les règles du jeu avec la possibilité de choisir de modes de fonctionnement qui sont :
- Mode console : Affichage des itérations sous forme textuelle.
- Mode graphique : affiche la grille et l’état des cellules sur une interface graphique.

Dans ce document, vous retrouverez la documentation technique et utilisateur de notre projet. 

Lien du GitHub : https://github.com/antoineP-it/POO_jeux-de-la-vie
## Documentation technique 

### Architecture générale du projet 

Afin de réspecter les notions de paradigme objet, nous avons séparé chaque classes dans un fichier différent. Pour chaque classes, nous avons un fichier d'en-tête .h qui nous fournit des informations sur les déclarations des classes et des méthodes de celles-ci. Avec ces fichiers, nous avons un fichier .cpp contenant la definition des classes et des méthodes déclarés dans sont .h respectif. Ensuite nous avons le fichier main.cpp qui est le fichier permettant d'appeller toutes nos classes. 
Conformement au diagramme de classe, dans notre projet nous avons :
<p align="center">
  <img src="https://github.com/user-attachments/assets/56f38f8b-0ade-4957-be5a-14498ae6f1a5" />
</p>

### Documentation des méthodes des classes 

#### classe : Cell

Bool getEstVivant() const : retourne l’état de vie d’une cellule (true -> vivante, false -> morte). 

Void setEstVivant(bool etat) : permet de modifier l'etat d'une cellule, prend en paramètre true ou false en fonction de si on veut mettre en vie une cellule ou la tuer. 

Bool getEstObstacle() const : retourne le status d'une cellule (true -> cellule obstacle, false -> cellule normale). 

void setEstObstacle(bool etat) : permet de modifier le status d'une cellule, prend en paramètre un booléen (true -> met la cellule en cellule obstacle, false -> met la cellule en cellule normale). 

int getCoordX() const : retourne la coordonnée x de la cellule.

int getCoordY() const : retourne la coordonnée y de la cellule.

void setCoordX(int coordx) : permet de changer la coordonnée x de la cellule.

void setCoordY(int coordy) : permet de changer la coordonnée y de la cellule.

void inverseEtat() : permet l’inversion de l’état d’une cellule.

#### classe GestionFichier

vector<int> dimensionsGrille() : Lit la 1ère ligne du fichier et retourne la taille de la grille (longueur, largeur) dasn un vecteur. 

vector<vector<int>> contenueGrille() : lit le contenu de la grille (après la 1ère ligne) et retourne la matrice d'entiers représentant l'état des cellules dasn un vecteur de deux dimensions. 

void initialiserDossierSauvegarde() : Crée un dossier de sauvegarde nommé avec la date et l'heure actuelle. 

void sauvegarderEtatGrille(const vector<vector<int>>& grille, int iteration) : Sauvegarde l'état de la grille dans un fichier texte au sein du dossier de sauvegarde. Prends en paramètre la grille sous forme de vecteur de 2 dimensions et l'iteration correspondant à la grille. 

#### classe Grille 

void initialiseDepuisFichier() : Permet l’initialisation de grille à partir du fichier donné. 

void miseAJour() : Permet la mise à jour de chaque cellule de la grille selon les différents règles du jeu. 

bool EstCellVivant(int x, int y) : permet de dire si la cellule à la position (x,y) de la grille est vivante ou morte. Prends en paramètre les coordonées de la cellule à regarder. Retourne true si elle est vivante et false si elle est morte. 

void setCellVivant(int x, int y, bool etat) : permet de changer l'etat de la cellule à la position(x,y).Prends en paramètre les coordonées de la cellule à modifier et le nouvel etat à lui affecter.

int countVoisins(int x, int y) : permet de compter les voisins vivants autour d’une cellule à la position(x,y). Prends en paramètre les coordonées de la cellule auquel il faut regarder ces voisins. Retourne le nombre de voisins vivants. 

void afficher() : permet d’afficher l’état de la grille dasn le terminal où on a 1(vivant) et 0(mort).  

vector<vector<int>> getEtatActuel() const : permet de donner l’état actuel de la grille sous forme de matrice d’entiers où l’on a 1 pour vivant et 0 pour mort. Retourne l'etat de la grille dans un vecteur à deux dimensions. 

bool estStable(const vector<vector<int>>& etatPrecedent) : permet de vérifier si l’état actuel de la grille est identique à son état précédent. Prends en paramètre l'etat precedent de la grille sous forme de vecteur de deux dimensions et retourne vrai si l'etat n'a pas changé et false si il a changé. 

#### classe MgraphSFML

void creeFenetre() : permet de creer une fenetre graphique simple avec un fond noir. 

void renduCell(int x, int y, Color color) : permet de dessiner une cellule à une position donnée avec une couleur de son choix. Prends en paramètre les coordonées de la cellule à colorier ainsi que la couleur à mettre à la cellule. 

void handleEvents() : permet la gestion des actions de l’utilisateur. Par exemple le fait d'appuyer sur la croix, permet de fermer la fenetre. 

void closeFenetre() : permet la fermeture de la fenetre graphique. 

void displayFenetre() : permet d’afficher le contenu dessiné dans la fenetre. 

void renduGrille(const Grille& grille, int longu, int larg) : permet d’afficher la grille sur la fenetre , les cellules qui sont en bleu sont vivantes et celles en blanc sont mortes. Prends en paramètre la grille à afficher et les dimensions de la grille. 

bool estOuverte() const : permet de savoir si une fenetre est ouverte ou non en renvoyant true ou false.

#### Différentes bibliothèques utilisées dans le programme

- Iostream
Bibliothèque permettant l’utilisation des flux d’entrée et de sortie standard en C++. Pour faire l'équivalent des prints par exemple. 

- Vector
Bibliothèque permettant de travailler avec des vecteurs. Pour gérer notre grille contenant les cellules par exemple. 

- Fstream
Bibliothèque permettant de lire ou d’écrire dans des fichiers. 

- Filesystem
Bibliothèque permettant la gestion des fichiers et des répertoires. 

- Iomanip
Bibliothèque permettant la manipulation des entrées et sorties de manières plus précise. 

- Thread
Bibliothèque permettant de travailler sur des threads (Thread = Flux d’exécution dans un programme). 

- Chrono
Bibliothèque permettant la manipulation et la prise de mesure des durées et intervalles , elle permet aussi de travailler avec des horloges. 

## Documentation utilisateur 

### Prérequis pour lancer le jeux 

Pour lancer le jeux, vous aurez besoin d'installer plusieurs choses :
- Un compilateur C++ pour pouvoir exécuter le code sur votre appareil.
- La librairie Simple and Fast Multimedia Library (SFML) pour la gestion des fenetres graphiques.

### Installation de la bibliothèque 

Pour installer la bibliothèque SFML, il vous faudra : 
- Sur un environement linux :

Il faudra suivre les commandes :
<div align='center'>
  sudo apt updade  
  sudo apt upgrade  
  sudo apt-get install libsfml-dev  
  brew install sfml  
</div>
  























