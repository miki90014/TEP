#include <iostream>
#include "CMySmartPointer.h"
#include "CTab.h"
using namespace std;
int main() {
	CTable* cTab = new CTable() ;
	CTable* cOther = new CTable();

	CMySmartPointer<CTable> pcSmart = CMySmartPointer<CTable>(cTab);
	
	/*initialize c_tab, c_other*/
	cTab = move(cOther);
	cOther = cTab;
	//c_tab = c_other;
	return 0;
}