#include <iostream>

using namespace std;

//zadanie 1
void v_alloc_table_add_5(int iSize) {
	//dynamicznie alokuje jednowymiarow¹ tablicê
	if (iSize >= 0) {

		int* pi_one_dimensional_table;
		pi_one_dimensional_table = new int[iSize];
		for (int ii = 0; ii < iSize; ii++) {
			pi_one_dimensional_table[ii] = ii + 5;
		}
		for (int ii = 0; ii < iSize; ii++) {
			cout << pi_one_dimensional_table[ii] << " " << pi_one_dimensional_table << endl;
		}

		delete[] pi_one_dimensional_table;
		cout << "One dimensional array has been deleted." << endl;
		cout << endl;
	}
	else {
		cout << "Wrong array size" << endl << endl;
	}

}

//zadanie 2
bool b_alloc_table_2_dim(int** piTable, int iSizeX, int iSizeY) {
	//piTable = new int* [iSizeX];
	for (int ii = 0; ii < iSizeX; ii++) {
		piTable[ii] = new int[iSizeY];
	}

	return true;

}

//zadanie 3
bool b_dealloc_table_2_dim(int**piTable, int iSizeX, int iSizeY) {
	for (int ii = 0; ii < iSizeX; ii++) {
		delete[] piTable[ii];
	}
	delete[] piTable;
	return true;
}

class CTable {
private:
	string sName;
	int iTableLen;
	int* pi_one_dimensional_table;

public:
	CTable() {
		sName = "deafult name";
		iTableLen = 5;
		cout << "bezp: " << sName << endl;
		pi_one_dimensional_table = new int[iTableLen];

	}

	CTable(string sName1, int iTableLen1) {
		sName = sName1;
		iTableLen = iTableLen1;
		cout << "parametr: " << sName << endl;
		pi_one_dimensional_table = new int[iTableLen];
	}

	void vSetName(string sName1) {
		sName = sName1;
	}

	bool bSetNewSize(int iTableLen1) {
		int* pi_one_dimensional_table_new;
		pi_one_dimensional_table_new = new int[iTableLen1];

		for (int ii = 0; ii < iTableLen1; ii++) {
			if (ii < iTableLen) {
				pi_one_dimensional_table_new[ii] = pi_one_dimensional_table[ii];
			}
		}
		delete[] pi_one_dimensional_table;
		pi_one_dimensional_table = pi_one_dimensional_table_new;
		cout << "Changed array from " << iTableLen << " size to " << iTableLen1 << " size." << endl;
		iTableLen = iTableLen1;

		return true;
	}

	void vTest() {
		cout << sName << " " << iTableLen << " " << endl;
	}

	CTable* pcClone(CTable const &pcOther) {
		iTableLen = pcOther.iTableLen;
		pi_one_dimensional_table = new int[iTableLen];
		sName = pcOther.sName+ "_copy";
		cout << "created copy of " << sName<<endl;
	}

	~CTable() {
		delete[] pi_one_dimensional_table;
		cout << "Destructor called for CTable " <<sName<<"."<<endl<<endl;
	}

};

int main() {
	//zadanie 1
	v_alloc_table_add_5(7);
	v_alloc_table_add_5(3);
	v_alloc_table_add_5(-2);
	v_alloc_table_add_5(0);
	//zadanie 2
	int** piT;
	b_alloc_table_2_dim(piT, 3, 5);

	//sposob pierwszy - 2D Pointer
	/*
	int* board[4];
	for (int i = 0; i < 4; i++) {
		board[i] = new int[10];
	}
	*/

	//sposob drugi - 2D Pointer
	/*
	int **board;
	board = new int*[4];
	for(int i = 0; i < 4; i++){
		board[i] = new int[10];
	 }
	 */
	



	//zadanie 3
	b_dealloc_table_2_dim(piT, 2, 4);
	//zadanie 4
	//konstruktor bezparametorwy
	CTable c_static_object;
	c_static_object.vTest();
	c_static_object.~CTable();
	CTable* c_dynamic_object0;
	c_dynamic_object0 = new CTable();
	(*c_dynamic_object0).~CTable();
	//konstruktor parametrowy
	CTable* c_dynamic_object;
	c_dynamic_object = new CTable("fantastic name", 4);
	(*c_dynamic_object).vTest();
	(*c_dynamic_object).bSetNewSize(10);
	(*c_dynamic_object).vSetName("changed name");
	(*c_dynamic_object).vTest();
	//konstruktor kopiuj¹cy
	CTable* pc_dynamic_obj_copy;
	pc_dynamic_obj_copy = new CTable(*c_dynamic_object);
	(*pc_dynamic_obj_copy).vTest();
	(*c_dynamic_object).~CTable();
	
	//CTable* pc_dynamic_obj_copy_by_method;
	//(*pc_dynamic_obj_copy_by_method).pcClone(*pc_dynamic_obj_copy);


	return 0;
}