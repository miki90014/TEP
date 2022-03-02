/*#include "cTreeDynamic.h"
#include "cNodeDynamic.h"
#include <iostream>
#include <queue>
using namespace std;

template< typename T >
CTreeDynamic<T>::CTreeDynamic() {
	pcRoot = new CNodeDynamic();
}

template< typename T >
CTreeDynamic<T>::~CTreeDynamic() {
	(*pcRoot).~CNodeDynamic();
}


template<typename T>
CNodeDynamic<T>* CTreeDynamic<T>::pcGetRoot() {
	return pcRoot;
}


template< typename T >
void CTreeDynamic<T>::vPrintTree() {
	(*pcRoot).vPrintAllBelow();
}

template< typename T >
bool bMoveSubtree(CNodeDynamic<T>* pcParentNode, CNodeDynamic<T>* pcNewChildNode)
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
}*/