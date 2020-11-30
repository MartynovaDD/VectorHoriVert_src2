#include "CStack.h"
#include "Node.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
	/*
	string s;
	for (int j = 0; j < 3; j++) {
		for (int i = 0; i < 1; i++) {
			ifstream ist(";).txt");
			ofstream dopf("prosto.txt");
			while (getline(ist, s)) {
				dopf << s << endl;
			}
			ist.close();
			ofstream ost(";).txt");
			ost << i << endl;
			//t++;
			//head = head->next;
			ifstream dopf1("prosto.txt");
			while (getline(dopf1, s)) {
				ost << s << endl;
			}
		}
		ofstream ostack("datadat.txt");
		ifstream ost(";).txt");
		while (getline(ost, s)) {
			ostack << s << endl;
		}
		ofstream osttt(";).txt");
		ofstream dopffff("prosto.txt");

	}
	*/







	int N;
	string st;
	string s;
	ifstream file("data.txt"); 
	ofstream ostack("datadat.txt"); 
	const char* f = "datadat.txt";
	const char* l = "data.txt";
	if (!file)
	{
		cout << "Error! Cannot open file..." << endl;
		return -1;
	}
	if (!ostack)
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
		st = "77777";
		A.push("44",f);
		A.push("55", f);
		A.push("6666", f);
		A.push(st, f);
		cout << "push:" << endl;
		A.Print();
		A.pop(f);
		A.pop(f);
		A.pop(f);
		A.pop(f);
		//A.pop(f);
		//A.pop(f);
		cout << "pop:" << endl;
		A.Print();
		cout << "vertex length:";
		cout << A.SizeString() << endl;
		cout << "stack size:";
		cout << A.SizeStack() << endl;
	}
	Autotest();
	file.close();
	ostack.close();
	return 0;
}