#pragma once
#include <vector>

// Affiche le menu de s�lection des op�rations
void afficherMenu();

// G�re le choix de l'utilisateur et appelle la fonction correspondante
void gererChoix(std::vector<int> & nombre1, std::vector<int> & nombre2, char& operateur, bool& erreur); 
