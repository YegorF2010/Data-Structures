// 5_Queue.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Link {
	Link* next;
	int data;
};
class Queue {
	Link *head, *tail;
	int cnt;
public:
	Queue() :head(NULL), tail(NULL) {}
	~Queue() {
		while (cnt--) {
			Link* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void push(int d) {				//добавление в конец
		Link* current = head;
		Link* newlink = new Link;
		newlink->data = d;

		if (head == NULL) head = tail=newlink;	
		else {
			tail->next = newlink;
			tail = newlink;
			newlink->next = head;
		}
		cnt++;
	}
	void pop() {
		if (head) {
			Link*  temp = head->next;
			delete head;
			head = temp;
			cnt--;
		}
	}
	int front() { return head->data; }
	int back() { return tail->data; }
	bool empty() { return !cnt; }
};
int main()
{
	Queue q1;
	q1.push(1);
	q1.push(2);
	q1.push(3);

	cout << q1.back();
	while (!q1.empty()) {
		cout << q1.front();
		q1.pop();
	}


	_getwch();
    return 0;
}

