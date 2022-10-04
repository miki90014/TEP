#ifndef SPOINTER_H
#define SPOINTER_H
#include <iostream>
#include "CRefCounter.h"
using namespace std;
template <typename T>
class CMySmartPointer {
private:
	T* pcPointer;
	CRefCounter<T>* pcCounter;
public:
	CMySmartPointer(T* pcPointerNew);
	CMySmartPointer(const CMySmartPointer<T>& pcOther);
	~CMySmartPointer();
	CRefCounter<T>* pcGetCounter() { return pcCounter; };
	T& operator*();
	T* operator->();
	void operator=(CMySmartPointer<T>& cPointer);
};

template <typename T>
CMySmartPointer<T>::CMySmartPointer(T* pcPointerNew) {
	pcPointer = pcPointerNew;
	pcCounter = new CRefCounter<T>();
	pcCounter->iAdd();
	pcCounter->vAddPointer(this);
}

template <typename T>
CMySmartPointer<T>::CMySmartPointer(const CMySmartPointer<T>& pcOther) {
	pcPointer = pcOther.pcPointer;
	pcCounter = pcOther.pcCounter;
	pcCounter->iAdd();
	pcCounter->vAddPointer(this);

}


template <typename T>
CMySmartPointer<T>::~CMySmartPointer() {
	pcCounter->vRemovePointer(this);
	if (pcCounter->iDec() == 0) {
		delete pcPointer;
		delete pcCounter;
	}
}

template <typename T>
T& CMySmartPointer<T>::operator*() {
	return (*pcPointer);
}

template <typename T>
T* CMySmartPointer<T>::operator->() {
	return pcPointer;
}

template <typename T>
void CMySmartPointer<T>::operator=(CMySmartPointer<T>& cPointer) {
	pcCounter->vRemovePointer(this);
	if (pcCounter->iDec() == 0) {
		delete pcPointer;
		delete pcCounter;
	}
	pcPointer = cPointer.pcPointer;
	pcCounter = cPointer.pcCounter;
	pcCounter->iAdd();
	pcCounter->vAddPointer(this);
}
#endif
