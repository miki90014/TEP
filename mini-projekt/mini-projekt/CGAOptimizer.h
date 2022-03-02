#ifndef CGAOPTIMIZER_H
#define CGAOPTIMIZER_H
#include "CGAIndividual.h"
#include <vector>
#include <tuple>
using namespace std;
class CGAOptimizer {
private:
	int iSizeOfPopulation;
	double dProbCross;
	double dProbMut;
	int iSizeDNA;
	void vInitialize();
	tuple <int, int> ChooseParents(int iCompetition);
public:
	vector <CGAIndividual> vcIndividuals;
	CGAOptimizer(int iNewSize, double dNewProbC, double dNewProbM, int iNewSizeDNA);
	void vRunIteration();
	void vPrint();
	vector<bool> vBestOfTheBest();
};
#endif
