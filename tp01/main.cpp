#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <string>

using namespace std;

int calculeLigne();
string chercheMotAlea(int nombreDeLigne);

  int main() {
	string motMystere;
	int nombreDeLigne = 0;

	nombreDeLigne = calculeLigne();
	motMystere = chercheMotAlea(nombreDeLigne);

	system("PAUSE");
	return 0;
}

string chercheMotAlea(int nombreDeLigne) {
	srand(time(0));
	string motMysteres, ligne;
	int ligneAléatoire, ligneSuivie = 0;
	ifstream dictionnaireMot("C:/Users/vrumm/Desktop/Programme Langage C/tp01/motMystere/dico.txt"); //Ouvre le fichier dictionnaire

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