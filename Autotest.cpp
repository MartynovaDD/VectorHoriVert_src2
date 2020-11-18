#include "CStack.h"
#include <iostream>
#include <fstream>
using namespace std;

void Autotest(void) {
	int N = 9;
	CStack A(N);
	string s;
	string st = "haha";
	string str = "ha";
	ifstream istack("autotest.txt"); // ôàéë ñî ñòåêîì
	ofstream ostack("autotest.txt");
	const char* f = "autotest.txt";
	A.push(st, f);
	A.push(str, f);
	A.Get(s);
	A.pop(f);
	if (A.SizeString() != 4 || A.SizeStack() != 1 || s != "ha") {
		cout << "Autotest falled..." << endl;
	}
	else {
		cout << "Autotest passed..." << endl;
	}
}