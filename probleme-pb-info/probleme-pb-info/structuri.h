#include <iostream>
#include <fstream>
#include <string>

using namespace std;

struct Interval {
	int st;
	int dr;

	int countIntersectate(Interval x[], int n, int j) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (i != j) {
				if ((x[i].st >= st && x[i].st <= dr) || (x[i].dr <= dr && x[i].dr >= st)) {
					c++;
				}
			}
		}
		return c;
	}
};

struct Elev {
	int cod;
	int medie;
	int absente;

	bool media10() {
		if (medie == 10) {
			return true;
		}
		return false;
	}
};

struct Bilet {
	string prenume;
	string nume;
	bool platit;
	
	int penalizari(Bilet x[], int n) {
		int c = 0;
		for (int i = 0; i < n; i++) {
			if (x[i].prenume == prenume && x[i].nume == nume && x[i].platit == 0) {
				c++;
			}
		}
		return c;
	}

	bool apare(string prenumex[], string numex[], int n, int j) {
		for (int i = 0; i < n; i++) {
			if (prenumex[i] == prenume && numex[i] == nume && j != i) {
				return 1;
			}
		}
		return 0;
	}
};

struct Elev2 {
	string nume;
	string prenume;
	int media1;
	int media2;
	int media3;

	double medie() {
		return (double)(media1 + media2 + media3) / 3;
	}
};

struct Uniforma {
	int nr;
	int tip;
};

struct Eveniment {
	int ore;
	int minute;
	int secunde;

	int durataInSecunde() {
		return ore * 60 * 60 + minute * 60 + secunde;
	}
};

struct Date {
	string prenume;
	string nume;
	int salariu;
	int varsta;
	string functie;
	string numartelefon;
	string email;
};