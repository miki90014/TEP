#include <iostream>
using namespace std;
template <typename T> class CTable {
private:
	int iSize;
	T* ptTable;
public:
	CTable() {
		iSize = 0;
		ptTable = NULL;
	}
	
	~CTable(){
		if (ptTable != NULL) {
			delete[] ptTable;
		}
	}

	bool bSetLength(int iNewSize) {
		if (i >=0) {
			iSize = iNewSize;
			return true;
		}
		//poprawiæ
		return false;
	}

	T* ptGetElement(int iOffset) {
		if (iOffset >= iSize || iOffset<0) {
			cout << "Niepoprawny offset" << endl;
			return NULL;
		}
		return *ptTable[iOffset];
	}

	bool bSetElement(int iOffset, T tValue) {
		if (iOffset >= iSize || iOffset < 0) {
			cout << "Niepoprawny offset" << endl;
			return false;
		}
		else {
			ptTable[iOffset] = tValue;
			return true;
		}
	}
};