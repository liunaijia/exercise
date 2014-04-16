#include <iostream>
#include <cstdlib>

typedef unsigned long Item;

class Stack {
private:
	static const int MAX = 10;
	Item* pitems;
	int size;
	int top;
	int capacity;
public:
	Stack(int n = MAX);
	Stack(const Stack& s);
	~Stack();
	bool isempty() const;
	bool isfull() const;
	bool push(const Item& item);
	bool pop(Item& item);
	Stack& operator=(const Stack& s);
	int getsize() const;
};

Stack::Stack(int n) {
	capacity = n;
	size = 0;
	top = 0;
	pitems = new Item[capacity];
}

Stack::Stack(const Stack& s) {
	capacity = s.capacity;
	size = s.size;
	top = s.top;
	pitems = new Item[capacity];
	for(int i = 0; i < capacity; i++)
		pitems[i] = s.pitems[i];
}

Stack::~Stack() {
	delete [] pitems;
}

bool Stack::isempty() const {
	return size == 0;
}

bool Stack::isfull() const {
	return size == capacity;
}

bool Stack::push(const Item& item) {
	if (isfull())
		return false;

	pitems[(top + size) % capacity] = item;
	size++;
}

bool Stack::pop(Item& item) {
	if (isempty())
		return false;
	item = pitems[top];
	top = (top + 1) % capacity;
	size--;
}

Stack& Stack::operator=(const Stack& s) {
	if (this == &s)
		return *this;

	delete [] pitems;

	capacity = s.capacity;
	size = s.size;
	top = s.top;
	pitems = new Item[capacity];
	for(int i = 0; i < capacity; i++)
		pitems[i] = s.pitems[i];
}

int Stack::getsize() const {
	return size;
}

int main() {
	void assert(bool condition, const char* desc = "");

	Stack s;
	assert(s.isempty(), "init is empty");
	s.push(1);
	s.push(2);
	s.push(3);
	assert(!s.isempty(), "is not empty");
	assert(3 == s.getsize(), "after push size is 3");

	Item temp;
	assert(s.pop(temp), "pop is ok");
	assert(1 == temp, "pop item is 1");
	assert(2 == s.getsize(), "after pop size is 2");
	s.push(4);
	s.push(5);
	s.push(6);
	s.push(7);
	s.push(8);
	s.push(9);
	s.push(10);
	s.push(11);
	assert(10 == s.getsize(), "after push size is 10");
	assert(s.isfull(), "and it's full");
	assert(s.pop(temp), "pop is ok");
	assert(2 == temp, "pop item is 2");
	s.push(12);
	assert(10 == s.getsize(), "after push size is 10");
	assert(!s.push(12), "can't push anymore");
	assert(10 == s.getsize(), "size is still 10");
	for(int i = 3; i <= 12; i++) {
		assert(s.pop(temp), "pop is ok");
		assert(i == temp, "pop item is equal");
	}
	assert(s.isempty(), "queue is empty");

	Stack s1(3);
	s1.push(1);
	Stack s2 = s1;
	s2.push(2);
	assert(s1.getsize() == 1);
	assert(s2.getsize() == 2);
	s1.~Stack();
	s2.push(3);
	assert(s2.getsize() == 3);

	Stack s3;
	s3 = s2;
	assert(s3.getsize() == 3);
	s3.pop(temp);
	assert(s3.getsize() == 2);
	assert(s2.getsize() == 3);
	
	return 0;
}

void assert(bool condition, const char* desc) {
	static int count = 1;
	std::cout << count++ << (condition ? ". [OK] " : ". [ERROR] ") << desc << std::endl;
}