#include "CStack.h"
#include "Node.h"
#include <iostream>
#include <fstream>
using namespace std;

int main() {
	int N;
	string st;
	string s;
	ifstream file("data.txt"); // файл с входными данными
	ifstream istack("datadat.txt"); // файл со стеком
	ofstream ostack("datadat.txt");
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
			A.fill(file, ostack, N);
			cout << "fill:" << endl;
			A.Print();
			A.Get(s);
			cout << "Copy a line at the top of the stack at the specified pointer:";
			cout << s <<endl;
			st = "dasha";
			A.push(st, ostack);
			cout << "push:" << endl;
			A.Print();
			A.pop(istack);
			A.pop(istack);
			A.pop(istack);
			cout << "pop:" << endl;
			A.Print();
			cout<< "vertex length:";
			cout << A.SizeString()<<endl;
			cout << "stack size:";
			cout << A.SizeStack()<<endl;
	}
	Autotest();
	file.close();
	istack.close();
	ostack.close();
	return 0;
}