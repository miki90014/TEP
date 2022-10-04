//#pragma once
/*#ifndef HEADER_H
#define HEADER_H*/


void vExercise(int);
void vAllocTableAdd5(int);
bool bAllocTable2Dim(int*[], int, int);
bool bDellocTable2Dim(int*[], int, int);


class CTable {
private:
	string sName;
	int iSize;
	int* piTable;

	string sDeafultName;
	int iDeafultSize;

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

void vModTabP(CTable*, int);
void vModTabC(CTable, int);


//#endif