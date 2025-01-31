//Celem zadania jest przećwiczenie podstawowych algorytmów STL. Proszę stworzyć klasę reprezentującą tablicę danych, którą można sortować na różne sposoby.

//Zadanie należy wykonać bez żadnych tradycyjnych pętli (nawet w print), lecz z użyciem algorytmów STL. Użycie w kodzie pętli (for, while, do-while) skutkuje niezaliczeniem zadania.

//Tips:
//- wypisanie równej liczby znaków: std::cout << std::setw(liczba) -- nagłówek iomanip
//- może się przydać namespace std::placeholders
//- można korzystać z dokumentacji na stronie https://en.cppreference.com/w/ (tylko dokumentacja, bez tutoriali!)


#include "Sum.h"
#include "Data.h"
#include "Table.h"
#include <iostream>

bool greaterSum(const Data& d1, const Data& d2){
	return sumData(d1).value() < sumData(d2).value();
}

int main(){
	const Data day1("Monday", {1.5, 2, -3.2});
	day1.print();

	Sum suma = sumData(day1);
	std::cout << "suma z poniedzialku: " << suma.value() << std::endl;
	suma(2); // to pokazuje co robi Sum
	std::cout << "suma z poniedzialku + 2: " << suma.value() << std::endl;

	std::cout << "   ============= Table =============" << std::endl;
 	Table table;
	table += day1;
	table += Data("Friday", {3, 2.5, 13, 2});
	table += Data("Sunday", {1, -12.5, 1.3, 1.5, 12.3});
	std::cout << "min row length: " << table.minRow << std::endl;

	table.print();
	std::cout << "======= sortowanie po kolumnie 3 =======" << std::endl;
	table.sort(2).print(); 

	std::cout << "======= sortowanie po kolumnie 2 =======" << std::endl;
	table.sort(1).print(); 

	table.sort(3); // uwaga, tutaj niedozwolony indeks 
	std::cout << "========= sortowanie po sumach =========" << std::endl;
	table.sortBy(greaterSum).print(); // sortowanie po zsumowanych kolumnach, rosnąco
}


/* //OUTPUT:
Monday:    1.5     2  -3.2
suma z poniedzialku: 0.3
suma z poniedzialku + 2: 2.3
   ============= Table =============
min row length: 3
Monday:    1.5     2  -3.2
Friday:      3   2.5    13     2
Sunday:      1 -12.5   1.3   1.5  12.3

======= sortowanie po kolumnie 3 =======
Monday:    1.5     2  -3.2
Sunday:      1 -12.5   1.3   1.5  12.3
Friday:      3   2.5    13     2

======= sortowanie po kolumnie 2 =======
Sunday:      1 -12.5   1.3   1.5  12.3
Monday:    1.5     2  -3.2
Friday:      3   2.5    13     2

Indeks 3 nieprawidlowy! 
========= sortowanie po sumach =========
Monday:    1.5     2  -3.2
Sunday:      1 -12.5   1.3   1.5  12.3
Friday:      3   2.5    13     2

*/
