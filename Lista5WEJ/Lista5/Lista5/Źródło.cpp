#include <iostream>
#include "CMySmartPointer.h"
#include "CTab.h"
using namespace std;

struct A { virtual  ~A() {}; };
struct B : public A { virtual ~B() {}; };
struct C{ virtual  ~C() {}; };

int main() {
	CTable* cTab = new CTable();
	CTable* cOther = new CTable();


	CMySmartPointer<CTable> pcSmart = CMySmartPointer<CTable>(cTab);
	
	cTab = move(cOther);
	cOther = cTab;

	A* a = new A();
	CMySmartPointer<A> aSmart(a);
	CMySmartPointer<B> cast = pcMyDynamicCast<A, B>(aSmart);

	B* b = new B();
	CMySmartPointer<B> bSmart(b);
	CMySmartPointer<A> cast2 = pcMyDynamicCast<B, A>(bSmart);

	C* c = new C();
	CMySmartPointer<C> cSmart(c);
	CMySmartPointer<A> cast3 = pcMyDynamicCast<C, A>(cSmart);



	int* test = new int;
	*test = 10;

	return 0;
}