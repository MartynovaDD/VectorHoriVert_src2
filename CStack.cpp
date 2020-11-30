#include "CStack.h" 
//#include <stdio.h>
#include <string>  
#include <fstream> 
#include <iostream>

using namespace std;


int CStack::push(const string& x, const char* filename) {//ifstream не надо
    if (N < x.length()) {
        return -1;
    }
    if (GetSize() + x.length() > N) {
        if (head->next == NULL) {
            return 0;
        }
        else {
            t = 0;

            ofstream odop("prostotak.txt");
            if (!odop) {
                cout << "Can not open file...";
            }
            ifstream istack(filename);
            string s;
            while (getline(istack, s)) {
                odop << s;
                odop << endl;
            }
            istack.close();
            ofstream ostack(filename);
            string p = head->data;
            head = head->next;
            //ofstream dopf("prosto.txt");
            int a = 0;
            while (head != NULL)
            {
                ifstream ist(";).txt");
                ofstream dopf("prosto.txt");
                while (getline(ist, s)) {
                    dopf << s << endl;
                }
                ist.close();
                ofstream ost(";).txt");
                ost << head->data << endl;
                t++;
                a++;
                head = head->next;
                ifstream dopf1("prosto.txt");
                while (getline(dopf1, s)) {
                    ost << s << endl;
                }
                //dopf.close();
            }
            //int* arr = new int;
            arr[d] = a;
            d++;
            ifstream ist(";).txt");
            while (getline(ist, s)) {
                ostack << s << endl;
                // cout << s << endl;
            }
            ofstream osttt(";).txt");
            ofstream dopfff("prosto.txt");
            ifstream idop("prostotak.txt");
            while (getline(idop, s)) {
                ostack << s << endl;
            }
            Clean();
            Node* node = new Node(p, head);
            head = node;
            size = 1;
            if (GetSize() + x.length() > N) {
                return 0;
            }
            else {
                //Node* node = new Node(p, head);
                //head = node;
                Node* node1 = new Node(x, head);
                head = node1;
                size = 2;
                return 0;
            }
        }
    }
    else {
        Node* node = new Node(x, head);
        //cout << x << endl;
        size++;
        head = node;
        return 0;
    }
}

int CStack::pop(const char* filename) {
    if (IsEmpty() == 0) {
        return -1;
    }
    poptop();
    if (IsEmpty() == 0) {
        ofstream odopfile("prostotak.txt");
        ifstream instack(filename);
        string line;
        int j = 0;
        while (getline(instack, line))
        {
            j++;
        }
        instack.clear();
        instack.seekg(0, ios_base::beg);
        if (j == 0)
        {
            cout << "Stack is empty..." << endl;
            return -1;
        }
        else {
            string s;
            head = NULL;
            for (int i = 0; i < arr[d - 1]; i++) {
                getline(instack, s);
                Node* node = new Node(s, head);
                head = node;
                size++;
            }
            arr[d - 1] = NULL;
            d--;

            while (getline(instack, s))
            {
                odopfile << s << endl;
            }
            instack.close();      //закрываем файл чтобы очистить
            ofstream outstack(filename);
            ifstream idopfile("prostotak.txt");
            while (getline(idopfile, s))
            {
                outstack << s << endl;
            }
            //poptop();
            return 0;
        }
    }
    else {
        //poptop();
        return 0;
    }
}

int CStack::fill(const char* filename) {
    string st;
    int k = 0;
    string line;
    int j = 0;
    ifstream file(filename);
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

            if (GetSize() + st.length() < N || GetSize() + st.length() == N) {
                push(st, filename);
            }
            else {
                k = 1;
            }
        }
        return 0;
    }
}