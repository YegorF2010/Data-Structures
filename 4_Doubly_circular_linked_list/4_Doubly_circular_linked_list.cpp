// 4_Doubly_circular_linked_list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

struct Link {
	Link* next, *prev;
	int data;
};
class LL_doubly_circular {
	Link* head, *tail;
	int cnt;
public:
	LL_doubly_circular() :head(NULL), tail(NULL), cnt(0) {}
	~LL_doubly_circular() {
		while (cnt--) {
			Link* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void insert(int pos, int d) {
		Link* current = head;
		Link* current_prev = head;
		Link* newlink = new Link;
		newlink->data = d;

		if (head == NULL) head = tail = newlink;
		else if (pos == 0) {
			newlink->next = head;
			newlink->prev = tail;
			head = newlink;
			tail->next = head;
		}
		else if (pos == cnt) {
			tail->next = newlink;
			newlink->prev = tail;	// это поле обязательно раньше "tail = newlink"
			newlink->next = head;
			tail = newlink;
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
		Link* current_prev = head;
		Link* current = head;
		if (head == NULL) exit(1);

		if (pos == 0) {
			if (cnt == 1) {			//если один элеменет
				head = current->next;
				tail->next = head;	//у хвоста обязательно поменять ТОЖЕ !!!
				head->prev = tail;
			}
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
			Link* temp = current->next;
			current_prev->next = temp;
			temp->prev = current_prev;
			delete current;
		}
		cnt--;
	}
	void show() {
		Link* current = head;
		int k = cnt;	//обязательно,т.к. при удалении cnt нужен!
		while (k--) {
			cout << current->data <<' ';
			current = current->next;
		}
	}
};
int main()
{
	LL_doubly_circular l1;
	l1.insert(0, 3);
	l1.insert(0, 4);
	l1.insert(2, 18);
	l1.insert(3, 21);
	l1.insert(2, 100);
	l1.erase(2);

	l1.show();

	_getwch();
    return 0;
}

