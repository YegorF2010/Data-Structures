// 3_Doubly_linear_linked_list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Link {
	Link* next,*prev;
	int data;
};
class LL_doubly_linear {
	Link* first;
	int cnt;
public:
	LL_doubly_linear() :first(NULL), cnt(0) {}
	~LL_doubly_linear() {
		while (first) {
			Link* temp = first->next;
			delete first;
			first = temp;
		}
	}
	void insert(int pos, int d) {
		Link* current = first;
		Link* current_prev = first;
		Link* newlink = new Link;
		newlink->data = d;

		if (pos == 0) {	
			newlink->next = first;
			newlink->prev = NULL;
			first = newlink;
		}
		else if(pos>=cnt){
			newlink->next = NULL;
			while (current->next)
				current = current->next;
			current->next = newlink;
			newlink->prev = current;
		}
		else {
			int k = 0;
			while (k++ != pos - 1) {
				current_prev = current_prev->next;
			}
			k = 0;
			while (k++ != pos) {
				current = current->next;
			}
			current_prev->next = newlink;
			newlink->prev = current_prev;
			newlink->next = current;
			current->prev = newlink;
		}
		cnt++;
	}

	void erase(int pos) {
		Link* current_prev = first;
		Link* current = first;
		if (first == NULL) exit(1);
		
		if (pos == 0) {
			first = current->next;
			first->prev = NULL;
			delete current;
		}
		else {
			int k = 0;
			while (k++ != pos - 1) {
				current_prev = current_prev->next;
			}
			k = 0;
			while (k++ != pos) {
				current = current->next;
			}
			current_prev->next = current->next;
			if (current->next != NULL) {
				(current->next)->prev = current_prev;	//чтобы не исп доп переменную
			}
			else {
				current_prev->next = NULL;
			}
			delete current;
		}
		cnt--;
	}
	void show() {
		Link* current = first;
		while (current) {
			cout << current->data << ' ';
			current = current->next;
		}
		cout << endl;
	}
};
int main()
{
	LL_doubly_linear l1;
	l1.insert(0, 11);
	l1.insert(0, 1);

	l1.insert(2, 2);
	l1.insert(4, 22);

	l1.insert(1, 33);
	l1.insert(3, 44);

	l1.erase(5);
	l1.show();


	_getwch();
    return 0;
}

