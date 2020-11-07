#pragma once
#include <iostream>
#include <string.h>
#include <math.h>
#include <stdio.h>
#include <fstream>
using namespace std;

class Node
{
public:
	Node* next;
	string data;
	Node(string newdata, Node* nextNode) {
		data = newdata;
		next = nextNode;
	}
};



