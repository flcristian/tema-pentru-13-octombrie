#include "controller.h"

struct View {
private:
	Control control;

	void meniu() {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		if (control.getDim() == 0) {
			cout << "ATENTIE! Nu exista niciun caracter!" << endl;
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		}
		cout << "Introduceti :" << endl;
		cout << "- 1 pentru a afisa lista de caractere" << endl;
		cout << "- 2 pentru a afisa lista de administratori" << endl;
		cout << "- 3 pentru a sorta dupa nivel" << endl;
		cout << "- 4 pentru a sorta alfabetic dupa nume" << endl;
		cout << "- 5 pentru a sorta alfabetic dupa clasa" << endl;
		cout << "- 6 pentru a modifica unul dintre caractere" << endl;
		cout << "- 7 pentru a adauga un caracter" << endl;
		cout << "- 8 pentru a sterge unul dintre caractere" << endl;
		cout << "- 9 pentru a atribui unui caracter functia de administrator" << endl;
		cout << "- 10 pentru a scoate functia de administrator a unui caracter" << endl;
		cout << "- 11 pentru a salva lista de caractere peste fisierul 'out.txt'" << endl;
		cout << "- 12 pentru a salva lista de administratori peste fisierul 'out.txt'" << endl;
	}

	void play() {
		int i, c;
		string nume, clasa;
		int nivel;
		Caracter x;
		bool running = true;
		int p;

		while (running == true) {
			meniu();
			cin >> p;

			switch (p)
			{
			case 1:
				afisare();
				break;
			case 2:
				afisareAdministratori();
				break;
			case 3:
				control.sortareNivel();
				afisare();
				break;
			case 4:
				control.sortareAlfabeticaNume();
				afisare();
				break;
			case 5:
				control.sortareAlfabeticaClasa();
				afisare();
				break;
			case 6:
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Introduceti indicele caracterului pe care doriti sa il modificati :" << endl;
				cout << "Numar de la 1 - " << control.getDim() << "." << endl;
				cin >> i;
				i--;
				cout << "Introduceti valoarea pe care varibila sa o modificati :" << endl;
				cout << "1 - Nume ; 2 - Clasa ; 3 - Nivel" << endl;
				cin >> c;

				switch (c)
				{
				case 1:
					cout << "Introduceti numele : ";
					cin >> nume;
					control.modificareNumeIndice(i, nume);
					break;
				case 2:
					cout << "Introduceti clasa : ";
					cin >> clasa;
					control.modificareClasaIndice(i, clasa);
					break;
				case 3:
					cout << "Introduceti nivelul : ";
					cin >> nivel;
					control.modificareNivelIndice(i, nivel);
					cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
					cout << "Caracterul a fost modificat!" << endl;
					break;
				default:
					break;
				}
				afisare();
				break;
			case 7:
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Introduceti numele caracterului : ";
				cin >> nume;
				cout << "Introduceti clasa caracterului : ";
				cin >> clasa;
				cout << "Introduceti nivelul caracterului : ";
				cin >> nivel;
				x.setNume(nume);
				x.setClasa(clasa);
				x.setNivel(nivel);
				control.addCaracter(x);
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Caracterul a fost adaugat!" << endl;
				afisare();
				break;
			case 8:
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Introduceti indicele caracterului care doriti sa fie sters :" << endl;
				cout << "Numar de la 1 - " << control.getDim() << "." << endl;
				cin >> i;
				i--;
				control.deleteCaracter(i);
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Caracterul a fost sters!" << endl;
				afisare();
				break;
			case 9:
				cout << "Introduceti indicele caracterului care doriti sa fie administrator :" << endl;
				cout << "Numar de la 1 - " << control.getDim() << "." << endl;
				cin >> i;
				i--;
				control.makeAdmin(i);
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Caracterul este acum un administrator!" << endl;
				afisareAdministratori();
				break;
			case 10:
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Introduceti indicele caracterului caruia doriti sa ii scoateti functia de administrator :" << endl;
				cout << "Numar de la 1 - " << control.getDim() << "." << endl;
				cin >> i;
				i--;
				control.revokeAdmin(i);
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Caracterul nu mai are functia de administrator!" << endl;
				afisareAdministratori();
				break;
			case 11:
				salvare();
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Fisierul a fost salvat!" << endl;
				break;
			case 12:
				salvareAdministratori();
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Fisierul a fost salvat!" << endl;
				break;
			default:
				break;
			}
		}
	}

public:
	View() {
		play();
	}

	void afisare() {
		for (int i = 0; i < this->control.getDim(); i++) {
			Caracter x = this->control.getCaracter(i);
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Indice : " << i + 1 << endl;
			x.descriereCaracter();
		}
	}

	void salvare() {
		ofstream f("out.txt");
		for (int i = 0; i < this->control.getDim(); i++) {
			Caracter x = this->control.getCaracter(i);
			f << x.getNume() << " " << x.getClasa() << " " << x.getNivel() << " " << x.isAdministrator() << endl;
		}
	}

	void afisareAdministratori() {
		int c = 0;
		for (int i = 0; i < this->control.getDim(); i++) {
			Caracter x = this->control.getCaracter(i);
			if (x.isAdministrator()) {
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Indice : " << i + 1 << endl;
				x.descriereCaracter();
				c++;
			}
		}
		if (c == 0) {
			cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
			cout << "Nu exista administratori!" << endl;
		}
	}

	void salvareAdministratori() {
		ofstream f("out.txt");
		for (int i = 0; i < this->control.getDim(); i++) {
			Caracter x = this->control.getCaracter(i);
			if (x.isAdministrator()) {
				f << x.getNume() << " " << x.getClasa() << " " << x.getNivel() << " " << x.isAdministrator() << endl;
			}
		}
	}
};