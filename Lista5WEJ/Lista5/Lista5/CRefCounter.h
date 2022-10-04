#ifndef CREFCOUNTER_H
#define CREFCOUNTER_H
#include <iostream>
#include <vector>
using namespace std;
template <typename> class CMySmartPointer;
template <typename T>
class CRefCounter {
private:
	int iCount;
	vector<CMySmartPointer<T>*> vecCMySmartPointers;
public:
	CRefCounter() { iCount = 0; };
	int iAdd();
	int iDec();
	int iGet();
	void vRemovePointer(CMySmartPointer<T>* pcDeleteMySmartPointer);
	void vAddPointer(CMySmartPointer<T>* pcNewMySmartPointer);
	vector<CMySmartPointer<T>*>* vecGetPointers();
};

template <typename T>
int CRefCounter<T>::CRefCounter::iAdd() {
	iCount = ++iCount;
	return iCount;
}

template <typename T>
int CRefCounter<T>::iDec() {
	iCount = --iCount;
	return iCount;
}

template <typename T>
int CRefCounter<T>::iGet() {
	return iCount;
}

template <typename T>
void CRefCounter<T>::vRemovePointer(CMySmartPointer<T>* pcDeleteMySmartPointer) {
	for (int ii = 0; ii < vecCMySmartPointers.size(); ii++) {
		if (vecCMySmartPointers.at(ii) == pcDeleteMySmartPointer) {
			vecCMySmartPointers.erase(vecCMySmartPointers.begin() + ii);
		}
	}
}

template <typename T>
void CRefCounter<T>::vAddPointer(CMySmartPointer<T>* pcNewMySmartPointer) {
	vecCMySmartPointers.push_back(pcNewMySmartPointer);
}

template <typename T>
vector <CMySmartPointer<T>*>* CRefCounter<T>::vecGetPointers() {
	return &vecCMySmartPointers;
}
#endif