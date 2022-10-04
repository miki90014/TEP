#ifndef TREEDYN_H
#define TREEDYN_H
#include <vector>
#include "nodeDynamic.h"
using namespace std;
class CTreeDynamic
{
private:
	CNodeDynamic* pcRoot;
public:
	CTreeDynamic();
	~CTreeDynamic();
	CNodeDynamic* pcGetRoot();
	void vPrintTree();
};
bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode);
#endif