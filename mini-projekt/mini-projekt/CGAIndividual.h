#ifndef CGAINDIVIDUAL_H
#define CGAINDIVIDUAL_H
#include <iostream>
#include <vector>
using namespace std;
class CGAIndividual {
private:
	//vector<bool> vGenotype;				//0 i 1  - prawda gdy ma taki sam
	double dProbMut;
	double dProbCross;
	double dFitness;
	int iSize;
public:
	vector<bool> vGenotype;
	CGAIndividual(int iNewSize, double dNewProbMut, double dNewProbCross);	//konstruktor dla pierwszych osobnikow populacji
	CGAIndividual();					
	CGAIndividual(CGAIndividual* cCopy);
	void setFitness(double dNewFitness);
	vector<bool> getvGenotype() { return vGenotype; };
	vector<CGAIndividual> cCrossover(CGAIndividual* cParent2);
	void cMutation();
	~CGAIndividual();
	void vPrint();
	double getdFitness(){ return dFitness; };
};
#endif