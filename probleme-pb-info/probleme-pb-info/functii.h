#include "structuri.h"

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