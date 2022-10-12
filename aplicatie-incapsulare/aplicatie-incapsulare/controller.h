#include "structuri.h"

struct Control {
private:
	Caracter caractere[100];
	int n = 0;

public:
	Control() {
		citire();
	}

	void addCaracter(Caracter x) {
		this->caractere[n] = x;
		this->n++;
	}

	void deleteCaracter(int i) {
		for (int j = i; j < n - 1; j++) {
			this->caractere[j] = this->caractere[j + 1];
		}
		this->n--;
	}

	void citire() {
		ifstream f("caractere.txt");

		while (!f.eof()) {
			string nume;
			string clasa;
			int nivel;
			bool administrator;

			f >> nume;
			f >> clasa;
			f >> nivel;
			f >> administrator;

			Caracter x(nume, clasa, nivel, administrator);

			this->addCaracter(x);
		}
		f.close();
	}

	int getDim() {
		return this->n;
	}

	void setDim(int n) {
		this->n = n;
	}

	void sortareNivel() {
		bool flag = true;
		do {
			flag = true;
			for (int i = 0; i < this->n - 1; i++) {
				if (this->caractere[i].getNivel() > this->caractere[i + 1].getNivel()) {
					Caracter r = this->caractere[i];
					this->caractere[i] = this->caractere[i + 1];
					this->caractere[i + 1] = r;
					flag = false;
				}
			}
		} while (flag == false);
	}

	int sortareString(string a, string b) {
		for (int i = 0; a[i] > 10 && a[i] < 150 && b[i] > 10 && b[i] < 150; i++) {
			if (a[i] > b[i]) {
				return 1;
			}
			if (a[i] < b[i]) {
				return 0;
			}
		}
		return -1;
	}

	void sortareAlfabeticaNume() {
		bool flag = true;
		do {
			flag = true;
			for (int i = 0; i < this->n - 1; i++) {
				if (sortareString(this->caractere[i].getNume(), this->caractere[i + 1].getNume()) == 1) {
					Caracter r = this->caractere[i];
					this->caractere[i] = this->caractere[i + 1];
					this->caractere[i + 1] = r;
					flag = false;
				}
			}
		} while (flag == false);
	}

	void sortareAlfabeticaClasa() {
		bool flag = true;
		do {
			flag = true;
			for (int i = 0; i < this->n - 1; i++) {
				if (sortareString(this->caractere[i].getClasa(), this->caractere[i + 1].getClasa()) == 1) {
					Caracter r = this->caractere[i];
					this->caractere[i] = this->caractere[i + 1];
					this->caractere[i + 1] = r;
					flag = false;
				}
			}
		} while (flag == false);
	}

	void modificareNumeIndice(int i, string nume) {
		this->caractere[i].setNume(nume);
	}

	void modificareClasaIndice(int i, string clasa) {
		this->caractere[i].setClasa(clasa);
	}

	void modificareNivelIndice(int i, int nivel) {
		this->caractere[i].setNivel(nivel);
	}

	void makeAdmin(int i) {
		this->caractere[i].setAdministratorStatus(1);
	}

	void revokeAdmin(int i) {
		this->caractere[i].setAdministratorStatus(0);
	}

	Caracter getCaracter(int i) {
		return this->caractere[i];
	}
};