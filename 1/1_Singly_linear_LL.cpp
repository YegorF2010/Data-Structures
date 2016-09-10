// 1.cpp: определяет точку входа для консольного приложения.
//

#include "stdafx.h"
#include <iostream>
#include <list>

using namespace std;

struct Link {
	Link* next;
	int data;
};

class LL_singly_linear {	//односвязный линейный список
	Link* first;
	int cnt;
public:
	LL_singly_linear() :first(0) {}
	~LL_singly_linear() {
		while (first) {
			Link* temp = first->next;
			delete first;
			first = temp;
		}
	}
	void insert(int pos,int d) {
		Link* current = first;
		Link* newlink = new Link;
		newlink->data = d;

		if (pos == 0) {
			newlink->next = first;	
			first = newlink;
			cnt++;
		}
		else if (pos >= cnt) {	//значение cnt еще ДО вставки
			newlink->next = NULL;
			while (current->next)
				current = current->next;
			current->next = newlink;
			cnt++;
		}
		else {
			int k = 0;
			while (k++ != pos - 1) {	//т.к. вся необх инф-ция в предыдущем элементе!
				current = current->next;
			}
			Link* address = current->next;
			current->next = newlink;
			newlink->next = address;
			cnt++;
		}
	}
	void erase(int pos) {
		Link* current_prev = first;
		Link* current = first;
		if (first == NULL) exit(1);

		int k = 0;
		if (pos == 0) {
			first = current->next;
			cnt--;
			delete current;
			return;
		}
		else {
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
			cnt--;
		}
	}

	void show() {
		Link* current = first;
		while (current){
			cout << current->data << ' ';
			current = current->next;
		}
		cout << endl;
	}
	int size() {
		return cnt;
	}
};


int main()
{
	LL_singly_linear l1;
	l1.insert(0, 8);
	l1.insert(0, 55);
	l1.insert(2, 44);
	l1.erase(2);

	//l1.insert(l1.size(), 3);
	//l1.insert(5, 67);
	//l1.insert(2, 14);

	l1.show();


	_getwch();
    return 0;
}

