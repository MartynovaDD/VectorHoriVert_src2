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
	ifstream istack("autotest.txt"); // файл со стеком
	ofstream ostack("autotest.txt");
	A.push(st, ostack);
	A.push(str, ostack);
	A.Get(s);
	A.pop(istack);
	if (A.SizeString() != 4 || A.SizeStack() != 1 || s!="ha") {
		cout << "Autotest falled..." << endl;
	}
	else {
		cout << "Autotest passed..." << endl;
	}
}