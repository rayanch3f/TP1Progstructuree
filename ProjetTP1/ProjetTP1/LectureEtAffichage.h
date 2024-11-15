#pragma once
//Biblioth�que donnant des fonctions pratiques pour manipuler des vecteurs d'entiers.
#include "LectureEtAffichage.h"
#include <iostream>
#include <vector>
#include "Calculatrice.h"

using namespace std;

// Inverse l'ordre des valeurs dans le vecteur d'entiers donn�.
// Par exemple, si le vecteur contient { 1, 2, 3 } lors de l'appel,
// il contiendra { 3, 2, 1 } apr�s l'ex�cution de la fonction
void inverser(vector<int>& nombre);


// Enl�ve les z�ros inutiles au d�but d'un nombre repr�sent� sous la forme d'un vecteur invers�
// Par exemple, le vecteur invers� repr�sentant le nombre 123 est { 3, 2, 1 }
// Si des z�ros inutiles sont pr�sents dans le nombre (00123), le vecteur contient { 3, 2, 1, 0, 0 }
// Dans ce cas, nombre { 3, 2, 1 } apr�s l'ex�cution de la fonction
void rogner_zeros_inutiles(vector<int>& nombre);


bool lire_premier_nombre_et_operateur(vector<int>& nombre1, char& operateur);

bool lire_deuxieme_nombre(vector<int>& nombre2);

void afficher(vector<int>& resultat);


// Fonction pour lire un nombre sous forme de vecteur d'entiers
void lireNombre(vector<int>& nombre);

// Afficher le r�sultat sous forme de vecteur d'entiers
void afficherResultat(const vector<int>& resultat);

// Conversion d'un caract�re en un entier
int convertirCaractere(char c);

// Inverser vecteur d'entiers
void inverserVecteur(vector<int>& nombre);
