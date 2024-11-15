// Calculatrice permettant de faire des opérations arithmétiques de base sur 
// des nombres entiers positifs de taille illimitée

#include "LectureEtAffichage.h"   // Pour lire_premier_nombre_et_operateur, lire_deuxieme_nombre, afficher
#include "Calculatrice.h"         // Pour calculer
#include <iostream>
#include <vector>

using namespace std;


// Calcule le résultat de l'opération composée des 2 nombres et de l'opérateur donné
// et l'affiche
void calculer_et_afficher_resultat(vector<int> nombre1, char operateur, vector<int> nombre2)
{
   bool erreur;
   vector<int> resultat = calculer(nombre1, operateur, nombre2, erreur);

   cout << endl;
   // On affiche le résultat s'il n'y a pas eu d'erreur de calcul
   if (!erreur)
   {
      afficher(resultat);
   }
   else
   {
      // La seule erreur possible est une tentative de division par 0
      cout << "Impossible de diviser par zéro!\n";
   }
   cout << endl;
   system("pause");
}


int main()
{
   setlocale(LC_ALL, "");

   vector<int> nombre1;
   char operateur;
   vector<int> nombre2;

   cout << "Entrez une opération arithmétique: ";
   bool estValide = lire_premier_nombre_et_operateur(nombre1, operateur);

   // Le programme continue tant que des opérations valides sont données
   while (estValide)
   {
      estValide = lire_deuxieme_nombre(nombre2);

      // On fait le calcul que si les données sont valides
      if (estValide)
      {
         calculer_et_afficher_resultat(nombre1, operateur, nombre2);

         // Demande la prochaine opération
         system("cls");
         cout << "Entrez une opération arithmétique: ";
         estValide = lire_premier_nombre_et_operateur(nombre1, operateur);
      }
   }

   // Une syntaxe invalide dans l'opération termine le programme
   cout << "\nOpération invalide - Fin du programme\n";
   system("pause");
}
