#include <iostream>
#include "cNodeDynamic.h"
#include "cTreeDynamic.h"
using namespace std;
int main() {
	//Node
	CNodeDynamic<int> cRoot;
	cRoot.vSetValue(0);
	cRoot.vAddNewChild();
	cRoot.vAddNewChild();
	cRoot.pcGetChild(0)->vSetValue(1);
	cRoot.pcGetChild(1)->vSetValue(2);
	cRoot.pcGetChild(0)->vAddNewChild();
	cRoot.pcGetChild(0)->vAddNewChild();
	cRoot.pcGetChild(0)->pcGetChild(0)->vSetValue(11);
	cRoot.pcGetChild(0)->pcGetChild(1)->vSetValue(12);
	cRoot.pcGetChild(1)->vAddNewChild();
	cRoot.pcGetChild(1)->vAddNewChild();
	cRoot.pcGetChild(1)->pcGetChild(0)->vSetValue(21);
	cRoot.pcGetChild(1)->pcGetChild(1)->vSetValue(22);
	cRoot.vPrintAllBelow();
	cout << endl;
	cRoot.pcGetChild(0)->vPrintAllBelow();
	cout << endl;
	cRoot.pcGetChild(1)->vPrintAllBelow();
	cout << endl;
	cout << endl;
	//Tree
	CTreeDynamic<int> cRootDyn;
	cRootDyn.pcGetRoot()->vAddNewChild();
	cRootDyn.pcGetRoot()->vAddNewChild();
	cRootDyn.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	cRootDyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootDyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootDyn.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(-1);
	cRootDyn.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(-2);
	cRootDyn.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	cRootDyn.vPrintTree();
	cout<<cRootDyn.sGetType();
	CTreeDynamic<string> cRootDyn2;
	cRootDyn2.pcGetRoot()->vAddNewChild();
	cRootDyn2.pcGetRoot()->vAddNewChild();
	cRootDyn2.pcGetRoot()->pcGetChild(0)->vSetValue("ALA");
	cRootDyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootDyn2.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootDyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue("MA");
	cRootDyn2.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue("KOTA");
	cRootDyn2.pcGetRoot()->pcGetChild(1)->vSetValue(".");
	cRootDyn2.vPrintTree();
	cout << cRootDyn2.sGetType();
}