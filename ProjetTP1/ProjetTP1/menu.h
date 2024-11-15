#pragma once
#include <vector>

// Affiche le menu de sélection des opérations
void afficherMenu();

// Gère le choix de l'utilisateur et appelle la fonction correspondante
void gererChoix(std::vector<int> & nombre1, std::vector<int> & nombre2, char& operateur, bool& erreur); 
