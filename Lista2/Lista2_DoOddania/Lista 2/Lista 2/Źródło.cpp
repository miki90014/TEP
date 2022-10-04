#include <iostream>
#include "CTable.h"
using namespace std;
int main() {
	
	//Zadanie 1 i 2
	//Poniewaz operator = zosta³ zdefiniowany jako dwa obiekty majacy ten sam wskaznik,
	//uzywajac destruktora bedziemy dwukrotnie alokowac obiekt
	//dlatego wyrzuca blad, bo usuwamy cos co juz nie istnieje
	CTable cTab0, cTab1;
	cTab0.bSetNewSize(6);
	cTab1.bSetNewSize(4);
	cTab0 = cTab1;
	cTab0.vShow();
	cTab1.vShow();
	cout << endl << endl;

	//Zadanie 3
	//Metoda nie zadziala poprawnie poniewaz obiekty maja ten sam wskaznik
	//modyfikujac jeden obiekt, a zmodyfikujemy dwa
	CTable cTab2, cTab3;
	cTab2.bSetNewSize(6);
	cTab3.bSetNewSize(4);
	cTab2 = cTab3;
	cTab3.vSetValueAt(2, 123);
	cTab2.vPrint();
	cTab3.vPrint();
	cout << endl << endl;

	//Zadanie 3a

	//Zadanie 4
	cTab3.bSetNewSize(10);
	(*(cTab2 + cTab3)).vShow();

}