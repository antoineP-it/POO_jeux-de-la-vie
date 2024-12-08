# POO_jeux-de-la-vie - Documentation

## Introduction
Le jeu de la vie est un automate cellulaire conçu par le mathématicien John Conway en 1970. Il consiste à simuler l’évolution d’une population de cellules placées dans une grille rectangulaire bidimensionnelle. Chaque cellule possède deux états ,  elle est  soit vivante, soit morte et peut interagir avec ses huit voisines adjacentes. Le jeu évolue sur un intervalle de temps discret, où l’état des cellules est mis à jour après chaque itération selon les règles suivantes :
- Une cellule morte possédant exactement trois voisines vivantes devient vivante.
- Une cellule vivante possédant deux ou trois voisines vivantes reste vivante, sinon elle meurt.
L’objectif de notre projet est l’implémentation de ce jeu en C++ avec des concepts de Programmation Orientée Objet (POO). Le programme devra lire un fichier contenant la taille de grille et l’état initial des cellules. Il devra par la suite mettre à jour l’état des cellules à chaque itération selon les règles du jeu avec la possibilité de choisir de modes de fonctionnement qui sont :
- Mode console : Affichage des itérations sous forme textuelle.
- Mode graphique : affiche la grille et l’état des cellules sur une interface graphique.

Dans ce document, vous retrouverez la documentation technique et utilisateur de notre projet. 
## Documentation technique 

### Architecture générale du programme 

Afin de réspecter les notions de paradigme objet, nous avons séparé chaque classes dans un fichier différent. Pour chaque classes, nous avons un fichier d'en-tête .h qui nous fournit des informations sur les déclarations des classes et des méthodes de celles-ci. Avec ces fichiers, nous avons un fichier .cpp contenant la definition des classes et des méthodes déclarés dans sont .h respectif. Ensuite nous avons le fichier main.cpp qui est le fichier permettant d'appeller toutes nos classes. 
Conformement au diagramme de classe, dans notre projet nous avons :
<p align="center">
  <img src="https://github.com/user-attachments/assets/56f38f8b-0ade-4957-be5a-14498ae6f1a5" />
</p>
<p align='center'>
![image](https://github.com/user-attachments/assets/56f38f8b-0ade-4957-be5a-14498ae6f1a5)
</p>


