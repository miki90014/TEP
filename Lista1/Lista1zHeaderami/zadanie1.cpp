#include "zadanie1.h"
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
	else {
		cout << "Nieprawidlowa wartosc" << endl << endl;
	}
}