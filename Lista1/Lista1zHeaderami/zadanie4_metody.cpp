#include <iostream>
#include "zadanie4_metody.h"
using namespace std;

void vModTabP(CTable *pcTab, int iNewSize) {
	(*pcTab).bSetNewSize(iNewSize);
}

void vModTabC(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
	//Tylko tutaj mozemy sie dostac do zmienionej tablicy
	//cTab.vShowNumbersInTable();
}