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
	string motMystere, motMelange, motTemporaire, reponse = "n";
	int nombreDeLigne = 0, nbrCoupMax, nbrCoups = 0;

	nombreDeLigne = calculeLigne();								//Calcule du nombre de ligne du dictionnaire
	do {
		cout << "Chargement" << endl;
		motMystere = chercheMotAlea(nombreDeLigne);				//Recherche d'un mot mystere
		motMelange = melangeMot(motMystere);					//Melange les lettres du mots
		system("cls");
		cout << "Quel est le nombre maximale de coups : ";
		cin >> nbrCoupMax;

		do {													//Boucle demande mot mystere
			system("cls");
			cout << motMystere << endl;
			cout << "Il te reste " << nbrCoupMax - nbrCoups << " coups" <<endl;
			cout << "Quel est le mot mystére : ";
			cout << motMelange << endl;
			cin >> motTemporaire;
			nbrCoups++;
			if (nbrCoups == nbrCoupMax) {
				cout << "Tu as perdu ! Tu as utilisé " << nbrCoupMax << " coups" << endl;
				
				system("PAUSE");
				return 0;
			}
		} while (motTemporaire != motMystere);

		cout << "Bravo Tu as gagne" << endl;
		cout << "Veux tu recommencer O/n" << endl;								
		cin >> reponse;
	} while (reponse != "N" && reponse != "n");					//Boucle demande nouvelle essaye

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
		motMelange = motMelange + motMystere[posLettre];
		motMystere.erase(posLettre, 1);
	} while (motMystere.size() != 0);

	return motMelange;
}