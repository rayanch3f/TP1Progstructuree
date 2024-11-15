#include "LectureEtAffichage.h"
#include <iostream>
#include <vector>
#include "Calculatrice.h"



using namespace std;



//Fonction qui transforme un caractère numérique('0' à '9') en entier(0 à 9)

int convertir_chiffre(char nombre)

{

	vector<char> conversion_chiffre = { '0', '1', '2', '3', '4', '5', '6', '7', '8', '9' };

	for (int b = 0; b < conversion_chiffre.size(); b++)

	{
		if (conversion_chiffre.at(b) == nombre)

		{

			return b;
		}

	}

	return -1; // On va Retourner - 1 si le caractère n'est pas un chiffre acceptable

}

//Fonction qui prend en entrée le premier nombre et l'opérateur 

bool lire_premier_nombre_et_operateur(vector<int>& nombre1, char& operateur)

{

	nombre1.clear();  // sa sert à Réinitialiser le vecteur 

	char chiffre;

	cin >> chiffre;


	// Une boucle qui vérifie que le chiffre du nombre1 est effectivement un chiffre, puis le convertit

	while (chiffre >= '0' && chiffre <= '9')

	{

		nombre1.push_back(convertir_chiffre(chiffre)); // Ajoute chaque numéro à la liste.

		cin >> chiffre;

	}

	inverser(nombre1); // Inversez l'ordre des chiffres pour qu'il corresponde à l'affichage

	rogner_zeros_inutiles(nombre1);   // Il sert à Supprimer les zéros inutiles au début du nombre



	operateur = chiffre;



	//  s'assure que l'opérateur est correct

	switch (operateur)

	{

	case '+':

	case '-':

	case '*':

	case 'x':

	case 'X':

	case '/':

	case '%':

	case '^':
		//Si le premier nombre est correct, renvoie vrai.
		if (nombre1.empty())

		{

			return false;

		}

		return true;

		break;



	default: return false;

		break;

	}

}



//Fonction qui lit le second nombre, de manière semblable à la première fonction de lecture.

bool lire_deuxieme_nombre(vector<int>& nombre2)

{

	nombre2.clear();

	char nombre;

	cin >> nombre;



	// On s'assure qu'il s'agit bien de chiffres

	while (nombre >= '0' && nombre <= '9')

	{

		nombre2.push_back(convertir_chiffre(nombre));

		cin >> nombre;

	}

	inverser(nombre2);

	rogner_zeros_inutiles(nombre2);



	//Vérifie que l'entrée se termine par ' = ' pour indiquer la fin de l'opération

	if (nombre == '=')

	{
		if (nombre2.empty())

		{
			return false;
		}

		return true;

	}

	else

	{

		return false;

	}

}


//Cette fonction présente les résultats dans un format approprié, en insérant des espaces tous les trois chiffres.
void afficher(vector<int>& resultat)

{
	for (int i = resultat.size() - 1; i >= 0; i--)

	{
		cout << resultat.at(i);
		// sa sert à ajouter un espace après chaque groupe de 3 chiffres
		if (i % 3 == 0)

		{
			cout << " ";
		}

	}

}

void lireNombre(vector<int>& nombre)
{
}

void afficherResultat(const vector<int>& resultat)
{
}

int convertirCaractere(char c)
{
	return 0;
}

void inverserVecteur(vector<int>& nombre)
{
}











