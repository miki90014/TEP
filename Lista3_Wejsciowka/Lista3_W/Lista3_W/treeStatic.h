#ifndef TREE_H
#define TREE_H
#include "nodeStatic.h"
using namespace std;
class CTreeStatic {
private:
	CNodeStatic cRoot;
public:
	CTreeStatic();
	~CTreeStatic();
	CNodeStatic* pcGetRoot();
	void vPrintTree();
};
bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode);
#endif