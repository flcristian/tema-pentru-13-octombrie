#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Caracter {
private:
	string nume;
	string clasa;
	int nivel;
	bool administrator;

public:
	Caracter(string nume, string clasa, int nivel, bool administrator) {
		this->nume = nume;
		this->clasa = clasa;
		this->nivel = nivel;
		this->administrator = administrator;
	}

	Caracter() {
		this->nume = "Guest";
		this->clasa = "Unknown";
		this->nivel = 1;
		this->administrator = 0;
	}

	string getNume() {
		return this->nume;
	}

	string getClasa() {
		return this->clasa;
	}

	int getNivel() {
		return this->nivel;
	}

	void setNume(string nume) {
		this->nume = nume;
	}

	void setClasa(string clasa) {
		this->clasa = clasa;
	}

	void setNivel(int nivel) {
		this->nivel = nivel;
	}

	bool isAdministrator() {
		return this->administrator;
	}

	void setAdministratorStatus(bool administrator) {
		this->administrator = administrator;
	}

	void descriereCaracter() {
		cout << "Nume : " << this->nume << endl;
		cout << "Clasa : " << this->clasa << endl;
		cout << "Nivel : " << this->nivel << endl;
		cout << "Administrator : ";
		if (this->administrator == 1) {
			cout << "Da";
		}
		else {
			cout << "Nu";
		}
		cout << endl;
	}
};