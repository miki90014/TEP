//#include "cNodeDynamic.h"
//#include "cTreeDynamic.h"
#include <iostream>
using namespace std;
/*template< typename T >
CNodeDynamic<T>::CNodeDynamic() {
	tVal = NULL;
	pcParentNode = NULL;
}

template< typename T >
CNodeDynamic<T>::~CNodeDynamic() {
	for (int ii = 0; ii < vChildren.size(); ii++) {
		delete vChildren[ii];
	}
}

template< typename T >
void CNodeDynamic<T>::vSetValue(T tNewVal) {
	tVal = tNewVal;
}

template< typename T >
int CNodeDynamic<T>::iGetChildrenNumber() {
	return(vChildren.size());
}

template< typename T >
T CNodeDynamic<T>::tGetValue()
{
	return tVal;
}

template< typename T >
void CNodeDynamic<T>::vSetParent(CNodeDynamic* pcParent) {
	pcParentNode = pcParent;
}

template< typename T >
vector<CNodeDynamic<T>*>* CNodeDynamic<T>::vGetvChildren()
{
	return &vChildren;
}

template< typename T >
CNodeDynamic<T>* CNodeDynamic<T>::pcGetParentNode()
{
	return pcParentNode;
}

template< typename T >
void CNodeDynamic<T>::vAddNewChild() {
	CNodeDynamic* temp = new CNodeDynamic();
	vChildren.push_back(temp);
	(*vChildren.back()).vSetParent(this);
}

template< typename T >
void CNodeDynamic<T>::vPrint() {
	cout << tVal << endl;
}

template< typename T >
void CNodeDynamic<T>::vPrintAllBelow() {
	vPrint();
	for (int ii = 0; ii < vChildren.size(); ii++) {
		(*vChildren[ii]).vPrintAllBelow();

	}
}

template< typename T >
CNodeDynamic<T>* CNodeDynamic<T>::pcGetChild(int iChildOffset) {
	if (iChildOffset > vChildren.size() - 1 || iChildOffset < 0) {
		cout << "Bledny offset" << endl;
		return NULL;
	}
	return vChildren[iChildOffset];
}*/