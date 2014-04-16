#include <iostream>
using namespace std;

struct Customer
{
	char fullname[35];
	double payment;
};

typedef Customer Item;

class Stack{
private:
	int index;
	int size;
	Item* items;
public:
	Stack(int size);
	~Stack();
	bool Push(const Item& item);
	bool Pop(Item& item);
	bool IsEmpty() const;
	bool IsFull() const;
};

Stack::Stack(int size) {
	this->size = size;
	index = 0;
	items = new Item[size];
}

Stack::~Stack() {
	delete [] items;
}

bool Stack::IsEmpty() const {
	return index == 0;
}

bool Stack::IsFull() const {
	return index == size;
}

bool Stack::Push(const Item& item) {
	if (IsFull()){
		cout << "stack is full";
		return false;
	}
	
	items[index++] = item;
	return true;
}	

bool Stack::Pop(Item& item) {
	if (IsEmpty()) {
		cout << "stack is empty";
		return false;
	}

	item = items[--index];
	return true;
}

int main(){
	Stack s(3);
	cout << s.IsEmpty() << endl;

	Customer c1 = {"lnj", 10};
	Customer c2 = {"bage", 5};
	Customer c3 = {"douniu", 8};
	s.Push(c1);
	s.Push(c2);
	s.Push(c3);
	cout << s.IsFull() << endl;

	double total_payment = 0;
	for(int i = 0; i < 2; i++) {
		Customer c;
		s.Pop(c);
		total_payment += c.payment;
		cout << total_payment << endl;
	}
	

	return 0;
}