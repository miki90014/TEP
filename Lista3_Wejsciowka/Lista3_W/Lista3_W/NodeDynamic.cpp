#include "nodeDynamic.h"
#include "treeDynamic.h"
#include <iostream>
using namespace std;
CNodeDynamic::CNodeDynamic() {
	iVal = 0; 
	pcParentNode = NULL;
}
CNodeDynamic::~CNodeDynamic() {
	for (int ii = 0; ii < vChildren.size(); ii++) {
		delete vChildren[ii];
	}

	/*if (pcParentNode != NULL) {
		for (int ii = 0; ii < (*pcParentNode).vChildren.size(); ii++) {
			if ((*pcParentNode).vChildren[ii] == this) {
				(*pcParentNode).vChildren[ii] = NULL;
			}
		}
	}
	delete pcParentNode;*/
	/*if (pcParentNode != NULL) {
		for (int ii = 0; ii < (*pcParentNode).vChildren.size(); ii++){
			if ((*pcParentNode).vChildren[ii] == this) {
				if (vChildren.empty() == false) {
					(*pcParentNode).vChildren[ii] = vChildren.back();
					vChildren.pop_back();
					for (int ij = 0; ij < vChildren.size(); ij++) {
						(*(*pcParentNode).vChildren[ii]).vChildren.push_back(vChildren[ij]);
						(*vChildren[ij]).pcParentNode = (*pcParentNode).vChildren[ii];
					}
					vChildren.clear();
				}
				else {
					for (int ij = ii; ii < (*pcParentNode).vChildren.size() - 1; ij++) {
						(*pcParentNode).vChildren[ij] = (*pcParentNode).vChildren[ij + 1];
					}
					(*pcParentNode).vChildren.pop_back();
				}
			}
		}
	}
	else if (vChildren.empty() == false) {
		for (int ij = 0; ij < vChildren.size() - 1; ij++) {
			(*vChildren.back()).vChildren.push_back(vChildren[ij]);
			(*vChildren[ij]).pcParentNode = vChildren.back();
		}
		(*vChildren.back()).pcParentNode = NULL;
		vChildren.clear();
	}*/
}

void CNodeDynamic::vSetValue(int iNewVal) {
	iVal = iNewVal;
}
int CNodeDynamic::iGetChildrenNumber() {
	return(vChildren.size());
}
int CNodeDynamic::iGetValue()
{
	return iVal;
}
void CNodeDynamic::vSetParent(CNodeDynamic* pcParent) {
	pcParentNode = pcParent;
}
vector<CNodeDynamic*>* CNodeDynamic::vGetvChildren()
{
	return &vChildren;
}
CNodeDynamic* CNodeDynamic::pcGetParentNode()
{
	return pcParentNode;
}
void CNodeDynamic::vAddNewChild() {
	CNodeDynamic* temp = new CNodeDynamic();
	vChildren.push_back(temp);
	(*vChildren.back()).vSetParent(this);
}
void CNodeDynamic::vPrint() {
	cout << iVal << endl;
}
void CNodeDynamic::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < vChildren.size(); ii++) {
		(*vChildren[ii]).vPrintAllBelow();

	}
}
CNodeDynamic* CNodeDynamic::pcGetChild(int iChildOffset) {
	if (iChildOffset > vChildren.size() - 1 || iChildOffset < 0) {
		cout << "Bledny offset" << endl;
		return NULL;
	}
	return vChildren[iChildOffset];
}