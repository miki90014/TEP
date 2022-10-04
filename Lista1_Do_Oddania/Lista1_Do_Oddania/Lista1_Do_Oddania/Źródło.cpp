#include <iostream>
using namespace std;
void vExercise(int iNumber) {
	cout << "Zadanie " << iNumber << endl << endl;
}
void vAllocTableAdd5(int iSize) {
	if (iSize >= 0) {
		int iAdd5 = 5;
		int* pi;
		pi = new int[iSize];
		for (int ii = 0; ii < iSize; ii++) {
			pi[ii] = ii + iAdd5;
		}
		for (int ii = 0; ii < iSize; ii++) {
			cout << pi[ii] << " ";
		}
		cout << endl << endl;
		delete[] pi;
	}
	else{
		cout << "Nieprawidlowa wartosc" << endl << endl;
	}
}

bool bAllocTable2Dim(int *piTable[], int iSizeX, int iSizeY) {
	if (iSizeX >= 0 && iSizeY >= 0) {
		for (int ii = 0; ii < iSizeX; ii++) {
			piTable[ii] = new int[iSizeY];
		}
		//Zapisanie offsetu do tablicy i wypisywanie - funkcja testowa
		/*for (int ii = 0; ii < iSizeX; ii++) {
			for (int ij = 0; ij < iSizeY; ij++) {
				piTable[ii][ij] = ii * ij;
			}
		}
		for (int ii = 0; ii < iSizeX; ii++) {
			for (int ij = 0; ij < iSizeY; ij++) {
				cout << piTable[ii][ij] << " ";
			}
			cout << endl;
		}*/
		cout << "2D Array of the size " << iSizeX << "x" << iSizeY << " has been allocated." << endl;
		return true;
	}
	else {
		return false;
	}
}

bool bDellocTable2Dim(int *piTable[], int iSizeX, int iSizeY) {
	if (iSizeX >= 0 && iSizeY >= 0) {
		for (int ii = 0; ii < iSizeX; ii++) {
			delete[] piTable[ii];
		}
		cout << "2D Array of the size " << iSizeX << "x" << iSizeY << " has been dellocated." << endl;
		return true;
	}
	else {
		return false;
	}
}

class CTable {
private:
	string sName;
	int iSize;
	int* piTable;

	string sDeafultName = "Tablica";
	int iDeafultSize = 5;

public:
	CTable() {
		sName = sDeafultName;
		iSize = iDeafultSize;
		piTable = new int[iSize];
		cout << "bezp: " << sName << endl;
		//Zapisywanie do Tablicy liczb - funkcja testowa
		vNumbersInTable();
	}

	CTable(string sName1, int iSize1) {
		sName = sName1;
		iSize = iSize1;
		piTable = new int[iSize];
		cout << "paramter: " << sName << endl;
		//Zapisywanie do Tablicy liczb - funkcja testowa
		vNumbersInTable();
	}

	CTable(CTable &pcOther) {
		sName = pcOther.sName+"_copy";
		iSize = pcOther.iSize;
		piTable = new int[iSize];
		for (int ii = 0; ii < iSize; ii++) {
			piTable[ii] = pcOther.piTable[ii];
		}
		cout << "kopiuj: " << sName << endl;
	}

	~CTable() {
		cout << "usuwam: " << sName << endl;
		delete[] piTable;
	}

	void vNumbersInTable() {
		for (int ii = 0; ii < iSize; ii++) {
			piTable[ii] = ii;
		}
	}
	
	void vShowNumbersInTable() {
		for (int ii = 0; ii < iSize; ii++) {
			cout << piTable[ii] << " ";
		}
		cout << endl;
	}

	void vSetName(string sNewName) {
		cout << "Nazwa " << sName << " zostala zmieniona na "<< sNewName << endl;
		sName = sNewName;
	}

	bool bSetNewSize(int iNewSize) {
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

	CTable* pcClone() {
		CTable* pcCloned = new CTable(sName, iSize);
		//Teoretycznie beda takie same wartosci przy tworzeniu bo nie modyfiukjemy 
		//tablicy, ale aby bylo idealnie, powinnismy takze skopiowac wartosci z tablicy
		for (int ii = 0; ii < iSize; ii++) {
			(*pcCloned).piTable[ii] = piTable[ii];
		}
		return pcCloned;
	}


};

void vModTabP(CTable* pcTab, int iNewSize) {
	(*pcTab).bSetNewSize(iNewSize);
}

void vModTabC(CTable cTab, int iNewSize) {
	cTab.bSetNewSize(iNewSize);
	//Tylko tutaj mozemy sie dostac do zmienionej tablicy
	//cTab.vShowNumbersInTable();
}


int main() {
	vExercise(1);
	vAllocTableAdd5(10);


	vExercise(2);
	int** piTab;
	piTab = new int*[2];
	bAllocTable2Dim(piTab, 2, 5);

	int* piTab2[3];
	bAllocTable2Dim(piTab2, 3, 5);
	cout << endl;


	vExercise(3);
	bDellocTable2Dim(piTab, 2, 5);
	bDellocTable2Dim(piTab2, 3, 5);
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


	return 0;
}