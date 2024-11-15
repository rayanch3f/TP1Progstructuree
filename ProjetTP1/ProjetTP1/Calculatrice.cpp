

#include "LectureEtAffichage.h"

#include "Calculatrice.h"

#include <iostream>

#include <vector>

#include "UtilitairesVecteur.h"



using namespace std;



//En ajoutant des zéros au nombre le plus court, cette fonction garantit que les deux nombres aient la même longueur pour les opérations.

vector<int> rajouter_zero(vector<int>& nombre1, vector<int>& nombre2)

{

	if (nombre1.size() < nombre2.size())

	{
		for (int i = nombre1.size(); i < nombre2.size(); i++)

		{
			nombre1.push_back(0);

		}

		return nombre1;
	}

	else
	{
		for (int i = nombre2.size(); i < nombre1.size(); i++)

		{
			nombre2.push_back(0);
		}

		return nombre2;

	}

}

//Cette fonction effectue une comparaison entre deux nombres représentés en vecteurs et renvoie true lorsque le premier nombre est supérieur au second.sinon, elle renvoie à une erreur.

bool est_plus_petit(vector<int>& nombre2, vector<int>& nombre1)

{

	rajouter_zero(nombre1, nombre2);

	for (int i = nombre2.size() - 1; i >= 0; i--)

	{

		if (nombre2.at(i) < nombre1.at(i))

		{

			return true;

		}

		else if (nombre1.at(i) < nombre2.at(i))

		{

			return false;

		}

	}

	return true;

}



// Effectue la multiplication de deux nombres, exprimés en vecteurs.
// On additionne les nombres chiffre par chiffre, en tenant compte de la retenue.

vector<int> addition(vector<int> nombre1, vector<int> nombre2)

{
	rajouter_zero(nombre1, nombre2);
	vector<int> resultat;

	int addition = 0;

	int retenue = 0;

	for (int i = 0; i < nombre1.size(); i++)

	{
        addition = nombre1.at(i) + nombre2.at(i) + retenue;

		retenue = addition / 10;

		addition %= 10;
     	resultat.push_back(addition);

	}
	if (retenue == 1)

	{
         resultat.push_back(retenue);
	}
	return resultat;
}

// Ce genre de fonction effectue la soustraction entre deux nombres, décrits par des vecteurs. // Elle gère les retenues demandées en cas de résultat négatif à une position précise.
vector<int> soustraction(vector<int> nombre1, vector<int> nombre2)

{

	rajouter_zero(nombre1, nombre2);
	vector<int> resultat;

	int soustraction = 0;
      int retenue = 0;



	  // Si la valeur de la soustraction des deux chiffres est en bas de 0, une retenue est supprimée.
	if (est_plus_petit(nombre2, nombre1))

	{

		for (int i = 0; i < nombre1.size(); i++)

		{
			soustraction = nombre1.at(i) - nombre2.at(i) - retenue;


			if (soustraction < 0)

			{
				soustraction += 10;

				retenue = 1;
			}
			else

			{
				retenue = 0;
			}

			resultat.push_back(soustraction);
		}
		rogner_zeros_inutiles(resultat);

		return resultat;
	}

	//on inverse le signe du resultat

	else

	{
		for (int i = 0; i < nombre1.size(); i++)

		{
			soustraction = nombre2.at(i) - nombre1.at(i) - retenue;

			if (soustraction < 0)

			{
				soustraction += 10;
				retenue = 1;
			}
			else
			{
				retenue = 0;

			}

			resultat.push_back(soustraction);
		}

		rogner_zeros_inutiles(resultat);

		resultat.at(resultat.size() - 1) = -resultat.at(resultat.size() - 1);

		return resultat;

	}

}






//Fais la multiplication de deux nombres qui sont présentés comme des vecteurs.

vector<int> multiplication(vector<int>& nombre1, vector<int>& nombre2)

{

	vector<int> resultat;

	vector<int> Inter;

	int multiplication = 0;

	int retenue = 0;



	
	//voici cette première boucle qui sert a extraire cahque chiffre du nombre2
	for (int i = 0; i < nombre2.size(); i++)

	{
		Inter.clear();
	//Cette boucle sert à ajouter des zéros
		for (int zero = 0; zero < i; zero++)

		{

			Inter.push_back(0);

		}
		retenue = 0;

		
		//Cette boucle prend le chiffre actuel de nombre2 et le multiplie par chaque chiffre de nombre1

		for (int j = 0; j < nombre1.size(); j++)

		{

			multiplication = (nombre1.at(j) * nombre2.at(i)) + retenue;

			Inter.push_back(multiplication % 10);

			retenue = multiplication / 10;

		}



		// S'il reste une retenue à la fin, elle est ajoutée au résultat intermédiaire

		if (retenue >= 1)

		{
			Inter.push_back(retenue);

		}

		// Le résultat final est déterminé en additionant le résultat par le résultat intermédiaire de chaque chiffre du nombre2
         resultat = addition(resultat, Inter);

	}

          	return resultat;

}


//Cette fonction réalise la division ou le calcul du modulo entre deux nombres. En fonction de l'opérateur utilisé, elle retourne soit le quotient, soit le reste de la division.
vector<int> division_Et_modulo(vector<int> nombre1, vector<int> nombre2, char operateur)

{
	vector<int> resultat;

	const vector<int> PremierNombre = { 1 };

	vector<int> compteur = { 0 };



	while (est_plus_petit(nombre2, nombre1))
	{
		nombre1 = soustraction(nombre1, nombre2);

		compteur = addition(compteur, PremierNombre);
	}



	if (operateur == '/')

	{
		resultat = compteur;
	}
	else if (operateur == '%')

	{
		rogner_zeros_inutiles(nombre1);

		resultat = nombre1;
	}

	return resultat;

}

//Calcule l'exposant de nombre1 à la puissance de nombre2
vector<int> exposant(vector<int>& nombre1, vector<int>& nombre2)
{

vector<int> resultat = {1}; 

while (est_plus_petit(nombre2, resultat)) {
	resultat = multiplication(resultat, nombre1);
}

return resultat;
}

// Fonction qui permet de déterminer quel calcul est à faire selon l'opérateur donné

vector<int> calculer(vector<int> nombre1, char operateur, vector<int> nombre2, bool& erreur)

{
	vector<int> resultat;

	// Vérifie que la division n'est pas effectuée par 0.

	if (nombre2.size() == 1 && nombre2.at(0) == 0 && (operateur == '/' || operateur == '%'))

	{
		erreur = true;
		return resultat;
	}
	erreur = false;


	// Sa vérifie que la division n'est pas effectuée par 0.

	switch (operateur)
	{

	case '+':

		resultat = addition(nombre1, nombre2);

		break;

	case '-':

		resultat = soustraction(nombre1, nombre2); 

		break;

	case '*':

	case 'x':

	case 'X':

		resultat = multiplication(nombre1, nombre2);

		break;

	case '/':

	case '%':

		resultat = division_Et_modulo(nombre1, nombre2, operateur); // division et modulo dans la même fonction

		break;

	case '^':

		resultat = exposant(nombre1, nombre2);

		break;
	}
     return resultat;

}


// Fin 














