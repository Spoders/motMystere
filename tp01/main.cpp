#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int calculeLigne();
string chercheMotAlea(int nombreDeLigne);
string melangeMot(string motMystere);

  int main() {
	string motMystere, motMelange;
	int nombreDeLigne = 0;

	nombreDeLigne = calculeLigne();							//Calcule du nombre de ligne du dictionnaire
	motMystere = chercheMotAlea(nombreDeLigne);				//Recherche d'un mot mystere
	motMelange = melangeMot(motMystere);

	cout << motMystere << endl;
	cout << motMelange << endl;

	system("PAUSE");
	return 0;
}

string chercheMotAlea(int nombreDeLigne) {
	srand(time(0));
	string motMysteres, ligne;
	int ligneAléatoire, ligneSuivie = 0;
	ifstream dictionnaireMot("C:/Users/vrumm/Desktop/Programme Langage C/tp01/motMystere/dico.txt"); 

	//Trouve un ligne aléatoire et stock le mot
	ligneAléatoire = rand() % nombreDeLigne;

	if (dictionnaireMot) {
		while (getline(dictionnaireMot, ligne)) {
			ligneSuivie++;
			if (ligneSuivie == ligneAléatoire) {
				motMysteres = ligne;
			}
		}
	}
	else {
		cout << "Impossible d'ouvrire le dictionnaire" << endl;
	}
	dictionnaireMot.close();

	return motMysteres;
}

int calculeLigne() {
	int nombreDeLigne = 0;
	string ligne;
	ifstream dictionnaireMot("C:/Users/vrumm/Desktop/Programme Langage C/tp01/motMystere/dico.txt"); //Ouvre le fichier dictionnaire

	//Compte le nombre de ligne du dictionnaire
	if (dictionnaireMot) {
		while (getline(dictionnaireMot, ligne)) {
			nombreDeLigne++;
		}
		dictionnaireMot.close();
	}
	else {
		cout << "Impossible d'ouvrire le dictionnaire" << endl;
	}

	return nombreDeLigne;
}

string melangeMot(string motMystere) {
	srand(time(0));
	int posLettre;
	string motMelange;

	do {
		posLettre = rand() % motMystere.size();
		motMelange += motMystere[posLettre];
		motMystere.erase(posLettre);
	} while (motMystere.size() != 0);

	return motMelange;
}