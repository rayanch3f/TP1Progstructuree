

#include "LectureEtAffichage.h"

#include "Calculatrice.h"

#include <iostream>

#include <vector>

#include "UtilitairesVecteur.h"



using namespace std;



//En ajoutant des z�ros au nombre le plus court, cette fonction garantit que les deux nombres aient la m�me longueur pour les op�rations.

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

//Cette fonction effectue une comparaison entre deux nombres repr�sent�s en vecteurs et renvoie true lorsque le premier nombre est sup�rieur au second.sinon, elle renvoie � une erreur.

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



// Effectue la multiplication de deux nombres, exprim�s en vecteurs.
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

// Ce genre de fonction effectue la soustraction entre deux nombres, d�crits par des vecteurs. // Elle g�re les retenues demand�es en cas de r�sultat n�gatif � une position pr�cise.
vector<int> soustraction(vector<int> nombre1, vector<int> nombre2)

{

	rajouter_zero(nombre1, nombre2);
	vector<int> resultat;

	int soustraction = 0;
      int retenue = 0;



	  // Si la valeur de la soustraction des deux chiffres est en bas de 0, une retenue est supprim�e.
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






//Fais la multiplication de deux nombres qui sont pr�sent�s comme des vecteurs.

vector<int> multiplication(vector<int>& nombre1, vector<int>& nombre2)

{

	vector<int> resultat;

	vector<int> Inter;

	int multiplication = 0;

	int retenue = 0;



	
	//voici cette premi�re boucle qui sert a extraire cahque chiffre du nombre2
	for (int i = 0; i < nombre2.size(); i++)

	{
		Inter.clear();
	//Cette boucle sert � ajouter des z�ros
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



		// S'il reste une retenue � la fin, elle est ajout�e au r�sultat interm�diaire

		if (retenue >= 1)

		{
			Inter.push_back(retenue);

		}

		// Le r�sultat final est d�termin� en additionant le r�sultat par le r�sultat interm�diaire de chaque chiffre du nombre2
         resultat = addition(resultat, Inter);

	}

          	return resultat;

}


//Cette fonction r�alise la division ou le calcul du modulo entre deux nombres. En fonction de l'op�rateur utilis�, elle retourne soit le quotient, soit le reste de la division.
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

//Calcule l'exposant de nombre1 � la puissance de nombre2
vector<int> exposant(vector<int>& nombre1, vector<int>& nombre2)
{

vector<int> resultat = {1}; 

while (est_plus_petit(nombre2, resultat)) {
	resultat = multiplication(resultat, nombre1);
}

return resultat;
}

// Fonction qui permet de d�terminer quel calcul est � faire selon l'op�rateur donn�

vector<int> calculer(vector<int> nombre1, char operateur, vector<int> nombre2, bool& erreur)

{
	vector<int> resultat;

	// V�rifie que la division n'est pas effectu�e par 0.

	if (nombre2.size() == 1 && nombre2.at(0) == 0 && (operateur == '/' || operateur == '%'))

	{
		erreur = true;
		return resultat;
	}
	erreur = false;


	// Sa v�rifie que la division n'est pas effectu�e par 0.

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

		resultat = division_Et_modulo(nombre1, nombre2, operateur); // division et modulo dans la m�me fonction

		break;

	case '^':

		resultat = exposant(nombre1, nombre2);

		break;
	}
     return resultat;

}


// Fin 














