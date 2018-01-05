#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int calculeLigne();
string chercheMotAlea(int nombreDeLigne);

ifstream dictionnaireMot("C:/Users/vrumm/Desktop/Programme Langage C/tp01/motMystere/dico.txt"); //Ouvre le fichier dictionnaire

int main() {
	string motMystere;
	int nombreDeLigne = 0;

	nombreDeLigne = calculeLigne();
	motMystere = chercheMotAlea(nombreDeLigne);
	cout << motMystere << endl;

	system("PAUSE");
	return 0;
}

string chercheMotAlea(int nombreDeLigne) {
	srand(time(0));
	string motMystere, ligne;
	int ligneAléatoire;

	//Trouve un ligne aléatoire et stock le mot
	ligneAléatoire = rand() % nombreDeLigne;

	nombreDeLigne = 0;
	while (getline(dictionnaireMot, ligne)) {
		nombreDeLigne++;
		if (nombreDeLigne == ligneAléatoire) {
			motMystere = ligne;
		}
	}

	return motMystere;
}

int calculeLigne() {
	int nombreDeLigne = 0;
	string ligne;

	//Compte le nombre de ligne du dictionnaire
	if (dictionnaireMot) {
		while (getline(dictionnaireMot, ligne)) {
			nombreDeLigne++;
		}
	}
	else {
		cout << "Impossible d'ouvrire le dictionnaire" << endl;
	}

	return nombreDeLigne;
}