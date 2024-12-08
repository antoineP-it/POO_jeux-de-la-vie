# POO_jeux-de-la-vie - Documentation

## Introduction
Le jeu de la vie est un automate cellulaire conçu par le mathématicien John Conway en 1970. Il consiste à simuler l’évolution d’une population de cellules placées dans une grille rectangulaire bidimensionnelle. Chaque cellule possède deux états : elle est soit vivante, soit morte, et peut interagir avec ses huit voisines adjacentes. Le jeu évolue sur un intervalle de temps discret, où l’état des cellules est mis à jour après chaque itération selon les règles suivantes :
- Une cellule morte possédant exactement trois voisines vivantes devient vivante.
- Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

L’objectif de notre projet est l’implémentation de ce jeu en C++ avec des concepts de Programmation Orientée Objet (POO). Le programme devra lire un fichier contenant la taille de la grille et l’état initial des cellules. Il devra par la suite mettre à jour l’état des cellules à chaque itération selon les règles du jeu avec la possibilité de choisir deux modes de fonctionnement :
- Mode console : affichage des itérations sous forme textuelle.
- Mode graphique : affichage de la grille et de l’état des cellules sur une interface graphique.

Dans ce document, vous retrouverez la documentation technique et utilisateur de notre projet.

Lien du GitHub : https://github.com/antoineP-it/POO_jeux-de-la-vie

## Documentation technique 

### Architecture générale du projet 

Afin de respecter les notions de paradigme objet, nous avons séparé chaque classe dans un fichier différent. Pour chaque classe, nous avons un fichier d'en-tête `.h` qui nous fournit des informations sur les déclarations des classes et des méthodes de celles-ci. Avec ces fichiers, nous avons un fichier `.cpp` contenant la définition des classes et des méthodes déclarées dans son `.h` respectif. Ensuite, nous avons le fichier `main.cpp`, qui est le fichier permettant d’appeler toutes nos classes. 

Conformément au diagramme de classes, dans notre projet nous avons :

<p align="center">
  <img src="https://github.com/user-attachments/assets/56f38f8b-0ade-4957-be5a-14498ae6f1a5" />
</p>

### Documentation des méthodes des classes 

#### Classe : Cell

`bool getEstVivant() const` : retourne l’état de vie d’une cellule (true -> vivante, false -> morte). 

`void setEstVivant(bool etat)` : permet de modifier l'état d'une cellule, prend en paramètre `true` ou `false` en fonction de si on veut mettre en vie une cellule ou la tuer. 

`bool getEstObstacle() const` : retourne le statut d'une cellule (true -> cellule obstacle, false -> cellule normale). 

`void setEstObstacle(bool etat)` : permet de modifier le statut d'une cellule, prend en paramètre un booléen (true -> met la cellule en cellule obstacle, false -> met la cellule en cellule normale). 

`int getCoordX() const` : retourne la coordonnée x de la cellule.

`int getCoordY() const` : retourne la coordonnée y de la cellule.

`void setCoordX(int coordx)` : permet de changer la coordonnée x de la cellule.

`void setCoordY(int coordy)` : permet de changer la coordonnée y de la cellule.

`void inverseEtat()` : permet l’inversion de l’état d’une cellule.

#### Classe : GestionFichier

`vector<int> dimensionsGrille()` : lit la 1ère ligne du fichier et retourne la taille de la grille (longueur, largeur) dans un vecteur. 

`vector<vector<int>> contenueGrille()` : lit le contenu de la grille (après la 1ère ligne) et retourne la matrice d'entiers représentant l'état des cellules dans un vecteur de deux dimensions. 

`void initialiserDossierSauvegarde()` : crée un dossier de sauvegarde nommé avec la date et l'heure actuelles. 

`void sauvegarderEtatGrille(const vector<vector<int>>& grille, int iteration)` : sauvegarde l'état de la grille dans un fichier texte au sein du dossier de sauvegarde. Prend en paramètre la grille sous forme de vecteur de 2 dimensions et l'itération correspondante à la grille. 

#### Classe : Grille 

`void initialiseDepuisFichier()` : permet l’initialisation de la grille à partir du fichier donné. 

`void miseAJour()` : permet la mise à jour de chaque cellule de la grille selon les différentes règles du jeu. 

`bool EstCellVivant(int x, int y)` : permet de dire si la cellule à la position `(x,y)` de la grille est vivante ou morte. Prend en paramètre les coordonnées de la cellule à regarder. Retourne `true` si elle est vivante et `false` si elle est morte. 

`void setCellVivant(int x, int y, bool etat)` : permet de changer l'état de la cellule à la position `(x,y)`. Prend en paramètre les coordonnées de la cellule à modifier et le nouvel état à lui affecter.

`int countVoisins(int x, int y)` : permet de compter les voisins vivants autour d’une cellule à la position `(x,y)`. Prend en paramètre les coordonnées de la cellule à analyser. Retourne le nombre de voisins vivants. 

`void afficher()` : permet d’afficher l’état de la grille dans le terminal, où on a `1` (vivant) et `0` (mort).  

`vector<vector<int>> getEtatActuel() const` : permet de donner l’état actuel de la grille sous forme de matrice d’entiers où l’on a `1` pour vivant et `0` pour mort. Retourne l'état de la grille dans un vecteur à deux dimensions. 

`bool estStable(const vector<vector<int>>& etatPrecedent)` : permet de vérifier si l’état actuel de la grille est identique à son état précédent. Prend en paramètre l'état précédent de la grille sous forme de vecteur de deux dimensions et retourne vrai si l'état n'a pas changé et faux s'il a changé. 

#### Classe : MgraphSFML

`void creeFenetre()` : permet de créer une fenêtre graphique simple avec un fond noir. 

`void renduCell(int x, int y, Color color)` : permet de dessiner une cellule à une position donnée avec une couleur de son choix. Prend en paramètre les coordonnées de la cellule à colorier ainsi que la couleur à attribuer à la cellule. 

`void handleEvents()` : permet la gestion des actions de l’utilisateur. Par exemple, le fait d'appuyer sur la croix permet de fermer la fenêtre. 

`void closeFenetre()` : permet la fermeture de la fenêtre graphique. 

`void displayFenetre()` : permet d’afficher le contenu dessiné dans la fenêtre. 

`void renduGrille(const Grille& grille, int longu, int larg)` : permet d’afficher la grille sur la fenêtre. Les cellules qui sont en bleu sont vivantes et celles en blanc sont mortes. Prend en paramètre la grille à afficher et les dimensions de la grille. 

`bool estOuverte() const` : permet de savoir si une fenêtre est ouverte ou non en renvoyant `true` ou `false`.

#### Différentes bibliothèques utilisées dans le programme

- **Iostream** : bibliothèque permettant l’utilisation des flux d’entrée et de sortie standard en C++. Pour faire l'équivalent des prints par exemple. 
- **Vector** : bibliothèque permettant de travailler avec des vecteurs. Pour gérer notre grille contenant les cellules par exemple. 
- **Fstream** : bibliothèque permettant de lire ou d’écrire dans des fichiers. 
- **Filesystem** : bibliothèque permettant la gestion des fichiers et des répertoires. 
- **Iomanip** : bibliothèque permettant la manipulation des entrées et sorties de manière plus précise. 
- **Thread** : bibliothèque permettant de travailler sur des threads (thread = flux d’exécution dans un programme). 
- **Chrono** : bibliothèque permettant la manipulation et la prise de mesure des durées et intervalles ; elle permet aussi de travailler avec des horloges. 

## Documentation utilisateur 

### Prérequis pour lancer le jeu

Pour lancer le jeu, vous aurez besoin d'installer plusieurs choses :
- Un compilateur C++ pour pouvoir exécuter le code sur votre appareil.
- La bibliothèque **Simple and Fast Multimedia Library (SFML)** pour la gestion des fenêtres graphiques.
- Un environnement Linux (l’environnement Linux n’est pas obligatoire pour lancer le jeu, mais la documentation suppose que vous êtes en environnement Linux).

### Installation de la bibliothèque 

Pour installer la bibliothèque SFML, il vous faudra suivre les commandes suivantes :

<div align='center'>
  sudo apt update 
  
  sudo apt upgrade  
  sudo apt-get install libsfml-dev  
  brew install sfml  
</div>

### Lancement du jeu

Pour pouvoir lancer le jeu, il faut tout d'abord télécharger les fichiers du code source dans un dossier. 
Ensuite, il faut ouvrir un terminal et se placer dans le dossier contenant les différents fichiers du programme. 
Sous un environnement Linux, vous pouvez vous déplacer grâce aux commandes `cd nomDossier` et `cd..`.
Ensuite, il va falloir compiler les fichiers du programme. Pour ce faire, si vous êtes dans l’environnement Linux et que vous avez installé le compilateur `g++`, vous pouvez créer un exécutable grâce à la commande : 
<div align='center'>
  g++ main.cpp cell.cpp Grille.cpp GestionFichier.cpp MgraphSFML.cpp -o programme -lsfml-graphics -lsfml-window -lsfml-system
  
</div>

Puis il ne vous reste plus qu'à lancer le programme en tapant la commande 
<div align='center'>
  ./programme
</div>

### Principes du jeu
- **Règle 1** : Une cellule morte possédant exactement trois voisines vivantes devient vivante. 
- **Règle 2** : Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.

### Comment jouer

Une fois que le jeu est lancé avec la commande `./programme`, il va vous demander de rentrer le chemin d’accès du fichier source (le fichier contenant la grille de départ).
Vous pourrez alors rentrer `test.txt`, par exemple, comme dans l'exemple ci-contre : 

<p align="center">
  <img src="https://github.com/user-attachments/assets/65487e92-eb63-480d-a9a0-53591cdd7471" />
</p>

Ensuite, vous arriverez dans un menu vous permettant de choisir les différents modes de jeu ou de quitter le jeu : 

<p align="center">
  <img src="https://github.com/user-attachments/assets/d1e320c3-d4ac-4411-8ae3-35ee0fdffcfe" />
</p>


Si vous choisissez le mode console, il vous permettra de choisir le nombre d’itérations et vous donnera l’évolution des cellules dans votre console sous forme de nombres entiers avec `1` pour vivant et `0` pour mort. Par exemple :

<p align="center">
  <img src="https://github.com/user-attachments/assets/07bf7fd1-6584-48b6-b6c8-7580cada6532" />
</p>


Le mode graphique, quant à lui, permet l’ouverture d’une interface graphique avec les cellules vivantes en bleu et celles mortes en blanc. Le jeu se termine lorsque toutes les cellules sont mortes ou lorsque la grille atteint un état stable. Par exemple : 

<p align="center">
  <img src="https://github.com/user-attachments/assets/1f680181-420e-4939-8897-7c7b45da96cd" />
</p>

Ensuite, vous pouvez quitter le jeu en choisissant l'option numéro 4. 


# Conclusion 

Pour conclure , la documentation du JEU DE LA VIE permet d'avoir une vision complète sur l'aspect technique et utilisateur du jeu.La partie technique fait une description de l'architecture POO , les classes, les méthodes et les bibbliothèques utilisées facilitant la compréhension du code.La documentation utilisateur  guide l'installation, la compilation et l'exécution du jeu en modes console et graphique. Cette double perception garantit une compréhension rapide et claire du fonctionnement du projet.
