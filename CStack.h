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
	Node* head = NULL;
	int size; // êîëè÷åñòâî ñòðîê â ñòåêå 
	int N;  // äîïóñòèìàÿ äëèíà ñòðîê â ñòåêå
	int t; // êîëè÷åñòâî ñáðîøåííûõ â ôàéë ñòðîê â ïðîøëûé ðàç
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

	int push(const string& x, const char* filename);

	int SizeString() {//äëèíà âåðøèíû
		if (size == 0) {
			return 0;
		}
		else {
			return head->data.length();
		}
	}
	int GetSize() {    //òåêóùàÿ äëèíà âñåõ ñòðîê â ñòåêå
		int n = 0;
		Node* p = head;
		while (head != NULL) {
			n = n + head->data.length();
			head = head->next;
		}
		head = p;
		return n;
	}

	int pop(const char* filename);

	void poptop() {
		size--;
		Node* node = head;
		head = head->next;
		delete node;
	}

	int Get(string& x)
	{
		if (IsEmpty() == 0) {
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
	int fill(const char* filename);
	void Print() {
		Node* p = head;
		while (head != NULL)
		{
			cout << head->data << endl;
			head = head->next;
		}
		head = p;
	}
};
