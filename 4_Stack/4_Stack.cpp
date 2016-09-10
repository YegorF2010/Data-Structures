// 4_Stack.cpp: ���������� ����� ����� ��� ����������� ����������.
//

#include "stdafx.h"
#include <iostream>
#include <queue>
#include <stack>

using namespace std;

struct Link {
	Link* next;
	int data;
};
class Stack {
	Link* first;
public:
	Stack() :first(NULL) {}
	~Stack() {
		while (first){
			Link* current = first->next;
			delete first;
			first = current;
		}
	}
	void push(int d) {	//���������� � ������
		Link* newlink = new Link;
		newlink->data = d;
		newlink->next = first;
		first = newlink;
	}	
	void pop() {
		if (first) {
			Link*  temp = first->next;
			delete first;
			first = temp;
		}
	}
	int top() {
		if (first) return first->data;
	}
};

int main()
{
	Stack s1;
	s1.push(1);
	cout << s1.top();
	s1.pop();

	_getwch();
    return 0;
}

