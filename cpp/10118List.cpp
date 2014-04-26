#include <iostream>
#include "10118List.h"

using namespace std;

List::List(int size) {
	items = new Item[size];
	this->size = size;
	index = 0;
}

List::~List() {
	delete [] items;
}

void List::Add(const Item& item) {
	if (IsFull()) {
		cout << "list is full";
		return;
	}
	items[index++] = item;
}

bool List::IsFull() const {
	return index == size;
}

bool List::IsEmpty() const {
	return index == 0;
}

void List::Visit(void (*pf)(Item& item)) {
	for(int i = 0; i < index; i++) {
		(*pf)(items[i]);
	}
}

int List::Length() const {
	return index;
}

const Item List::Get(int i) const {
	return items[i];
}

int main() {
	List list(5);
	cout << list.IsEmpty() << endl;
	list.Add(1);
	list.Add(2);
	list.Add(3);
	list.Add(4);
	list.Add(5);
	cout << list.IsFull() << endl;

	void Inc(Item& item);
	list.Visit(Inc);
	for(int i = 0; i < list.Length(); i++)
		cout << list.Get(i) << " ";
	return 0;
}

void Inc(Item& item) {
	item++;
}