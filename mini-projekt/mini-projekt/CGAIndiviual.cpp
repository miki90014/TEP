#include "CGAIndividual.h"
CGAIndividual::CGAIndividual(int iNewSize, double dNewProbMut, double dNewProbCross) {
	dProbMut = dNewProbMut;
	dProbCross = dNewProbCross;
	iSize = iNewSize;
	dFitness = 0;
	int iTemp;

	static bool bSeeded = false;
	if (!bSeeded) {
		srand(time(NULL));
		bSeeded = true;
	}


	for (int ii = 0; ii < iSize; ii++) {
		iTemp = rand() % 1000;
		if (iTemp >=0 && iTemp<=31) {
			vGenotype.push_back(false);
		}
		else if (iTemp > 31 && iTemp <=95) {
			vGenotype.push_back(true);
		}
		else {
			vGenotype.push_back(false);
		}

	}
	cMutation();
	
}

CGAIndividual::CGAIndividual() {
	
}

CGAIndividual::CGAIndividual(CGAIndividual* cCopy) {
	dProbCross = cCopy->dProbCross;
	dProbMut = cCopy->dProbMut;
	vGenotype = cCopy->vGenotype;
	iSize = cCopy->iSize;
}

void CGAIndividual::setFitness(double dNewFitness) {
	dFitness = dNewFitness;
}

CGAIndividual::~CGAIndividual() {

};

vector<CGAIndividual> CGAIndividual::cCrossover(CGAIndividual* cParent2) {
	double dTemp;
	int iTemp;
	vector<CGAIndividual> vChildren;
	dTemp = (double)rand() / RAND_MAX;
	if (dTemp <= dProbCross) {
		CGAIndividual cChild1(this);
		CGAIndividual cChild2(this);
		for (int ii = 0; ii < cChild1.vGenotype.size(); ii++) {
			iTemp = rand() % 2;
			if (iTemp == 0) {
				cChild1.vGenotype[ii] = cParent2->vGenotype[ii];
			}
			cChild2.vGenotype[ii] = !cChild1.vGenotype[ii];
		}
		vChildren.push_back(cChild1);
		vChildren.push_back(cChild2);
	}
	else {
		vChildren.push_back(CGAIndividual(this));
		vChildren.push_back(CGAIndividual(cParent2));
	}

	return vChildren;
}

void CGAIndividual::cMutation() {
	double dTemp;
	for (int ii = 0; ii < vGenotype.size(); ii++) {
		dTemp = (double)rand() / RAND_MAX;
		if (dTemp <= dProbMut) {
			vGenotype[ii] = !vGenotype[ii];
		}
	}
}

void CGAIndividual::vPrint() {
	cout << "Gen:" << endl;
	for (int ii = 0; ii < vGenotype.size(); ii++) {
		cout << vGenotype[ii] << " ";
	}
	cout << endl;
	cout << "Fitness: "<<dFitness << endl;
}