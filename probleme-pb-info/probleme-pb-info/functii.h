#include "structuri.h"

// Problema 1

void citirePb1(Interval x[], int& n) {
	ifstream f("intervale.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i].st;
		f >> x[i].dr;

		if (x[i].st > x[i].dr) {
			int r = x[i].st;
			x[i].st = x[i].dr;
			x[i].dr = r;
		}
	}
}

int rezolvarePb1(Interval x[], int n) {
	int max = 0;
	for (int i = 0; i < n; i++) {
		int count = x[i].countIntersectate(x, n, i);
		if (count > max) {
			max = count;
		}
	}
	return max;
}

// Problema 2

void citirePb2(Elev x[], int& n) {
	ifstream f("elevi.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i].cod;
		f >> x[i].medie;
		f >> x[i].absente;
	}
}

void rezolvarePb2(Elev x[], int n, int& i1, int& i2, int& c, int& medie) {
	c = 0, i1 = 0, i2 = 0;
	int max1 = 0, max2 = 0;
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += x[i].medie;
		if (x[i].media10()) {
			c++;
		}
		if (x[i].absente > max1) {
			max2 = max1;
			i2 = i1;
			max1 = x[i].absente;
			i1 = i;
		}
		else {
			if (x[i].absente > max2) {
				max2 = x[i].absente;
				i2 = i;
			}
		}
	}
	medie = s / n;

	if (x[i1].absente == x[i2].absente) {
		if (x[i2].cod > x[i1].cod) {
			int r = i2;
			i2 = i1;
			i1 = r;
		}
	}
}

// Problema 3

void citirePb3(Bilet x[], int& n) {
	ifstream f("bilete.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i].prenume;
		f >> x[i].nume;
		f >> x[i].platit;
	}
}

int sortareString(string x, string y) {
	for (int i = 0; x[i] > 64 && x[i] < 123; i++) {
		if (x[i] > y[i]) {
			return 1;
		}
		if (x[i] < y[i]) {
			return 0;
		}
	}
	return -1;
}

void sortareAlfabetica(string prenume[], string nume[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			int k = sortareString(prenume[i], prenume[i + 1]);
			if (k != -1) {
				if (k == 1) {
					string r1 = prenume[i];
					string r2 = nume[i];
					prenume[i] = prenume[i + 1];
					prenume[i + 1] = r1;
					nume[i] = nume[i + 1];
					nume[i + 1] = r2;
					flag = false;
				}
			}
			else {
				if (sortareString(nume[i], nume[i + 1]) == 1) {
					string r1 = prenume[i];
					string r2 = nume[i];
					prenume[i] = prenume[i + 1];
					prenume[i + 1] = r1;
					nume[i] = nume[i + 1];
					nume[i + 1] = r2;
					flag = false;
				}
			}
		}
	} while (flag == false);
}

void sortarePart2Pb3(string prenume[], string nume[], int penalizari[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (penalizari[i] != penalizari[i + 1]) {
				if (penalizari[i] < penalizari[i + 1]) {
					string r1 = prenume[i];
					string r2 = nume[i];
					prenume[i] = prenume[i + 1];
					prenume[i + 1] = r1;
					nume[i] = nume[i + 1];
					nume[i + 1] = r2;
					flag = false;
					int r3 = penalizari[i];
					penalizari[i] = penalizari[i + 1];
					penalizari[i + 1] = r3;
				}
			}
			else {
				int k = sortareString(prenume[i], prenume[i + 1]);
				if (k != -1) {
					if (k == 1) {
						string r1 = prenume[i];
						string r2 = nume[i];
						prenume[i] = prenume[i + 1];
						prenume[i + 1] = r1;
						nume[i] = nume[i + 1];
						nume[i + 1] = r2;
						flag = false;
					}
				}
				else {
					if (sortareString(nume[i], nume[i + 1]) == 1) {
						string r1 = prenume[i];
						string r2 = nume[i];
						prenume[i] = prenume[i + 1];
						prenume[i + 1] = r1;
						nume[i] = nume[i + 1];
						nume[i + 1] = r2;
						flag = false;
					}
				}
			}
		}
	} while (flag == false);
}

void rezolvarePart2Pb3(Bilet x[], int n, string prenume[], string nume[], int penalizari[], int& d) {
	d = 0;
	for (int i = 0; i < n; i++) {
		if (!x[i].apare(prenume, nume, n, i)) {
			prenume[d] = x[i].prenume;
			nume[d] = x[i].nume;
			penalizari[d] = x[i].penalizari(x, n);
			d++;
		}
	}
}

void afisarePart2Pb3(string prenume[], string nume[], int penalizari[], int d) {
	cout << "Persoana cu cele mai multe penalizari in ordine alfabetica este :" << endl;
	cout << prenume[0] << " " << nume[0] << endl;
	cout << endl << "Lista ordonata dupa cerinta este :" << endl;
	for (int i = 0; i < d; i++) {
		cout << prenume[i] << " " << nume[i] << " " << penalizari[i] << endl;
	}
}

// Problema 4

void citirePb4(Elev2 x[], int& n) {
	ifstream f("elevi2.txt");
	f >> n;

	for (int i = 0; i < n; i++) {
		f >> x[i].nume;
		f >> x[i].prenume;
		f >> x[i].media1;
		f >> x[i].media2;
		f >> x[i].media3;
	}
}

void sortarePart2Pb4(string prenume[], string nume[], double medii[], int n) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < n - 1; i++) {
			if (medii[i] != medii[i + 1]) {
				if (medii[i] < medii[i + 1]) {
					string r1 = prenume[i];
					string r2 = nume[i];
					prenume[i] = prenume[i + 1];
					prenume[i + 1] = r1;
					nume[i] = nume[i + 1];
					nume[i + 1] = r2;
					flag = false;
					double r3 = medii[i];
					medii[i] = medii[i + 1];
					medii[i + 1] = r3;
				}
			}
			else {
				int k = sortareString(prenume[i], prenume[i + 1]);
				if (k != -1) {
					if (k == 1) {
						string r1 = prenume[i];
						string r2 = nume[i];
						prenume[i] = prenume[i + 1];
						prenume[i + 1] = r1;
						nume[i] = nume[i + 1];
						nume[i + 1] = r2;
						flag = false;
					}
				}
				else {
					if (sortareString(nume[i], nume[i + 1]) == 1) {
						string r1 = prenume[i];
						string r2 = nume[i];
						prenume[i] = prenume[i + 1];
						prenume[i + 1] = r1;
						nume[i] = nume[i + 1];
						nume[i + 1] = r2;
						flag = false;
					}
				}
			}
		}
	} while (flag == false);
}

double mediaClasei(Elev2 x[], int n) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		s += x[i].medie();
	}
	return (double)s / n;
}

void rezolvarePb4(Elev2 x[], int n, string nume[], string prenume[], double medii[], int& c, double medie) {
	c = 0;
	for (int i = 0; i < n; i++) {
		if (x[i].medie() > medie) {
			c++;
		}
		nume[i] = x[i].nume;
		prenume[i] = x[i].prenume;
		medii[i] = x[i].medie();
	}
	sortarePart2Pb4(prenume, nume, medii, n);
}

void afisarePb4(Elev2 x[], int n, string nume[], string prenume[], double medii[], int nr, double medie) {
	cout << "Numarul de elevi cu media mai mare decat cea a clasei este " << nr << "." << endl;
	cout << endl << "Media clasei : " << medie << "." << endl;
	cout << "(Media elevilor a fost rotunjita pentru afisare)" << endl;
	for (int i = 0; i < n; i++) {
		cout << nume[i] << " " << prenume[i] << " " << round(medii[i]) << endl;
	}
}

// Problema 5

void citirePb5(Uniforma x[], int& n, int& p) {
	ifstream f("uniforme.txt");
	f >> n, f >> p;
	
	for (int i = 0; i < n; i++) {
		f >> x[i].nr;
		f >> x[i].tip;
	}
}

int nrElevi(Uniforma x[], int n, int j) {
	int s = 0;
	for (int i = 0; i < n; i++) {
		if (x[i].tip == j) {
			s += x[i].nr;
		}
	}
	return s;
}

void rezolvarePb5(Uniforma x[], int n, int p, int nr[], int indice[]) {
	for (int i = 0; i < p; i++) {
		indice[i] = i + 1;
		nr[i] = nrElevi(x, n, i + 1);
	}
}

void sortarePb5(int nr[], int indice[], int p) {
	bool flag = true;
	do {
		flag = true;
		for (int i = 0; i < p - 1; i++) {
			if (nr[i] < nr[i + 1]) {
				int r1 = nr[i];
				int r2 = indice[i];
				nr[i] = nr[i + 1];
				nr[i + 1] = r1;
				indice[i] = indice[i + 1];
				indice[i + 1] = r2;
				flag = false;
			}
		}
	} while (flag == false);
}

void afisarePb5(int indice[], int p) {
	cout << "Indicii tipurilor de uniforme in ordinea numarului de elevi care le poarta sunt :" << endl;
	for (int i = 0; i < p; i++) {
		cout << indice[i] << " ";
	}
}





