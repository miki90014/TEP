#include <iostream>
#include "nodeStatic.h"
#include "treeStatic.h"
#include "nodeDynamic.h"
#include "treeDynamic.h"
using namespace std;
int main() {
	//zadanie 2
	CNodeStatic cRoot;
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
	//zadanie 3
	cRoot.pcGetChild(0)->pcGetChild(1)->vPrintUp();
	cout << endl;
	cRoot.pcGetChild(1)->pcGetChild(1)->vPrintUp();
	//zadanie 4
	CNodeDynamic p;
	p.vSetValue(1);
	p.vAddNewChild();
	p.vAddNewChild();
	p.pcGetChild(0)->vAddNewChild();
	p.pcGetChild(0)->pcGetChild(0)->vSetValue(-1);
	p.pcGetChild(0)->vSetValue(2);
	p.vPrintAllBelow();
	cout << endl << endl;
	p.pcGetChild(0)->~CNodeDynamic();
	p.vPrintAllBelow();
	cout << endl << endl;
	CTreeDynamic cRootDyn;
	cRootDyn.pcGetRoot()->vAddNewChild();
	cRootDyn.pcGetRoot()->vAddNewChild();
	cRootDyn.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	cRootDyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootDyn.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootDyn.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(-1); 
	cRootDyn.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(-2);
	cRootDyn.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	cRootDyn.vPrintTree();
	CTreeStatic cRootStat;
	cRootStat.pcGetRoot()->vAddNewChild();
	cRootStat.pcGetRoot()->vAddNewChild();
	cRootStat.pcGetRoot()->pcGetChild(0)->vSetValue(1);
	cRootStat.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootStat.pcGetRoot()->pcGetChild(0)->vAddNewChild();
	cRootStat.pcGetRoot()->pcGetChild(0)->pcGetChild(0)->vSetValue(-1);
	cRootStat.pcGetRoot()->pcGetChild(0)->pcGetChild(1)->vSetValue(-2);
	cRootStat.pcGetRoot()->pcGetChild(1)->vSetValue(2);
	cout << endl << endl;
	//zadanie 6 - dynamiczne
	CTreeDynamic cRootDyn2;
	cRootDyn2.pcGetRoot()->vSetValue(11);
	cRootDyn2.pcGetRoot()->vAddNewChild();
	cRootDyn2.vPrintTree();
	cout << endl << "Drzewo cRootDyn2 po zmianie" << endl;
	bMoveSubtree(cRootDyn2.pcGetRoot()->pcGetChild(0), cRootDyn.pcGetRoot()->pcGetChild(0));
	cRootDyn2.vPrintTree();
	cout << endl << "Drzewo cRootDyn po zmianie" << endl;
	cRootDyn.vPrintTree();
	//zadanie 6 - statycznie
	cout << "cRootStat2" << endl;
	CTreeStatic cRootStat2;
	cRootStat2.pcGetRoot()->vSetValue(11);
	cRootStat2.pcGetRoot()->vAddNewChild();
	cRootStat2.vPrintTree();
	cout << "cRootStat" << endl;
	cRootStat.vPrintTree();
	cout << endl << "Drzewo cRootStat2 po zmianie" << endl;
	bMoveSubtree(cRootStat2.pcGetRoot()->pcGetChild(0), cRootStat.pcGetRoot()->pcGetChild(0));
	cRootStat2.vPrintTree();
	cout << endl << "Drzewo cRootStat po zmianie" << endl;
	cRootStat.vPrintTree();
	return 0;
}