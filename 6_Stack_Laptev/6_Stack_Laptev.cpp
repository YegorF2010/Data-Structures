// 6_Stack_Laptev.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

typedef double dtype;
struct Node {
	Node* next;
	dtype data;
	Node(const dtype& d, Node *p) :data(d), next(p) {}
	//перебирать эл-ты стека не требуется, поэтому не требуется и итератор
	//ctor инициализации не нужен, т.к. изначально стек пуст
};
class Stack {
	Node* head;
	Stack(const Stack &);
	Stack& operator=(const Stack &);
public:
	Stack() :head(NULL) {}
	~Stack() { while (!empty()) pop();}
	class EmptyStack{};
	void push(const dtype& d) {	//добавление в начало
		head= new Node(d, head);	//безымянный объект
	}
	void pop() throw(EmptyStack){
		if (empty()) throw EmptyStack();
		Node*  oldHead = head->next;
		delete head;
		head = oldHead;
	}
	dtype top()const throw(EmptyStack){
		//if (head) return first->data;
		return !empty() ? head->data : throw EmptyStack();
	}
	bool empty() const {
		return head == 0;
	}
};

int main()
{
	Stack s1;
	for (int i = 0;i < 5;i++) {
		s1.push(i*i);
	}
	while (!s1.empty()) {
		cout << s1.top()<<' ';
		s1.pop();
	}


	_getwch();
    return 0;
}

