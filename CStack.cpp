#include "CStack.h"
#include <iostream>
#include <string> 
#include <fstream>

using namespace std;


int CStack::push(const string& x, ofstream& file) {
    if (GetSize()+x.length() > N) {
        t = 0;
        string p = head->data; 
        head = head->next;
            while (head != NULL)
            {
                file << head->data << endl;
                t++;
                head = head->next;
            }
            Clean();
            Node* node = new Node(p, head);
            head = node;
            Node* node1 = new Node(x, head);
            head = node1;
            size = 2;
            return 0;
    }
    else {
        Node* node = new Node(x, head);
        size++;
        head = node;
        return 0;
    }
}

int CStack:: pop(ifstream& file) {
    if (IsEmpty()==0) {
        string line;
        int j = 0;
        while (getline(file, line))
        {
            j++;
        }
        file.clear();
        file.seekg(0, ios_base::beg);
        if (j == 0)
        {
            cout << "Stack is empty..." << endl;
            return -1;
        }
        else {
            string s;
            head = NULL;
            for (int i = 0; i < t; i++) {
                getline(file, s);
                Node* node = new Node(s, head);
                head = node;
                size++;
            }
            
            poptop();
            return 0;
        } 
    }
    else {
        poptop();
        return 0;
    }
}
int CStack::fill(ifstream&file, ofstream&file1, int& N) {
    string st;
    int k = 0;
    string line;
    int j = 0;
    while (getline(file, line))
    {
        j++;
    }
    file.clear();
    file.seekg(0, ios_base::beg);
    if (j == 0)
    {
        cout << "Stack is empty..." << endl;
        return -1;
    }
    else {
        while (getline(file, st) && k != 1) {

            if (GetSize() + st.length() < N) {
                push(st, file1);
            }
            else {
                k = 1;
            }
        }
        return 0;
    }
}


