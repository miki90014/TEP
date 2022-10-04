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

	CTable(CTable&& pcOther)noexcept;

	~CTable();
	void vNumbersInTable();
	void vShowNumbersInTable();
	void vSetName(string sNewName);
	bool bSetNewSize(int iNewSize);
	CTable* pcClone();

	CTable operator=(CTable&& pcOther) noexcept;
	CTable operator=(CTable& pcOther);
};
#endif