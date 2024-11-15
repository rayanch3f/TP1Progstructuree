#pragma once
#include <iostream>

#include <vector>

#include "UtilitairesVecteur.h"

#include "Calculatrice.h"

#include "LectureEtAffichage.h"



using namespace std;



// Bibliothèque qui permettra de calculer selon les opérations arithmétiques



// Fonction qui permet de déterminer quel calcul est à faire selon l'opérateur donné

vector<int> exposant(vector<int>& nombre1, vector<int>& nombre2);

vector<int> calculer(vector<int> nombre1, char operateur, vector<int> nombre2, bool& erreur);

vector<int> addition(vector<int> nombre1, vector<int> nombre2);
