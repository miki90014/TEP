#ifndef NODE_H
#define NODE_H
#include <vector>
using namespace std;
class CNodeStatic {
private:
	vector<CNodeStatic> vChildren;
	CNodeStatic* pcParentNode;
	int iVal;
public:
	CNodeStatic();
	~CNodeStatic();
	void vSetValue(int iNewVal);
	void vSetParent(CNodeStatic* pcParent);
	int iGetChildrenNumber();
	void vAddNewChild();
	CNodeStatic* pcGetParent();
	vector<CNodeStatic>* vGetvChildren();
	bool operator==(CNodeStatic cNode);
	CNodeStatic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
	void vPrintUp();
};
#endif