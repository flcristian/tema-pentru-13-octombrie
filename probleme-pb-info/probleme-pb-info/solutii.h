#include "functii.h"

// Dându-se N intervale[a, b], calculați numărul 
// maxim de astfel de intervale care se 
// intersectează în cel puțin un punct.

void solutiepb1() {
	int n;
	Interval x[100];
	citirePb1(x, n);
	cout << "Numarul maxim de intervale care se intersecteaza in minim un punct este " << rezolvarePb1(x, n) << "." << endl;
}

// Se dau n, reprezentând numărul de elevi apoi, 
// pe câte un rând, datele fiecărui elev : 
// codul(număr natural de maxim 4 cifre), media 
// la informatică(număr natural de la 1 la 10) 
// și numărul de absențe. Definiți un tip 
// structură pentru a putea memora datele unui 
// elev și rezolvați cerințele :
//
// a) memorați datele tuturor elevilor într-un 
// vector de structuri de tipul definit;
// b) afișați numărul de elevi cu media 10
// c) afișați media clasei(se va afișa doar partea 
// întreagă a ei).
// d) afișați primii doi elevi după 
// absențe(elevii cu cele mai multe absențe).
// Dacă sunt mai mulți elevi cu același număr de 
// absențe se afișează în ordine crescătoare 
// a codului. Dacă sunt mai mult de doi elevi 
// număr maxim de absențe se afișează doar doi.

void solutiepb2() {
	int n;
	Elev x[100];
	citirePb2(x, n);
	int c, i1, i2, medie;
	rezolvarePb2(x, n, i1, i2, c, medie);
	cout << "Numarul de elevi cu media 10 este " << c << "." << endl;
	cout << "Media clasei este " << medie << "." << endl;
	cout << "Elevii cu cele mai multe absente : " << endl;
	cout << x[i1].cod << " " << x[i1].medie << " " << x[i1].absente << endl;
	cout << x[i2].cod << " " << x[i2].medie << " " << x[i2].absente << endl;
}