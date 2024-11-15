// Biblioth�que fournissant des fonctions utilitaires pour l'utilisation de vecteurs d'entiers
#include "UtilitairesVecteur.h"

using namespace std;


// Permutte les valeurs de 2 variables enti�res
// nb1, nb2: R�f�rences sur les variables � permutter
void permutter_entiers(int& nb1, int& nb2)
{
   int tmp = nb1;
   nb1 = nb2;
   nb2 = tmp;
}


//
// Fonctions d�clar�es dans UtilitairesVecteur.h
//

void inverser(vector<int>& nombre)
{
   // Pour toutes les positions du d�but jusqu'� la moiti�
   for (int i = 0; i < nombre.size() / 2; ++i)
   {
      // On permutte la valeur avec la position sym�trique � partir de la fin
      permutter_entiers(nombre.at(i), nombre.at(nombre.size() - 1 - i));
   }
}


void rogner_zeros_inutiles(vector<int>& nombre)
{
   // Puisque les nombres sont invers�s, il faut enlever les 0 de la fin du vecteur
   // Tant que vecteur contient plus d'un chiffre (n�cessaire pour g�rer le cas o� le nombre est z�ro car on doit laisser un z�ro),
   // et que le dernier chiffre est z�ro
   while (nombre.size() > 1 && nombre.at(nombre.size() - 1) == 0)
   {
      // On enl�ve le z�ro � la fin
      nombre.pop_back();
   }
}
