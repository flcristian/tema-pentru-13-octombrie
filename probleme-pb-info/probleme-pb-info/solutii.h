#include "functii.h"

// Problema 1
// Dându-se N intervale[a, b], calculați numărul 
// maxim de astfel de intervale care se 
// intersectează în cel puțin un punct.

void solutiepb1() {
	int n;
	Interval x[100];
	citirePb1(x, n);
	cout << "Numarul maxim de intervale care se intersecteaza in minim un punct este " << rezolvarePb1(x, n) << "." << endl;
}

// Problema 2
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

// Problema 3
// Se dau două numere n p și o listă de n elemente 
// cu urcările în autobuz a mai multor persoane a 
// căror structura este prenume nume bilet_platit, 
// fiecare intrare fiind plasată pe câte o linie.
// 
// Câmpurile prenume și nume sunt șiruri de caractere, 
// iar bilet_platit este un număr care poate fi 0 sau 1;
// 0 dacă persoana respectivă nu a plătit biletul sau 1 
// dacă a plătit biletul. Pentru fiecare bilet neplătit 
// se va contoriza o penalizare persoanei.
//
// Se cere :
// a) Prenumele, numele și numărul de penalizări al 
// persoanei care are număr maxim de penalizări. 
// Dacă există mai multe persoane cu număr maxim de 
// penalizări se cere afișarea persoanei care apare 
// prima în ordine alfabetică.
// 
// b) Ordonarea listei de persoane descrescător după 
// numărul de penalizări, la număr de penalizări egale, 
// crescător după prenume, la prenume identice, 
// crescător după nume.

void solutiepb3() {
	int n;
	Bilet x[100];
	citirePb3(x, n);
	int d;
	int penalizari[100];
	string prenume[100], nume[100];
	rezolvarePart2Pb3(x, n, prenume, nume, penalizari, d);
	sortarePart2Pb3(prenume, nume, penalizari, d);
	afisarePart2Pb3(prenume, nume, penalizari, d);
}

// Problema 4
// Se citește de la tastatură numărul n și un număr 
// p cu valoarea 1 sau 2 și apoi n șiruri de tip nume 
// prenume media1 media2 media3 separate prin spații.
//
// Pentru p = 1, se va afișa numărul elevilor care au 
// media generală mai mare sau egală decât media clasei.
// Pentru p = 2, se va afișa pe primul rând media 
// clasei și pe următoarele n rânduri, numele, 
// prenumele și media generală a fiecărui elev, 
// separate printr-un singur spațiu, sortat 
// descrescător după medie; la medii egale se sortează 
// crescător după nume, iar la nume egale crescător 
// după prenume.

void solutiepb4() {
	int n;
	Elev2 x[100];
	citirePb4(x, n);
	double medie = mediaClasei(x, n);
	string nume[100], prenume[100];
	double medii[100];
	int nr;
	rezolvarePb4(x, n, nume, prenume, medii, nr, medie);
	afisarePb4(x, n, nume, prenume, medii, nr, medie);
}

// Problema 5
// La o serbare sunt n grupe de copii care poartă p 
// tipuri de uniforme.Scrieţi un program care să 
// afişeze pe ecran tipurile de uniforme în ordinea 
// descrescătoare a numărului total de copii ce 
// poartă fiecare tip de uniformă. 
// Afişarea se va face pe o singură linie, 
// valoriile fiind separate printr-un spaţiu.

void solutiepb5() {
	int n, p;
	Uniforma x[100];
	citirePb5(x, n, p);
	int nr[100];
	int indice[100];
	rezolvarePb5(x, n, p, nr, indice);
	sortarePb5(nr, indice, p);
	afisarePb5(indice, p);
}

// Problema 6
// Se consideră două evenimente a căror durată
// este exprimată fiecare prin câte trei 
// numere naturale: ore (h), minute (m) şi 
// secunde (s).
// 
// Să se scrie în fișierul de ieșire :
// a) pe primele două linii, duratele în '
// formatul h : m: s
// b) pe următoarele două linii, duratele 
// exprimate în secunde, corespunzătoare 
// fiecărui eveniment, pe rânduri separate;
// c) pe următoarea linie suma obţinută din 
// adunarea duratelor celor două evenimente, 
// exprimată în ore, minute, secunde, în 
// formatul h : m: s.

void solutiepb6() {
	int n;
	Eveniment x[100];
	citirePb6(x, n);
	Eveniment raspuns = durataAdunata(x, n);
	afisarePb6(x, n, raspuns);
}

// Problema 7
// Se citește numărul n și apoi n articole 
// cu structura : prenume nume salariu 
// vârstă funcție număr_de_telefon email.
// Fiecare articol este plasat pe câte o 
// linie, câmpurile sale fiind separate prin 
// câte un spațiu. Câmpurile salariu și vârstă 
// conțin numere naturale, celelalte conțin 
// șiruri de caractere.
//
// Se citește apoi un număr natural p cuprins 
// între 1 și 7 și un caracter c care poate 
// fi + sau - .
//
// Se cere ordonarea celor n articole în 
// funcție de p și c, astfel :
//
// dacă p = 1, ordonarea se face după 
// prenume; dacă p = 2, ordonarea se face 
// după nume; dacă p = 3, ordonarea se face 
// după salariu; dacă p = 4, ordonarea se 
// face după vârstă; dacă p = 5, ordonarea se 
// face după funcție; dacă p = 6, ordonarea 
// se face după număr_de_telefon; dacă p = 7, 
// ordonarea se face după email;
// dacă c are valoarea + , ordonarea va fi 
// crescătoare, iar dacă c are valoarea - , 
// ordonarea va fi descrescătoare;
// dacă două articole au aceeași valoare a 
// câmpului în raport cu care se face 
// sortarea, ordinea lor nu se va modifica.

void solutiepb7() {
	int n;
	Date x[100];
	citirePb7(x, n);

	int p;
	char c;
	cout << "Introduceti p (1-7) : ";
	cin >> p;
	cout << "Introduceti c (+ / -) : ";
	cin >> c;

	switch (p)
	{
	case 1:
		sortarePrenume(x, n);
		break;
	case 2:
		sortareNume(x, n);
		break;
	case 3:
		sortareSalariu(x, n);
		break;
	case 4:
		sortareVarsta(x, n);
		break;
	case 5:
		sortareFunctie(x, n);
		break;
	case 6:
		sortareNumarTelefon(x, n);
		break;
	case 7:
		sortareEmail(x, n);
		break;
	default:
		break;
	}

	switch (c)
	{
	case '+':
		afisarePb7Cresc(x, n);
		break;
	case '-':
		afisarePb7Descresc(x, n);
		break;
	default:
		break;
	}
}