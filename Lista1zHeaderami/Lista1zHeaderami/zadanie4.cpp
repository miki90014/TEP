#include "zadanie4.h"
#include <iostream>
using namespace std;
	const string sDeafultName = "nazwa";
	const int iDeafultSize =5;
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

	CTable::~CTable() {
		cout << "usuwam: " << sName << endl;
		delete[] piTable;
	}

	void CTable::vNumbersInTable() {
		for (int ii = 0; ii < iSize; ii++) {
			piTable[ii] = ii;
		}
	}

	void CTable::vShowNumbersInTable() {
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

	void vModTabP(CTable* pcTab, int iNewSize) {
		(*pcTab).bSetNewSize(iNewSize);
	}

	void vModTabC(CTable cTab, int iNewSize) {
		cTab.bSetNewSize(iNewSize);
		//Tylko tutaj mozemy sie dostac do zmienionej tablicy
		//cTab.vShowNumbersInTable();
	}