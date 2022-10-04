#include "CTable.h"
#include <iostream>
using namespace std;
const string sDeafultName = "nazwa";
const int iDeafultSize = 5;
CTable::CTable() {
	sName = sDeafultName;
	iSize = iDeafultSize;
	piTable = new int[iSize];
	cout << "bezp: " << sName << endl;
	//Zapisywanie do Tablicy liczb - funkcja testowa
	vNumbersInTable();
}

CTable::CTable(string sName1, int iSize1) {
	sName = sName1;
	iSize = iSize1;
	piTable = new int[iSize];
	cout << "paramter: " << sName << endl;
	//Zapisywanie do Tablicy liczb - funkcja testowa
	vNumbersInTable();
}

CTable::CTable(CTable& pcOther) {
	sName = pcOther.sName + "_copy";
	iSize = pcOther.iSize;
	piTable = new int[iSize];
	for (int ii = 0; ii < iSize; ii++) {
		piTable[ii] = pcOther.piTable[ii];
	}
	cout << "kopiuj: " << sName << endl;
}

/*CTable::~CTable() {
	cout << "usuwam: " << sName << endl;
	delete[] piTable;
}*/

void CTable::vNumbersInTable(){
	for (int ii = 0; ii < iSize; ii++) {
		piTable[ii] = ii;
	}
}

void CTable::vPrint() {
	for (int ii = 0; ii < iSize; ii++) {
		cout << piTable[ii] << " ";
	}
	cout << endl;
}

void CTable::vSetName(string sNewName) {
	cout << "Nazwa " << sName << " zostala zmieniona na " << sNewName << endl;
	sName = sNewName;
}

bool CTable::bSetNewSize(int iNewSize) {
	if (iNewSize >= 0) {
		int* piTableNew = new int[iNewSize];
		for (int ii = 0; ii < iNewSize; ii++) {
			if (ii < iSize) {
				piTableNew[ii] = piTable[ii];
			}
			//Testowe wypelnienie wartosci, ujemne by bylo widac "nowe" dopisane wartosci
			else {
				piTableNew[ii] = ii * -1;
			}
		}
		cout << "Zostala zmieniona dlugosc tablicy na " << iNewSize << " w " << sName << endl;
		iSize = iNewSize;
		piTable = piTableNew;
		return true;
	}
	else {
		cout << "Nie zostala zmieniona dlugosc tablicy na " << iNewSize << " w " << sName << endl;
		return false;
	}
}

CTable* CTable::pcClone() {
	CTable* pcCloned = new CTable(sName, iSize);
	//Teoretycznie beda takie same wartosci przy tworzeniu bo nie modyfiukjemy 
	//tablicy, ale aby bylo idealnie, powinnismy takze skopiowac wartosci z tablicy
	for (int ii = 0; ii < iSize; ii++) {
		(*pcCloned).piTable[ii] = piTable[ii];
	}
	return pcCloned;
}



//LISTA 2:
void CTable::operator=(CTable& pcOther) {
	piTable = pcOther.piTable;
	iSize = pcOther.iSize;
};

//zadanie 3a
/*void CTable::operator=(CTable& pcOther) {
	iSize = pcOther.iSize;
	sName = pcOther.sName;
	delete[] piTable;
	piTable = new int[iSize];
	for (int ii = 0; ii < iSize; ii++) {
		piTable[ii] = pcOther.piTable[ii];
	}
}*/

void CTable::vShow() {
	cout << sName << ": " << iSize << endl;
	vPrint();
}

void CTable::vSetValueAt(int iOffSet, int iNewValue) {
	piTable[iOffSet] = iNewValue;
}

CTable* CTable::operator+(CTable& pcOther) {
	CTable* cTab = new CTable(*this);
	int* piSumTab = new int[iSize + pcOther.iSize];
	for (int ii = 0; ii < iSize + pcOther.iSize; ii++) {
		if (ii < iSize) {
			piSumTab[ii] = piTable[ii];
		}
		else {
			piSumTab[ii] = pcOther.piTable[ii - iSize];
		}
	}
	for (int ii = 0; ii < iSize + pcOther.iSize; ii++) {
		cout << piSumTab[ii] << " ";
	}
	delete[](*cTab).piTable;
	(*cTab).iSize = iSize + pcOther.iSize;
	(*cTab).piTable = piSumTab;
	cout << endl;
	return cTab;
}
