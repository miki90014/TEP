#include "zadanie1.h"
#include "zadanie2_3.h"
#include "zadanie4.h"
#include <iostream>
#include<string>  
using namespace std;

int main() {
	vExercise(1);
	vAllocTableAdd5(10);
	
	vExercise(2);
	int** piTab;
	bAllocTable2Dim(&piTab, 2, 5);

	vExercise(3);
	bDellocTable2Dim(&piTab, 2, 5);
	cout << endl;

	vExercise(4);
	CTable* pcTab;
	pcTab = new CTable();
	(*pcTab).bSetNewSize(20);
	(*pcTab).vShowNumbersInTable();

	CTable* pcTab2;
	pcTab2 = new CTable("nazwa", 20);
	(*pcTab2).~CTable();

	CTable* pcTabCopy;
	pcTabCopy = new CTable(*pcTab);
	(*pcTab).~CTable();
	CTable* pcTabCopyClone;
	pcTabCopyClone = (*pcTabCopy).pcClone();
	(*pcTabCopy).~CTable();
	(*pcTabCopyClone).vSetName("Klon");

	cout << endl << endl;
	(*pcTabCopyClone).vShowNumbersInTable();
	vModTabP(pcTabCopyClone, 10);
	(*pcTabCopyClone).vShowNumbersInTable();
	cout << endl;
	vModTabC(*pcTabCopyClone, 4);	//niemodyfikuje tablicy a tworzy nowa klase "kopie"
	(*pcTabCopyClone).~CTable();
	cout << endl << endl;

	vExercise(4);
	cout << "Podpunkt ostatni" << endl;
	int iSizeArray = 4;
	CTable** pcArrayCTable;
	pcArrayCTable = new CTable*[iSizeArray];
	string sTemp;
	for (int ii = 0; ii < iSizeArray; ii++) {
		sTemp = "name_" + to_string(ii);
		pcArrayCTable[ii] = new CTable(sTemp, ii);
	}
	for (int ii = 0; ii < iSizeArray; ii++) {
		(*pcArrayCTable[ii]).~CTable();
	}
	delete[] pcArrayCTable;
	//Tworzy cztery bezparametrowe obiekty;
	//pcArrayCTable = new CTable[iSizeArray];


	return 0;

}