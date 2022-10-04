#include <iostream>
#include "treeStatic.h"
#include "nodeStatic.h"
using namespace std;
CTreeStatic::CTreeStatic() {
	cRoot = CNodeStatic();
}
CNodeStatic* CTreeStatic::pcGetRoot() {
	return &cRoot;
}
void CTreeStatic::vPrintTree() {
	cRoot.vPrintAllBelow();
}
CTreeStatic::~CTreeStatic() {
	cRoot.~CNodeStatic();
}

bool bMoveSubtree(CNodeStatic* pcParentNode, CNodeStatic* pcNewChildNode)
{
	(*pcParentNode->vGetvChildren()).push_back(*pcNewChildNode);
	if (pcNewChildNode->pcGetParent() != NULL) {
		for (int ii = 0; ii < (*pcNewChildNode->pcGetParent()->vGetvChildren()).size(); ii++) {
			if ((*pcNewChildNode->pcGetParent()->vGetvChildren())[ii] == (*pcNewChildNode)) {
				for (int ij = ii; ij < (*pcNewChildNode->pcGetParent()->vGetvChildren()).size() - 1; ij++) {
					(*pcNewChildNode->pcGetParent()->vGetvChildren())[ij] = (*pcNewChildNode->pcGetParent()->vGetvChildren())[ij + 1];
				}
			}
			(*pcNewChildNode->pcGetParent()->vGetvChildren()).pop_back();
		}
	}
	(*pcNewChildNode).vSetParent(pcParentNode);
	return true;
}
