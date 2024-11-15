#pragma once
//Bibliothèque donnant des fonctions pratiques pour manipuler des vecteurs d'entiers.
#include "LectureEtAffichage.h"
#include <iostream>
#include <vector>
#include "Calculatrice.h"

using namespace std;

// Inverse l'ordre des valeurs dans le vecteur d'entiers donné.
// Par exemple, si le vecteur contient { 1, 2, 3 } lors de l'appel,
// il contiendra { 3, 2, 1 } après l'exécution de la fonction
void inverser(vector<int>& nombre);


// Enlève les zéros inutiles au début d'un nombre représenté sous la forme d'un vecteur inversé
// Par exemple, le vecteur inversé représentant le nombre 123 est { 3, 2, 1 }
// Si des zéros inutiles sont présents dans le nombre (00123), le vecteur contient { 3, 2, 1, 0, 0 }
// Dans ce cas, nombre { 3, 2, 1 } après l'exécution de la fonction
void rogner_zeros_inutiles(vector<int>& nombre);


bool lire_premier_nombre_et_operateur(vector<int>& nombre1, char& operateur);

bool lire_deuxieme_nombre(vector<int>& nombre2);

void afficher(vector<int>& resultat);


// Fonction pour lire un nombre sous forme de vecteur d'entiers
void lireNombre(vector<int>& nombre);

// Afficher le résultat sous forme de vecteur d'entiers
void afficherResultat(const vector<int>& resultat);

// Conversion d'un caractère en un entier
int convertirCaractere(char c);

// Inverser vecteur d'entiers
void inverserVecteur(vector<int>& nombre);
