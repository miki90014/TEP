#include "treeDynamic.h"
#include "nodeDynamic.h"
#include <iostream>
using namespace std;
CTreeDynamic::CTreeDynamic() {
	CNodeDynamic* temp;
	temp = new CNodeDynamic();
	pcRoot = temp;
}
CTreeDynamic::~CTreeDynamic() {
	(*pcRoot).~CNodeDynamic();
}
CNodeDynamic* CTreeDynamic::pcGetRoot() {
	return(pcRoot);
}
void CTreeDynamic::vPrintTree() {
	(*pcRoot).vPrintAllBelow();
}


bool bMoveSubtree(CNodeDynamic* pcParentNode, CNodeDynamic* pcNewChildNode)
{
	if (pcNewChildNode->pcGetParentNode() != NULL) {
		for (int ii = 0; ii < (*pcNewChildNode->pcGetParentNode()->vGetvChildren()).size(); ii++) {
			if ((*pcNewChildNode->pcGetParentNode()->vGetvChildren())[ii] == pcNewChildNode) {
				for (int ij = ii; ij < (*pcNewChildNode->pcGetParentNode()->vGetvChildren()).size() - 1; ij++) {
					(*pcNewChildNode->pcGetParentNode()->vGetvChildren())[ij] = (*pcNewChildNode->pcGetParentNode()->vGetvChildren())[ij + 1];
				}
				(*pcNewChildNode->pcGetParentNode()->vGetvChildren()).pop_back();
			}
		}
	}
	pcNewChildNode->vSetParent(pcParentNode);
	(*pcParentNode->vGetvChildren()).push_back(pcNewChildNode);
	return true;
}
