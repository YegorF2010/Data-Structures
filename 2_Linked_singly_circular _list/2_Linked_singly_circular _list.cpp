// 2_Linked_singly_circular _list.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>

using namespace std;
struct Link {
	Link* next;
	int data;
};
class LL_singly_circular {
	Link* head,*tail;
	int cnt;
public:
	LL_singly_circular() :head(NULL), tail(NULL), cnt(0) {}
	~LL_singly_circular() {
		while (cnt--) {
			Link* temp = head->next;
			delete head;
			head = temp;
		}
	}
	void insert(int pos, int d) {
		Link* current = head;
		Link* newlink = new Link;
		newlink->data = d;
		
		if (pos == 0) {
			if (head == NULL) head = tail = newlink;		//без этого хвосту нельзя ничего присвоить
			else {
				newlink->next = head;
				head=newlink;
				tail->next = head;
			}
		}
		else if (pos == cnt) {
			tail->next = newlink;
			tail = newlink;
			newlink->next = head;
		}
		else {
			int k = 0;
			while (k++ != pos - 1) {	//т.к. вся необх инф-ция в предыдущем элементе!
				current = current->next;
			}
			Link* address = current->next;
			current->next = newlink;
			newlink->next = address;
		}
		cnt++;
	}
	void erase(int pos) {
		Link* current_prev = head;
		Link* current = head;
		if (head == NULL) exit(1);

		if (pos == 0) {
			head = current->next;	
			tail->next = head;	//у хвоста обязательно поменять ТОЖЕ !!!
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
			Link* address = current->next;
			current_prev->next = address;
			delete current;
		}
		cnt--;
	}
	void show() {
		Link* current = head;
		int k = cnt;	//обязательно,т.к. при удалении cnt нужен!
		while (k--){
			cout << current->data << endl;
			current = current->next;
		}

	}
};
int main()
{
	LL_singly_circular l1;
	l1.insert(0, 2);
	l1.insert(0, 31);
	l1.insert(0, 25);
	l1.erase(0);
	
	l1.show();

	_getwch();
    return 0;
}
//вывод: 1 2 5 3
