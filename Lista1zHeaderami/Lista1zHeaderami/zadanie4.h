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
	~CTable();
	void vNumbersInTable();
	void vShowNumbersInTable();
	void vSetName(string sNewName);
	bool bSetNewSize(int iNewSize);
	CTable* pcClone();
};
void vModTabP(CTable* pcTab, int iNewSize);
void vModTabC(CTable cTab, int iNewSize);
#endif
