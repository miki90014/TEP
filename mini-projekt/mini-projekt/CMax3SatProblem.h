#ifndef CMAX3SATPROBLEM_H
#define CMAX3SATPROBLEM_H
#include <iostream>
#include <vector>
using namespace std;
class CMax3SatProblem {
private:
	class CValue {
	private:
		string sName;
		bool bValue;
	public:
		CValue(string sNewName, bool bNewValue) { sName = sNewName; bValue = bNewValue; }
		string sGetName() { return sName; };
		bool bGetValue() { return bValue; };
		void bSetValue(bool bNewValue) { bValue = bNewValue; };
	};
	vector<bool> vDNA;
	vector<string*> vFormulas;
	vector<string> vVariables;
	vector<string> vCombinations;
	void vClearVector();
	string sRemoveMinus(string sVar);
	bool bCheckFormula(CValue* cFormV[3], string sFormula[3]);
	void vCombinationGenerate();
	
public:
	~CMax3SatProblem();
	bool vLoad(string sFileName);
	void vCompute();
	void vShowFormulas();
};
#endif