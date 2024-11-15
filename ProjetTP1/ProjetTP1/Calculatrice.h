#pragma once
#include <iostream>

#include <vector>

#include "UtilitairesVecteur.h"

#include "Calculatrice.h"

#include "LectureEtAffichage.h"



using namespace std;



// Biblioth�que qui permettra de calculer selon les op�rations arithm�tiques



// Fonction qui permet de d�terminer quel calcul est � faire selon l'op�rateur donn�

vector<int> exposant(vector<int>& nombre1, vector<int>& nombre2);

vector<int> calculer(vector<int> nombre1, char operateur, vector<int> nombre2, bool& erreur);

vector<int> addition(vector<int> nombre1, vector<int> nombre2);
