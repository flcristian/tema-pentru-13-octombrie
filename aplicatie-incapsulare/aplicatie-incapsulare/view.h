#include "controller.h"

struct View {
private:
	Control control;

	void meniu() {
		cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
		cout << "Introduceti :" << endl;
		cout << "- 1 pentru a afisa lista de caractere" << endl;
		cout << "- 2 pentru a sorta dupa nivel" << endl;
		cout << "- 3 pentru a salva lista de caractere peste fisierul 'out.txt'" << endl;
		cout << "- 4 pentru a sorta alfabetic dupa nume" << endl;
		cout << "- 5 pentru a modifica unul dintre caractere" << endl;
		cout << "- 6 pentru a arata lista de administratori" << endl;
		cout << "- 7 pentru a atribui unui caracter functia de administrator" << endl;
		cout << "- 8 pentru a salva lista de administratori peste fisierul 'out.txt'" << endl;
	}

	void play() {
		int i, c;
		string nume, clasa;
		int nivel;
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
				control.sortareNivel();
				afisare();
				break;
			case 3:
				salvare();
				cout << "=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=" << endl;
				cout << "Fisierul a fost salvat!" << endl;
				break;
			case 4:
				control.sortareAlfabetica();
				afisare();
				break;
			case 5:
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
					break;
				default:
					break;
				}
				afisare();
				break;
			case 6:
				afisareAdministratori();
				break;
			case 7:
				cout << "Introduceti indicele caracterului care doriti sa fie administrator :" << endl;
				cout << "Numar de la 1 - " << control.getDim() << "." << endl;
				cin >> i;
				i--;
				control.makeAdmin(i);
				afisareAdministratori();
				break;
			case 8:
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
		for (int i = 0; i < this->control.getDim(); i++) {
			Caracter x = this->control.getCaracter(i);
			if (x.isAdministrator()) {
				x.descriereCaracter();
			}
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