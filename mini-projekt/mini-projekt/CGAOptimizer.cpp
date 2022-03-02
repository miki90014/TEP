#include "CGAOptimizer.h"
#include "CGAIndividual.h"
#include <iostream>
#include <tuple>
using namespace std;
CGAOptimizer::CGAOptimizer(int iNewSize, double dNewProbC, double dNewProbM, int iNewSizeDNA) {
	iSizeOfPopulation = iNewSize;
	dProbCross = dNewProbC;
	dProbMut = dNewProbM;
	iSizeDNA = iNewSizeDNA;
	vInitialize();
}

void CGAOptimizer::vInitialize() {
	vcIndividuals.clear();
	for (int ii = 0; ii < iSizeOfPopulation; ii++) {
		vcIndividuals.push_back(CGAIndividual(iSizeDNA, dProbMut, dProbCross));
		//cout << vcIndividuals[ii].vGenotype << endl;;
	}

}

void CGAOptimizer::vPrint() {
	for (int ii = 0; ii < iSizeOfPopulation; ii++) {
		vcIndividuals[ii].vPrint();
		cout << "---------------------------------------------------" << endl;
	}
}

tuple <int, int> CGAOptimizer::ChooseParents(int iCompetition) {
	int iIndexBest = 0;
	double dFitBest = 0;
	int iIndexSecBest = 0;
	double dFitSecBest = 0;
	
	int iTemp;

	static bool seeded = false;
	if (!seeded) {
		srand(time(NULL));
		seeded = true;
	}

	for (int ii = 0; ii < iCompetition; ii++) {
		iTemp = rand() % vcIndividuals.size();
		if (vcIndividuals[iTemp].getdFitness() > dFitBest) {
			iIndexSecBest = iIndexBest;
			dFitSecBest = dFitBest;
			iIndexBest = iTemp;
			dFitBest = vcIndividuals[iTemp].getdFitness();
		}
	}
	return tuple<int, int>{iIndexBest, iIndexSecBest};
}

vector<bool> CGAOptimizer::vBestOfTheBest() {
	int iIndexBest = 0;
	double dFitBest = 0;

	for (int ii = 0; ii < vcIndividuals.size(); ii++) {
		if (vcIndividuals[ii].getdFitness() > dFitBest) {
			iIndexBest = ii;
			dFitBest = vcIndividuals[ii].getdFitness();
		}	
	}

	/*cout << "The Best Invidual Paramets: " << endl;
	vcIndividuals[iIndexBest].vPrint();*/

	return vcIndividuals[iIndexBest].getvGenotype();
}

void CGAOptimizer::vRunIteration() {
	vector<CGAIndividual> vNewPopulation;
	vNewPopulation.clear();
	tuple<int, int> tParents;
	vector < CGAIndividual> vChildren;
	while (vNewPopulation.size() < vcIndividuals.size()) {
		vChildren.clear();
		tParents = ChooseParents(5);
		vChildren = vcIndividuals[get<0>(tParents)].cCrossover(&vcIndividuals[get<1>(tParents)]);
		vChildren[0].cMutation();
		vChildren[1].cMutation();
		vNewPopulation.push_back(vChildren[0]);
		vNewPopulation.push_back(vChildren[1]);
	}
	vcIndividuals = vNewPopulation;
	//vPrint();
}

