#include "CStack.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	int N;
	string st;
	string s;
	ifstream file("data.txt"); 
	ofstream istack("datadat.txt"); 
	const char* f = "datadat.txt";
	const char* l = "data.txt";
	if (!file)
	{
		cout << "Error! Cannot open file..." << endl;
		return -1;
	}
	if (!istack)
	{
		cout << "Error! Cannot open file..." << endl;
		return -1;
	}
	else {
		cin >> N;
		CStack A(N);
		A.fill(l);
		cout << "fill:" << endl;
		A.Print();
		A.Get(s);
		cout << "Copy a line at the top of the stack at the specified pointer:";
		cout << s << endl;
		st = "dasha";
		A.push("ca",f);
		A.push("da", f);
		A.push("braa", f);
		A.push(st, f);
		cout << "push:" << endl;
		A.Print();
		A.pop(f);
		A.pop(f);
		A.pop(f);
		A.pop(f);
		cout << "pop:" << endl;
		A.Print();
		cout << "vertex length:";
		cout << A.SizeString() << endl;
		cout << "stack size:";
		cout << A.SizeStack() << endl;
	}
	Autotest();
	file.close();
	istack.close();
	return 0;
}