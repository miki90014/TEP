#ifndef NODEDYN_H
#define NODEDYN_H
#include <vector>
using namespace std;
class CNodeDynamic
{
private:
	vector<CNodeDynamic*> vChildren;
	CNodeDynamic* pcParentNode;
	int iVal;
public:
	CNodeDynamic();
	~CNodeDynamic();
	void vSetValue(int iNewVal);
	int iGetChildrenNumber();
	int iGetValue();
	void vAddNewChild();
	void vSetParent(CNodeDynamic* pcParent);
	vector<CNodeDynamic*>* vGetvChildren();
	CNodeDynamic* pcGetParentNode();
	CNodeDynamic* pcGetChild(int iChildOffset);
	void vPrint();
	void vPrintAllBelow();
};
#endif