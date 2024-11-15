#pragma once
// Bibliothèque fournissant des fonctions utilitaires pour l'utilisation de vecteurs d'entiers

#include <vector>


// Inverse l'ordre des valeurs dans le vecteur d'entiers donné.
// Par exemple, si le vecteur contient { 1, 2, 3 } lors de l'appel,
// il contiendra { 3, 2, 1 } après l'exécution de la fonction
void inverser(std::vector<int>& nombre);


// Enlève les zéros inutiles au début d'un nombre représenté sous la forme d'un vecteur inversé
// Par exemple, le vecteur inversé représentant le nombre 123 est { 3, 2, 1 }
// Si des zéros inutiles sont présents dans le nombre (00123), le vecteur contient { 3, 2, 1, 0, 0 }
// Dans ce cas, nombre { 3, 2, 1 } après l'exécution de la fonction
void rogner_zeros_inutiles(std::vector<int>& nombre);
