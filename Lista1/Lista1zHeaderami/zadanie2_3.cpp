#include "zadanie2_3.h"
#include <iostream>
using namespace std;

bool bAllocTable2Dim(int*** piTable, int iSizeX, int iSizeY) {
	*piTable = new int*[iSizeX];
	if (iSizeX >= 0 && iSizeY >= 0) {
		for (int ii = 0; ii < iSizeX; ii++) {
			(*piTable)[ii] = new int[iSizeY];
		}
		//Zapisanie offsetu do tablicy i wypisywanie - funkcja testowa
		for (int ii = 0; ii < iSizeX; ii++) {
			for (int ij = 0; ij < iSizeY; ij++) {
				(*piTable)[ii][ij] = ii * ij;
			}
		}
		for (int ii = 0; ii < iSizeX; ii++) {
			for (int ij = 0; ij < iSizeY; ij++) {
				cout << (*piTable)[ii][ij] << " ";
			}
			cout << endl;
		}
		cout << "2D Array of the size " << iSizeX << "x" << iSizeY << " has been allocated." << endl;
		return true;
	}
	else {
		return false;
	}
}

bool bDellocTable2Dim(int*** piTable, int iSizeX, int iSizeY) {
	if (iSizeX >= 0 && iSizeY >= 0) {
		for (int ii = 0; ii < iSizeX; ii++) {
			delete[] (*piTable)[ii];
		}
		delete[] *piTable;
		cout << "2D Array of the size " << iSizeX << "x" << iSizeY << " has been dellocated." << endl;
		return true;
	}
	else {
		return false;
	}
}
