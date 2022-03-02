#include <iostream>
#include <vector>
#include <fstream>
#include <regex>
#include "CMax3SatProblem.h"
#include "CGAOptimizer.h"
using namespace std;

bool CMax3SatProblem::vLoad(string sFileName) {
	vClearVector();
	vVariables.clear();
	ifstream file;
	file.open(sFileName.c_str());
	if (!file.good()) {
		cout << "Error with opening the file";
		return false;
	}
	int iOffSet = 0;
	while (true) {
		char cbracket1, cbracket2;
		string i1, i2, i3;
		string sTemp, sPattern;
		file >> cbracket1 >> i1 >> i2 >> i3 >> cbracket2;

		//if(rege)
		if (!file.fail() && cbracket1 == '(' && cbracket2 == ')') {
			vFormulas.push_back(new string[3]);
			vFormulas[iOffSet][0] = i1;
			vFormulas[iOffSet][1] = i2;
			vFormulas[iOffSet][2] = i3;
			iOffSet++;
			vVariables.push_back(sRemoveMinus(i1));
			vVariables.push_back(sRemoveMinus(i2));
			vVariables.push_back(sRemoveMinus(i3));
		}
		else {
			break;
		}
	}
	auto end = vVariables.end();
	for (auto it = vVariables.begin(); it != end; ++it) {
		end = remove(it + 1, end, *it);
	}

	vVariables.erase(end, vVariables.end());

	for (int ii = 0; ii < vVariables.size(); ii++) {
		vDNA.push_back(true);
	}

	return true;
}

void CMax3SatProblem::vClearVector() {
	for (int ii = 0; ii < vFormulas.size(); ii++) {
		delete[] vFormulas[ii];
	}
}

CMax3SatProblem::~CMax3SatProblem() {
	vClearVector();
}

string CMax3SatProblem::sRemoveMinus(string sVar) {
	if (sVar[0] != '-') {
		return sVar;
	}
	else {
		return sVar.substr(1, sVar.length());
	}
}

bool CMax3SatProblem::bCheckFormula(CValue* cFormV[3], string sFormula[3]) {
	bool bVal[3];
	for (int ii = 0; ii < 3; ii++) {
		if (sFormula[ii][0] == '-') {
			bVal[ii] = !cFormV[ii]->bGetValue();
		}
		else {
			bVal[ii] = cFormV[ii]->bGetValue();
		}
	}
	if (bVal[0] == true || bVal[1] == true || bVal[2] == true) {
		return true;
	}
	else {
		return false;
	}
}

void CMax3SatProblem::vCombinationGenerate() {
	vCombinations.clear();
	for (int ii = 0; ii < (1 << vVariables.size()); ii++) {
		string sTemp;
		for (int ic = vVariables.size() - 1; ic >= 0; ic--) {
			int r = ii >> ic;
			sTemp = sTemp + ((r & 1) ? "1" : "0");
		}
		vCombinations.push_back(sTemp);
	}
}

void CMax3SatProblem::vCompute() {
	vector<CValue> vValues;
	//vector<CValue> vBestSol;
	vector<CValue**> vFormulV;
	for (int ii = 0; ii < vVariables.size(); ii++) {
		CValue cTemp(vVariables[ii], false);
		vValues.push_back(cTemp);
		//vBestSol.push_back(cTemp);

	}

	for (int ii = 0; ii < vFormulas.size(); ii++) {
		vFormulV.push_back(new CValue * [3]);
		vFormulV[ii][0] = nullptr;
		vFormulV[ii][1] = nullptr;
		vFormulV[ii][2] = nullptr;
		for (int ik = 0; ik < 3; ik++) {
			for (int ij = 0; ij < vValues.size(); ij++) {
				if (vValues[ij].sGetName() == sRemoveMinus(vFormulas[ii][ik])) {
					vFormulV[ii][ik] = &vValues[ij];
					break;
				}
			}
		}
	}

	

	/*for (int ii = 0; ii < vFormulV.size(); ii++) {
		cout << vFormulV[ii][0] << " " << vFormulV[ii][1] << " " << vFormulV[ii][2] << endl;
	}*/
	

	CGAOptimizer cGACompute(200, 0.4, 0.17, vValues.size());
	cGACompute.vPrint();
	for (int ii = 0; ii < cGACompute.vcIndividuals.size(); ii++) {
		vector<bool> vTemp = cGACompute.vcIndividuals[ii].getvGenotype();
		int iCorrectFormulas = 0;
		for (int ij = 0; ij < vValues.size(); ij++) {
			vValues[ij].bSetValue(vTemp[ij]);
		}
		
		for (int ij = 0; ij < vFormulV.size(); ij++) {
			if (bCheckFormula(vFormulV[ij], vFormulas[ij])) {
				iCorrectFormulas++;
			}
		}
		double dFit = (double) iCorrectFormulas / (double) vFormulV.size();
		cGACompute.vcIndividuals[ii].setFitness(dFit);
	}

	/*for (int ii = 0; ii < cGACompute.vcIndividuals.size(); ii++) {
		cout << cGACompute.vcIndividuals[ii].getdFitness() << endl;
	}*/

	cGACompute.vRunIteration();
	for (int ii = 0; ii < cGACompute.vcIndividuals.size(); ii++) {
		vector<bool> vTemp = cGACompute.vcIndividuals[ii].getvGenotype();
		int iCorrectFormulas = 0;
		for (int ij = 0; ij < vValues.size(); ij++) {
			vValues[ij].bSetValue(vTemp[ij]);
		}

		for (int ij = 0; ij < vFormulV.size(); ij++) {
			if (bCheckFormula(vFormulV[ij], vFormulas[ij])) {
				iCorrectFormulas++;
			}
		}
		double dFit = (double)iCorrectFormulas / (double)vFormulV.size();
		cGACompute.vcIndividuals[ii].setFitness(dFit);
	}

	for (int ii = 0; ii < cGACompute.vcIndividuals.size(); ii++) {
		cout << cGACompute.vcIndividuals[ii].getdFitness() << endl;
	}

	vector<bool> vTemp = cGACompute.vBestOfTheBest();

	for (int ii = 0; ii < vTemp.size(); ii++) {
		vValues[ii].bSetValue(vTemp[ii]);
	}
	
	int iMAXSol = 0;

	for (int ii = 0; ii < vFormulV.size(); ii++) {
		if (bCheckFormula(vFormulV[ii], vFormulas[ii])) {
			iMAXSol++;
		}
	}


	/*
	int iMAXSol = 0;
	
	vCombinationGenerate();
	

	*/
	/*for (int ii = 0; ii < vCombinations.size(); ii++) {

		int iCorrectFormulas = 0;

		for (int ij = 0; ij < vCombinations[ii].size(); ij++) {
			if (vCombinations[ii][ij] == '0') {
				vValues[ij].bSetValue(false);
			}
			else {
				vValues[ij].bSetValue(true);
			}
		}

		for (int ij = 0; ij < vFormulV.size(); ij++) {
			if (bCheckFormula(vFormulV[ij], vFormulas[ij])) {
				iCorrectFormulas++;
			}
		}

		//cout << vCombinations[ii]<<" : " << iCorrectFormulas << endl;
		
		if (iCorrectFormulas > iMAXSol) {
			iMAXSol = iCorrectFormulas;
			vBestSol = vValues;
		}

		if (iMAXSol == vFormulas.size()) {
			break;
		}
	}*/

	cout << "------BEST SOLUTION------" << endl;
	cout << "-------------------------" << endl;
	cout << "Correct Formulas: " << iMAXSol <<" / "<< vFormulas.size()<< endl << endl;
	cout << "Variables: " << endl;
	for (int ii = 0; ii < vValues.size(); ii++) {
		cout << "Name: " << vValues[ii].sGetName() << "; Value: " << vValues[ii].bGetValue() << endl;
	}

	for (int ii = 0; ii < vFormulV.size(); ii++) {
		delete[] vFormulV[ii];
	}
	


}

void CMax3SatProblem::vShowFormulas() {
	for (int ii = 0; ii < vFormulas.size(); ii++) {
		cout << vFormulas[ii][0] << " " << vFormulas[ii][1] << " " << vFormulas[ii][2] << endl;
	}
	cout << endl;
}