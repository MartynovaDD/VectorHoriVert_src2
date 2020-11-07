#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <fstream>
#include "Node.h"
using namespace std;
void Autotest();

class CNode;
class CStack {
private:
	Node* head=NULL;
	int size; // количество строк в стеке 
	int N;  // допустимая длина строк в стеке
	int t; // количество сброшенных в файл строк в прошлый раз
public:
	CStack() = delete;
	CStack(int& x) {
		SetZero();
		N = x;
	}
	~CStack() {
		Clean();
	}
	void SetZero() { head = NULL; size = 0; }

	void CopyOnly(const CStack& b)
	{
		size = b.size;
		N = b.N;
		t = b.t;
		head = b.head;
	}
	
	void Clean() {
		SetZero();
	}
	int IsEmpty() {
		if (head == NULL) {
			return 0;
		}
		else {
			return -1;
		}
	}
	CStack& operator=(const CStack& b)
	{
		if (this != &b)
		{
			Clean(); CopyOnly(b);
		}
		return *this;
	}

	int push(const string& x, ofstream& stack);

	int SizeString() {//длина вершины
		if (size == 0) {
			return 0;
		}
		else {
			return head->data.length();
		}
	}
	int GetSize() {    //текущая длина всех строк в стеке
		int n = 0;
		Node* p = head;
		while (head != NULL) {
			n = n + head->data.length();
			head = head->next;
		}
		head = p;
		return n;
	}

	int pop(ifstream& stack);

	void poptop() {
		size--;
		Node* node = head;
		head = head->next;
		delete node;
	}

	int Get(string& x)
	{
		if (IsEmpty()==0) {
			return -1;
		}
		else {
			x = head->data;
		}
		return 0;
	}
	int SizeStack() {
		return size;
	}
	int fill(ifstream& file, ofstream& file1, int& N);
	void Print() {
		Node* p = head;
		while(head != NULL)
		{
			cout << head->data<<endl;
			head = head->next;
		}
		head = p;
	}
};
