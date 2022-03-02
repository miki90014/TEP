#include <iostream>
#include <vector>
#include "CGAIndividual.h"
#include "CGAOptimizer.h"
#include "CMax3SatProblem.h"
using namespace std;

void vTestCGA() {
	vector<bool> per;
	int iTemp;
	srand(time(NULL));
	for (int i = 0; i < 37; i++) {
		iTemp = rand() % 2;
		iTemp = iTemp + rand();
		iTemp = iTemp % 2;
		if (iTemp == 0) {
			per.push_back(false);
		}
		else {
			per.push_back(true);
		}
	}

	/*for (int i = 0; i < per.size(); i++) {
		cout << per[i] << " ";
	}
	cout << endl;*/

	CGAOptimizer cPop(100, 0.4, 0.17, 8);
	cPop.vRunIteration();
	//cPop.vBestOfTheBest();
}

void vTestMax3SatProblem(string const sFile) {
	CMax3SatProblem cExample;
	cExample.vLoad(sFile);
	cExample.vShowFormulas();
	cout << endl;
	cExample.vCompute();
}

int main() {

	string const s2Var = "m3s_2_0.txt";
	string const s3Var = "m3s_3_0.txt";
	string const s350_0Var = "m3s_350_0.txt";
	string const s350_1Var = "m3s_350_1.txt";
	string const s350_2Var = "m3s_350_2.txt";
	string const s350_3Var = "m3s_350_3.txt";
	string const s50Var = "m3s_50_0.txt";

	//vTestCGA();


	vTestMax3SatProblem(s350_0Var);

	return 0;


}