// Bibliothèque fournissant des fonctions utilitaires pour l'utilisation de vecteurs d'entiers
#include "UtilitairesVecteur.h"

using namespace std;


// Permutte les valeurs de 2 variables entières
// nb1, nb2: Références sur les variables à permutter
void permutter_entiers(int& nb1, int& nb2)
{
   int tmp = nb1;
   nb1 = nb2;
   nb2 = tmp;
}


//
// Fonctions déclarées dans UtilitairesVecteur.h
//

void inverser(vector<int>& nombre)
{
   // Pour toutes les positions du début jusqu'à la moitié
   for (int i = 0; i < nombre.size() / 2; ++i)
   {
      // On permutte la valeur avec la position symétrique à partir de la fin
      permutter_entiers(nombre.at(i), nombre.at(nombre.size() - 1 - i));
   }
}


void rogner_zeros_inutiles(vector<int>& nombre)
{
   // Puisque les nombres sont inversés, il faut enlever les 0 de la fin du vecteur
   // Tant que vecteur contient plus d'un chiffre (nécessaire pour gérer le cas où le nombre est zéro car on doit laisser un zéro),
   // et que le dernier chiffre est zéro
   while (nombre.size() > 1 && nombre.at(nombre.size() - 1) == 0)
   {
      // On enléve le zéro à la fin
      nombre.pop_back();
   }
}
