#ifndef CTABLE_H
#define CTABLE_H
#include <iostream>
using namespace std;

class CTable {
private:
	string sName;
	int iSize;
	int* piTable;

public:
	CTable();
	CTable(string sName1, int iSize1);
	CTable(CTable& pcOther);
	//~CTable();
	void vSetValueAt(int iOffSet, int iNewValue);
	void vPrint();
	void vSetName(string sNewName);
	void vShow();
	void vNumbersInTable();
	bool bSetNewSize(int iNewSize);
	CTable* pcClone();

	void operator=(CTable& pcOther);
	CTable* operator+(CTable& pcOther);

};
#endif