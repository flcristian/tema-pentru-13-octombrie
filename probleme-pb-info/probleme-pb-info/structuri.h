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