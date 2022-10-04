#include <iostream>
#include "nodeStatic.h"
using namespace std;
CNodeStatic::CNodeStatic() {
	iVal = 0; 
	pcParentNode = NULL;
}
CNodeStatic::~CNodeStatic() {
}
void CNodeStatic::vSetValue(int iNewVal) {
	iVal = iNewVal;
}
int CNodeStatic::iGetChildrenNumber() { 
	return(vChildren.size()); 
};
void CNodeStatic::vSetParent(CNodeStatic* pcParent) {
	pcParentNode = pcParent;
};
void CNodeStatic::vAddNewChild() {
	vChildren.push_back(CNodeStatic());
	vChildren.back().vSetParent(this);
	
}
CNodeStatic* CNodeStatic::pcGetParent()
{
	return pcParentNode;
}
vector<CNodeStatic>* CNodeStatic::vGetvChildren() {
	return &vChildren;
}
bool CNodeStatic::operator==(CNodeStatic cNode) {
	if (cNode.iVal == this->iVal && (*cNode.vGetvChildren()).size()==(*this->vGetvChildren()).size()) {
		for (int ii = 0; ii < (*cNode.vGetvChildren()).size(); ii++) {
			if (((*cNode.vGetvChildren())[ii] == (*this->vGetvChildren())[ii])==false) {
				return false;
			}
		}
		return true;
	}
	return false;
}
CNodeStatic* CNodeStatic::pcGetChild(int iChildOffset) {
	if (iChildOffset > vChildren.size() || iChildOffset<0) {
		cout << "Bledny offset" << endl;
		return NULL;
	}
	return &vChildren[iChildOffset];
}
void CNodeStatic::vPrint() {
	cout << iVal << endl;
}
void CNodeStatic::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < vChildren.size(); ii++) {
		vChildren[ii].vPrintAllBelow();

	}
}
void CNodeStatic::vPrintUp() {
	vPrint();
	if (pcParentNode != NULL) {
		(*pcParentNode).vPrintUp();
	}
}